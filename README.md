# BB-8 Robot  Controller Sketch for  Arduino

An Arduino Sketch created to control a BB-8 robot, for a project at Universidad de los Andes. My team used Bluetooth
and an app on a smartphone to control the robot. The BB-8 was able to move in 8 directions, and play Star Wars sounds through a buzzer.

## Getting Started

First of all, clone or download this repository, and assemble the circuit accordingly to the schematic below. You can also
find it on /img folder. **Please, note that ENA and ENB are the ENA and ENB of the LN-298N controller.**

![Schematic](/img/schematic.jpg)

Then, open Arduino IDE and open arduinoBB8.ino file. Load the code to the microcontroller via USB, and turn on the Arduino.
Pair your smartphone to the HC06 Bluethoot module (should appear as HC-06), and open Arduino Bluetooth RC Car app. You should be able now to control the engines acceleration, direction, and make Star Wars sounds with the buzzer.

The commands on the Arduino Bluethoot RC Car app are:

* Go forward: Forward button
* Go forward/right: Forward button + Right button
* Go forward/left: Forward button + Left button
* Go backward: Backward button
* Go backward/right: Backward button + Right button
* Go backward/left: Backward button + Left button
* Go right: Right button
* Go left: Left button
* Speed at 0: Slider at 0
* Speed at 10: Slider at 10
* Speed at 20: Slider at 20
* Speed at 30: Slider at 30
* Speed at 40: Slider at 40
* Speed at 50: Slider at 50
* Speed at 60: Slider at 60
* Speed at 70: Slider at 70
* Speed at 80: Slider at 80
* Speed at 90: Slider at 90
* Speed at 100: Slider at 100
* Sound 1: Back lights on
* Sound 2: Front lights on
* Sound 3: Front lights off
* Imperial March: Back lights off
* Ooooh: Horn on
* Double Ooohh: Horn off

### Prerequisites

1. You need to install Arduino IDE on your computer. You can do it from https://www.arduino.cc/en/main/software .
2. You need to assemble the circuit, accordingly to the schematic. The components used on this project are:
    - Arduino UNO
    - HC-06 Bluethoot Module
    - LN-298N Controller
    - 2 DC Engines
    - Cables
    - Buzzer
    - Switch
    - Batteries: 18V 2700-2900mAh for the controller and 9V 2700-2900mAh for the Arduino
    - Your smartphone
3. Install Arduino RC Car app on your smartphone. On Android, you can download it from https://play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller&hl=es_CL


## What I learned

* Programming an Arduino using Arduino IDE
* Play sounds and melodies through a buzzer
* Manage Bluetooth communication with an Android app on Arduino

## Authors

* **Gianfranco Lacasella** - *Initial work* - [glacasellaUANDES](https://github.com/glacasellaUANDES)

## License

This project is licensed under the GNU GENERAL PUBLIC LICENSE- see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* My teammates, who managed the BB8 case construction
