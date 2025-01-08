# Over-The-Air (OTA) Update Guide

## What is OTA?
OTA (Over-The-Air) updates allow you to update your ESP Relay device's firmware without physically connecting it to a computer. This is especially useful when the device is installed in a hard-to-reach location or when you need to update multiple devices.

## Safety First! ⚠️
Before performing an OTA update:
1. Ensure the relay is in a safe state (OFF position)
2. Make sure you have stable Wi-Fi connectivity
3. Keep power stable during the update
4. Have a backup plan in case the update fails

## How to Update Your Device

### Method 1: Using the Web Interface (Recommended)
1. Connect to the same Wi-Fi network as your device
2. Open your web browser
3. Go to: `http://esp-relay.local` or use the device's IP address
4. Navigate to the "Update" section
5. Click "Choose File" and select the new firmware file
6. Click "Update" and wait for the process to complete

### Method 2: Using Arduino IDE
1. Open Arduino IDE
2. Go to `Tools > Port`
3. Select `Network Ports > ESP_Relay at 192.168.x.x`
4. Upload your sketch as normal using the upload button

### Status Indicators
The device's LED will show the update progress:
- Fast blinking: Update in progress
- Solid ON: Update completed successfully
- Rapid flashing: Error during update

## Troubleshooting

### If Update Fails
1. Device will automatically roll back to previous version
2. Check your Wi-Fi connection
3. Verify you're using the correct firmware file
4. Try again or use manual update method

### Common Issues
* "Device not found":
  - Verify you're on the same network
  - Try using the IP address instead of hostname

* "Update failed":
  - Check your Wi-Fi signal strength
  - Ensure stable power supply
  - Verify firmware file integrity

* "Version error":
  - Confirm you're using a compatible firmware version
  - Cannot downgrade to older versions

## Best Practices
1. Always backup your configuration before updating
2. Update during low-usage periods
3. Test new firmware on one device before mass deployment
4. Keep a record of firmware versions and changes

## Emergency Recovery
If your device becomes unresponsive after an update:
1. Power cycle the device
2. Device will attempt to boot last working firmware
3. If still not working, use manual USB update

## Version Control
Current firmware version can be checked:
* Through web interface: Settings > About
* LED pattern at startup
* Serial monitor output

## Support
If you need assistance:
1. Check the troubleshooting section above
2. Consult project documentation
3. Open an issue on GitHub
4. Contact support team

Remember: OTA updates are a powerful feature but should be used carefully. Always ensure you have a way to recover the device if an update fails.