#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>

int main() {
    int serial_port = open("/dev/serial0", O_RDWR);

    // Check for errors opening the port
    if (serial_port < 0) {
        perror("Error opening serial port");
        return 1;
    }

    // Configure port settings
    struct termios tty;
    memset(&tty, 0, sizeof tty);

    if (tcgetattr(serial_port, &tty) != 0) {
        perror("Error from tcgetattr");
        close(serial_port);
        return 1;
    }

    // Set Baud Rate to 9600 (adjust as needed)
    cfsetispeed(&tty, B9600);
    cfsetospeed(&tty, B9600);

    // Configure 8N1 (8 bits, no parity, 1 stop bit)
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~CRTSCTS;
    tty.c_cflag |= CREAD | CLOCAL;

    // Set read timeout
    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 10;

    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        perror("Error from tcsetattr");
        close(serial_port);
        return 1;
    }

    // Read loop
    char read_buf[256];
    while (1) {
        memset(&read_buf, '\0', sizeof(read_buf));
        int num_bytes = read(serial_port, &read_buf, sizeof(read_buf) - 1);

        if (num_bytes < 0) {
            perror("Error reading");
            break;
        } else if (num_bytes > 0) {
            // Check if the received data starts with "$GPSLL"
            if ((strncmp(read_buf, "$GPGLL", 6) == 0) || (strncmp(read_buf, "$GPGSV", 6) == 0)) {
                printf("Received: %s\n", read_buf); // Print matching data
            }
        }
    }

    // Clean up and close the serial port
    close(serial_port);
    return 0;
}