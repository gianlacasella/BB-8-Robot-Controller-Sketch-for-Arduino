# BB-8 Robot  Controller Sketch for  Arduino

An Arduino Sketch created to control a BB-8 robot, for a project at Universidad de los Andes. My team used Bluetooth
and the "Arduino Bluetooth RC Car" app on an Android phone to control the robot. The BB-8 was able to move in 8 directions,
and play Star Wars sounds through a buzzer. 

We used two engines connected to the LN-298N controller, the HC-06 Bluethoot module, a switch and 18 AA batteries.

## Getting Started

First of all, clone or download this repository, and assemble the circuit accordingly to the schematic below. You can also
find it on /img folder. **Please, note that ENA and ENB are the ENA and ENB of the LN-298N controller.*

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


                FORMAT
Speed at v  = value -----------> Slider value on the Android App

Speed at 0  = 0 ---------------> Slider at 0
Speed at 10 = 1 ---------------> Slider at 10
Speed at 20 = 2 ---------------> Slider at 20
Speed at 30 = 3 ---------------> Slider at 30
Speed at 40 = 4 ---------------> Slider at 40
Speed at 50 = 5 ---------------> Slider at 50
Speed at 60 = 6 ---------------> Slider at 60
Speed at 70 = 7 ---------------> Slider at 70
Speed at 80 = 8 ---------------> Slider at 80
Speed at 90 = 9 ---------------> Slider at 90
Speed at 100 = 'q' ------------> Slider at 100


                FORMAT
Sound type = char ---------------> Button on the Android App

Sound 2 = 'W' -------------------> Front lights on
Sound 3 = 'w' -------------------> Front lights off
Sound 1 = 'U' -------------------> Back lights on
Imperial March = 'u' ------------> Back lights off
Ooooh = 'V' ---------------------> Horn on
Double Ooohh = 'v' --------------> Horn off
### Prerequisites

What things you need to install the software and how to install them

```
Give examples
```

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
