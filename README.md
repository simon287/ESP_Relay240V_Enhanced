# ESP_Relay240V_Enhanced

An enhanced version of the ESP8266/ESP32 240V Relay control project with improved features, safety measures, and comprehensive documentation.

## 🔥 Features

- Support for both ESP8266 and ESP32 microcontrollers
- Secure WiFi configuration via web interface
- MQTT support for home automation integration
- Built-in safety timeout mechanisms
- Web-based control interface
- OTA (Over-The-Air) updates
- Status LED indicators

## 🛠️ Hardware Requirements

- ESP8266 or ESP32 development board
- 240V Relay module (with optocoupler)
- Power supply (5V)
- Status LED (optional)
- Push button for manual control (optional)

## ⚡ Safety Warning

**IMPORTANT**: This project involves working with HIGH VOLTAGE (240V AC). Only attempt this if you have proper knowledge and experience working with high voltage systems. Always ensure proper isolation and safety measures.

## 📦 Installation

1. Clone this repository
2. Install required libraries (listed in platformio.ini)
3. Configure your WiFi credentials in `config.h`
4. Upload to your ESP device

## 🔧 Configuration

See `config.h` for all configurable options including:
- WiFi settings
- MQTT configuration
- Pin assignments
- Timeout values

## 📚 Documentation

Detailed documentation available in the `/docs` folder.

## 🤝 Contributing

Contributions are welcome! Please read our contributing guidelines before submitting PRs.

## 📜 License

MIT License