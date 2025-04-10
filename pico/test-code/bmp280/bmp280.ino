 // Including the required libraries

 #include <Wire.h>
 #include <Adafruit_BMP280.h>
 
 // Declaring an object - this uses the BMP280 library
 Adafruit_BMP280 bmp; // I2C

 void setup() {

  //Wire.setSDA(8); // To change the SDA pin for I2C0
  //Wire.setSCL(9); // To change the SCL pin for I2C0
  Wire.begin(); // Initaliasing I2C0
   Serial.begin(115200);
   // while ( !Serial ) delay(100);  // This will not start the program until the serial port is opened
   delay(3000);                     // This waits 3 seconds allowing the Pico to connect to the USB output

   Serial.println(F("|TillySat BMP280 test"));

     if(!bmp.begin(0x76)){
    Serial.println("BMP 280 Error");
    //while (1) delay(10);
  }
  else{
    Serial.println("BMP 280 Check");

  }

   /* Default settings from datasheet. */
   bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                   Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                   Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                   Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                   Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
    // These values can be changed but recommend to use the defaults for most use cases
 } // END of Setup()
 
 void loop() {

     Serial.print(F("Temperature = "));
     Serial.print(bmp.readTemperature()); // this command returns the temperature
     Serial.println(" *C");

     // Can also save the value as a variable
     // float Temperature = bmp.readTemperature();
     // Serial.print(Temperature);
 
     Serial.print(F("Pressure = "));
     Serial.print(bmp.readPressure());
     Serial.println(" Pa");
 
     Serial.print(F("Approx altitude = "));
     Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
     Serial.println(" m");
     // The 1013.25 is the average sea level pressure
     // to get a more accurate altitude from this should be set to the local ground pressure
 
     Serial.println();
     delay(2000);

 } // END of Loop()
 