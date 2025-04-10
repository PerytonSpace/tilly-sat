# MPU6050 Example

This example builds upon the Adafruit `basic_example` example, changing a few features to work with the Raspberry Pi Pico.

A more indepth Adafruit Guide can be found [here](https://learn.adafruit.com/mpu6050-6-dof-accelerometer-and-gyro).

## Wiring

<p align="center">
<img src="https://github.com/PerytonSpace/tilly-sat/blob/main/assets/img/sensors/mpu6050.jpg" width = 20% height = 20%>
</p>
Here is the MPU6050 Inertial Measurement Unit (IMU), which is made up of an accelerometer and a gyroscope.

The MPU6050 has a default I2C address of 0x68, this can be changed to 0x69 by connecting the `AD0` pin to `VCC`.

Connect the VCC pin to the 3V3(OUT) pin of the Pico. Connect GND to any of the GND pins on the Pico. We will be using the default `I2C0` pins. `SDA` goes to `GPIO 4` and `SCL` goes to `GPIO 5`.
<br>

<br>

```
VCC ---> 3V3(OUT)
GND ---> GND
SCL ---> GPIO 5
SDA ---> GPIO 4

AD0 ---> GND (0x68)
or
AD0 ---> 3V3 (0x69)
```

<br>

Try blowing on the sensor and changing the height of the sensor to see the change in values. It might be useful to reduce the delay in the loop to see this.

The `CSB` and `SDO` pins are used for SPI.
