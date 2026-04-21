OVERVIEW
--------

The aircraft uses the ArduPlane firmware from ArduPilot running on a Pixhawk flight controller.

This firmware provides:

 -Autopilot stabilization
 
 -Sensor fusion (IMU, GPS, barometer)
 
 -Flight modes (Manual, Stabilize, FBWA, Auto, RTL)

 -Telemetry communication
 
 -Mission planning and waypoint navigation

 -Failsafe & return-to-launch safety features

 The firmware converts pilot commands and mission plans into real-time control of:

 -Aileron servo
 
 -Elevator servo
 
 -Rudder servo
 
 -ESC (motor throttle)

 Why ArduPlane Firmware?
 -----------------------

 ArduPlane is ideal for a solar electric autonomous glider because it supports:

 -Fixed-wing aircraft
 
 -Autonomous missions
 
 -Gliding & motor-assisted flight
 
 -Telemetry and logging
 
 -Failsafe protection

This makes it perfect for research and prototype UAV projects.

Firmware Architecture
---------------------

Sensor Inputs
-------------

The flight controller reads data from:

 -IMU → Orientation & stabilization
 
 -GPS → Position & speed
 
 -Barometer → Altitude
 
 -Compass → Heading

Control Outputs
---------------

The firmware generates PWM signals to control:

Output	Component

SERVO 1	Aileron

SERVO 2	Elevator

SERVO 3	Rudder

SERVO 4	ESC (Motor)

Flight Modes Used in This Project
---------------------------------

Mode	      Purpose

Manual	    Pilot full control

Stabilize	  Assisted manual flight

FBWA	      Angle-limited stabilized flight

Auto	      Fully autonomous mission

RTL	        Return to launch safety mode

Ground Control Software
-----------------------
Mission planning and parameter tuning are done using Mission Planner.

This is used to:

 -Upload firmware

 -Calibrate sensors
 
 -Configure flight modes
 
 -Upload autonomous missions
 
 -Monitor telemetry and logs

Firmware Installation Steps
---------------------------

 -Connect Pixhawk to PC via USB

 -Open Mission Planner
 
 -Go to Install Firmware
 
 -Select ArduPlane
 
 -Wait for flashing to complete

Safety & Failsafe Features
--------------------------

The firmware is configured with:

 -Low battery RTL
 
 -Loss of signal RTL
 
 -GPS failsafe
 
 -Geofence protection

These ensure safe operation during autonomous flights.

Future Firmware Upgrades
------------------------

Planned future improvements:

 -AI object tracking integration
 -Advanced gliding optimization
 -Solar power telemetry monitoring
 -Auto-landing system
