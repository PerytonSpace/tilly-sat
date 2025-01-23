//#include <wiringPi.h>
#include "/home/tilly/Code/WiringPi/wiringPi/wiringPi.h"
#include <wiringSerial.h>
#include <stdio.h>
#include <errno.h>

int main() {
	int uart_fd;
	char buffer[256];
	int bytes_read;
	
	if (wiringPiSetup() == -1) {
		//fprintf(stderr, "WiringPi setup failed: %s\n", strerror(errno));
		perror("WiringPi set up failed \n");
		return 1;
	}

	if ( (uart_fd = serialOpen("/dev/serial0", 9600)) < 0 ) {
		//fprintf(stderr, "Failed to open UART: %s\n", strerror(errno));
		perror("Failed to open UART");
		return 1;
	}

	printf("UART opened successfully.\n");
	while(1) {
	if (serialDataAvail(uart_fd)) {
		bytes_read = 0;
		while (serialDataAvail(uart_fd)) {
		buffer[bytes_read++] = serialGetchar(uart_fd);
			if (bytes_read >= sizeof(buffer) -1){
				break;
			} 
		}
		buffer[bytes_read] = '\0';
		printf("%s", buffer);
	
	}//If

	delay(100);
	} // END of while

serialClose(uart_fd);
return 0;


}//END of Main
