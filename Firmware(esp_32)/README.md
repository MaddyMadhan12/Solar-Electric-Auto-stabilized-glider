# Firmware

This folder contains firmware used in the Solar-Electric Autonomous Apex Glider.

## ESP32-CAM Auto Video Recorder

The ESP32-CAM records flight video automatically using a Pixhawk trigger signal.

### How it works
- Pixhawk ARMED → recording starts
- Pixhawk DISARMED → recording stops
- Video is saved to ESP32 micro-SD card as MJPEG

This ensures the entire flight from takeoff to landing is recorded automatically.
