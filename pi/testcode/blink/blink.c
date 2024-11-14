#include <stdio.h>
#include "/home/pi/WiringPi/wiringPi/wiringPi.h"

#define PIN_NUM 17

int main(void){
    wiringPiSetupGpio();

    pinMode(PIN_NUM, OUTPUT);
    //digitalWrite(17, LOW);

    while (1) {
        digitalWrite(PIN_NUM, HIGH);
        delay(1000);
        digitalWrite(PIN_NUM,LOW);
        delay(1000);
    }

return 0;

}

// bool hello() {
//     return true;
// }

// void main() {
//     bool flag = hello();

//     if (flag) {
//         printf("Hello Peryton\n");
//     } else {
//         printf("Bye Peryton\n");
//     }
// }