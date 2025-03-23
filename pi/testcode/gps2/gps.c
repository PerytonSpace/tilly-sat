#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>

int main() {
	int uart_fd = open("/dev/serial0", O_RDWR | O_NOCTTY | O_NDELAY);
	if (uart_fd = -1) {
		perror("Failed to open UART");
		return 1;
	}
	struct termios options;
	tcgetattr(uart_fd, &options);
	options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
	options.c_iflag = IGNPAR;
	options.c_oflag = 0;
	options.c_lflag = 0;
	tcflush(uart_fd, TCIFLUSH);
	tcsetattr(uart_fd, TCSANOW, &options);

	char buffer[256];
	int bytes_read;

	while(1){
	bytes_read = read(uart_fd, buffer, sizeof(buffer) -1);
	if (bytes_read > 0) {
	 	buffer[bytes_read] = '\0';
		printf("%s", buffer);
	} else if (bytes_read < 0) {
		perror("UART read error");
	}
	usleep(100000);

	} // END of while


	close(uart_fd);
	return 0;
} // END of main
