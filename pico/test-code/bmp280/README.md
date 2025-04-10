# BMP280 Example

This example builds upon the Adafruit `bmp280test` example, changing a few features to work with the Raspberry Pi Pico.

A more indepth Adafruit Guide can be found [here](https://learn.adafruit.com/adafruit-bmp280-barometric-pressure-plus-temperature-sensor-breakout/overview).

## Wiring

<p align="center">
<img src="https://github.com/PerytonSpace/tilly-sat/blob/main/assets/img/sensors/bmp280.jpg" width = 20% height = 20%>
</p>
Here is a standard BMP280 breakout board. The actual BMP280 sensor itself is the small silver component in the centre of the board. This uses the small hole to calculate the air pressure so be careful to not touch the sensor and keep it clean.

<br>
Connect the VCC pin to the 3V3(OUT) pin of the Pico. Connect GND to any of the GND pins on the Pico. We will be using the default `I2C0` pins. `SDA` goes to `GPIO 4` and `SCL` goes to `GPIO 5`.
<br>
The BMP280 has a default I2C address of 0x76, this can be changed to 0x77 by connecting the `SD0` pin to `GND`.
<br>

```
VCC ---> 3V3(OUT)
GND ---> GND
SCL ---> GPIO 5
SDA ---> GPIO 4
```

<br>

Try blowing on the sensor and changing the height of the sensor to see the change in values. It might be useful to reduce the delay in the loop to see this.

The `CSB` and `SDO` pins are used for SPI.
