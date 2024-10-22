// Code to measure and read the ADC pins on a raspberry pi pico
// The pico already uses two of the 5 ADC pins to measure the microcontroller temperature and to also mesure V_SYS of the system
// The ADC has a 12-bit resolution 0 - 4095

// Datasheet for TMP36: https://www.analog.com/media/en/technical-documentation/data-sheets/TMP35_36_37.pdf
// Link about the diode V drop: https://forums.raspberrypi.com/viewtopic.php?t=301152

float tempC;
float tempF;
int i;
//GPIO 29 is VSYS
int TMP36_Pin = 26;
int VSYS_Pin = 29;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12); // This sets the resolution of the adc output to 12 bits
  pinMode(TMP36_Pin, INPUT);
  pinMode(VSYS_Pin, INPUT);
}

void loop() {
  i += 1;

  tempC = analogReadTemp(); // Get internal temperature
  // tempF = tempC * 9.0 / 5.0 + 32.0; // Fahrenheit conversion

  float adc_value = analogRead(TMP36_Pin);
  adc_value = adc_value / 4095; // turns the adc reading into a fraction of the max reading
  adc_value = adc_value * 3.3;  // turns that reading into a voltage
  adc_value = adc_value - 0.5;  // removing the 0.5V offset
  
  float TMP_TEMP = adc_value * 100; 
    // adc_value / 4095 gives the relative voltage input to the ADC
    // * by 3.3v gives the actual V read
    // The datasheet, pg 8, states for the TMP36 there is a 0.5V offset, hence it is taken away from the measured V
    // The scaling for the TMP36 is 10 mV/degree celcius so by dividing the measured V by 0.01 gives us the measured temperature
    // ^same as multiplying by 100
    // e.g am ADC reading of 949 correlates to 26.5 C

  float vsys = analogRead(VSYS_Pin);
  vsys = vsys * 3.23*3/4095;
  //vsys typicall measures as 4.82V, which is strange as the icb output is 5V
  // This is due to a voltage drop over a protection diode coming in and the vsys is measured after this diode hence the 0.2V drop
  Serial.println();

  Serial.print("|Counter");Serial.print("|Pico Temp");Serial.print("|TMP36 Temp");Serial.println("|V_SYS|");
  
  Serial.print("  ");Serial.print(i);Serial.print(" , ");
  Serial.print(tempC);Serial.print("  , ");
  //Serial.print(tempF);Serial.print(",");
  Serial.print(TMP_TEMP);Serial.print(" , "); 
  Serial.println(vsys); 

  delay(1000);
}

