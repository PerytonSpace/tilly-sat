# Raspberry Pi Pico
TillySat utilizes the Raspberry Pi Pico microcontroller which can be coded in the Arduino IDE or can be coded using the Raspberry Pi C/C++ SDK, a way to code the Pico in C or C++ and have a more hands on approach to programming the Pico than using Arduino.

<p align="center">
<img src="https://github.com/PerytonSpace/tilly-sat/blob/main/assets/img/pico/raspberry-pi-pico.jpg" width = 20% height = 20%>
</p>

Also remember to `only use 3.3V!`, attaching 5V to any of the input GPIOs can damage the Pico. 
<br>
Normal Arduinos use 5V.

## Using the Pico in Arduino

Arduino lets us code and talk to official Arduino Microcontrollers, but also allows the use of third party boards with the help of a board manager. 

A board manager just allows Arduino to program different types of architectures and boards, using the Arduino language.

Here is a guide to install third-party Board Managers to [Arduino](https://support.arduino.cc/hc/en-us/articles/360016466340-Add-third-party-platforms-to-the-Boards-Manager-in-Arduino-IDE?_gl=1%2A1eoz6vm%2A_up%2AMQ..%2A_ga%2AMTkxNDIwODk2Ny4xNzQ0MDIwMzQw%2A_ga_NEXN8H46L5%2AMTc0NDAyMDMzOS4xLjAuMTc0NDAyMDMzOS4wLjAuMTI1MjcwODg3OQ..).

For the Board Manager URL, we will be using the [earlephilhower](https://github.com/earlephilhower/arduino-pico) Board Manager, place this link into the Board URLs section:

```
https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
```
This link allows you to then download the board manager from the Board Manager tab in the Arduino IDE and search for Pi Pico.
### Pico unique
#### Using I2C

By default the Pi Pico uses `GPIO 4 ` for  `SDA0` and `GPIO 5` for `SCL0`
To change these from default make sure to declare them before `Serial.begin();` and to include `<Wire.h>`

```
#include <Wire.h>


void setup(){
    Wire.setSDA(X);
    Wire.setSCL(X);
    Wire.begin();
    Serial.begin(115200);
    ...
}

```
Where `x` is the value of the GPIO pin number. If using `I2C1` then use `Wire1`. `Wire` and `Wire1` can be used in the same code, meaning the different I2C interfaces.

#### Using SPI
BY default the pico uses `SPI0` using GPIO pins 18-20


# Code Examples
Below are examples to use with the Pi Pico which are relevant to TillySat, such as interfacing with specific sensors or using certain communication protocols. 

Examples will need a library to interface with the sensor, unless you want to write your own, which in themselves provide examples but they may not be tailored specifically to the Pi Pico. 

Most of these libraries can be found in the library tab in the IDE and can be installed easily, otherwise they can manually be added to [Arduino](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries/) by importing a Zip File.

## BMP280

The BMP280 is a pressure sensor and communicates with the Pico over I2C or SPI. For this example we will be talking to the BMP280 over I2C.

Library 
Adafruit BMP280 Library
```
https://github.com/adafruit/Adafruit_BMP280_Library
```
Find the example [here](https://github.com/PerytonSpace/tilly-sat/tree/main/pico/test-code/bmp280).

## MPU6050

The MPU6050 is an Interial-Measurement Unit (IMU), which can measure the acceleration and rotational velocity of the sensor. Some variants also include a magnetometer. The MPU6050 communicated over I2C or SPI, for this example we will use I2C.

Library 
Adafruit MPU6050 Library
```
https://github.com/adafruit/Adafruit_MPU6050
```
Find the example [here](https://github.com/PerytonSpace/tilly-sat/tree/main/pico/test-code/mpu6050).

## PCF8523 RTC
keeps track of the time, from when it gets set by the user, 

Library 
Adafruit RTCLib Library
```
https://github.com/adafruit/RTClib
```
Find the example [here](https://github.com/PerytonSpace/tilly-sat/tree/main/pico/test-code/pcf8523).

## Internal ADC

The Pi Pico has an internal Analog-to-Digital Converter, which converts a measured voltage to a numerical value which is a ratio of the measured value to the reference voltage - typically 3.3V.

two examples, internal V temp, Vsys and then an external temperature sensor.


Find the example [here](https://github.com/PerytonSpace/tilly-sat/tree/main/pico/test-code/mpu6050).

<br>
<br>
<br>

<p align="center">
<img src="https://github.com/PerytonSpace/tilly-sat/blob/main/assets/img/pico/pico-pinout.jpg" width = 50% height = 50%>
</p>

<br>
<br>


<p align="center">
<img src="https://github.com/PerytonSpace/tilly-sat/blob/main/assets/img/PerytonSpaceLogo.png" width = 40% height = 40%>
</p>
