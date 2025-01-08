/**
 * relay_controller.cpp
 * Core implementation of the relay control functionality with safety features
 * 
 * Key features:
 * - Safe relay state management
 * - Timeout protection
 * - State persistence
 * - Emergency stop capability
 */

#include "relay_controller.h"
#include <EEPROM.h>

// EEPROM address for storing relay state
const int RELAY_STATE_ADDR = 0;
const unsigned long SAFETY_TIMEOUT = 3600000; // 1 hour maximum ON time

RelayController::RelayController() : 
    _relayPin(-1),
    _statusLedPin(-1),
    _isInitialized(false),
    _isOn(false),
    _lastStateChange(0),
    _emergencyStop(false) {}

void RelayController::begin(int relayPin, int statusLedPin) {
    _relayPin = relayPin;
    _statusLedPin = statusLedPin;
    
    // Configure pins
    pinMode(_relayPin, OUTPUT);
    pinMode(_statusLedPin, OUTPUT);
    
    // Initialize EEPROM for state persistence
    EEPROM.begin(512);
    
    // Start in safe state
    digitalWrite(_relayPin, LOW);
    _isOn = false;
    _lastStateChange = millis();
    
    // Read last known state (if power was lost)
    if (EEPROM.read(RELAY_STATE_ADDR) == 1 && !_emergencyStop) {
        turnOn();  // Restore last state if it was ON
    }
    
    _isInitialized = true;
}

bool RelayController::turnOn() {
    if (!_isInitialized || _emergencyStop) {
        return false;
    }
    
    digitalWrite(_relayPin, HIGH);
    digitalWrite(_statusLedPin, HIGH);
    _isOn = true;
    _lastStateChange = millis();
    
    // Persist state
    EEPROM.write(RELAY_STATE_ADDR, 1);
    EEPROM.commit();
    
    return true;
}

bool RelayController::turnOff() {
    if (!_isInitialized) {
        return false;
    }
    
    digitalWrite(_relayPin, LOW);
    digitalWrite(_statusLedPin, LOW);
    _isOn = false;
    
    // Persist state
    EEPROM.write(RELAY_STATE_ADDR, 0);
    EEPROM.commit();
    
    return true;
}

void RelayController::emergencyStop() {
    _emergencyStop = true;
    turnOff();
    // Rapid blink status LED to indicate emergency stop
    for(int i = 0; i < 5; i++) {
        digitalWrite(_statusLedPin, HIGH);
        delay(100);
        digitalWrite(_statusLedPin, LOW);
        delay(100);
    }
}

void RelayController::resetEmergencyStop() {
    _emergencyStop = false;
}

bool RelayController::isOn() const {
    return _isOn;
}

void RelayController::update() {
    if (!_isInitialized) return;
    
    // Safety timeout check
    if (_isOn && (millis() - _lastStateChange > SAFETY_TIMEOUT)) {
        turnOff();
        return;
    }
    
    // Status LED update
    if (_isOn) {
        // Slow blink when relay is on
        digitalWrite(_statusLedPin, (millis() / 1000) % 2);
    } else {
        // Quick pulse when off
        digitalWrite(_statusLedPin, (millis() / 200) % 5 == 0);
    }
}

bool RelayController::isEmergencyStop() const {
    return _emergencyStop;
}
