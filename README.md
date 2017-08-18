# Arduino-Infrared-Rc-Car
I made this car from a cheap rc car. Can be controlled with an infrared TV remote or with an smart phone via bluetooth.

So this project has to versions: Bluetooht controlled, Infrared controlled.

This repository is for Infrared version.

Click this link for bluetooht version: https://github.com/ahmetakif/Arduino-Bluetooth-Rc-Car

The folder named "IRremote" is the required Arduino library for the project.
And after including this library you also need to delete the default library called "RobotIRremote" because it conflicts with the "IRremote" library

Materials to use:
- Arduino uno clone,
- Hc-06 bluetooth module,
- small size breadboard,
- 9v battery and it's connector,
- 3.7v li-po battery (from drone),
- L293d motor driver,
- Sg-90 9g micro servo motor,
- 3v brushed dc motor,
- Gear box with 3 gears,
- Buzzer,
- 10kohm ve 5kohm resistors,
- 9v battery and connector,

Video: https://www.youtube.com/watch?v=265YbpS6gwE&t=28s

Note: This version uses a Samsung TV Remote to be controlled. You may need to chenge the button hex codes at beginning of the arduino code to use it with your remote.
