
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <errno.h>
#include <gps.h>

void write_CSV(double latitude, double longitude, double speed, int time)
    ("latitude: %f, longitude: %f, speed: %f, timestamp: %lf\n", gps_data.fix.latitude, gps_data.fix.longitude, gps_data.fix.speed, gps_data.fix.time);

int main() {
//struct timeval tv;
struct gps_data_t gps_data;

if ((gps_open(localhost, 2947, &gps_data)) == -1) {
    printf("code: %d, reason: %s\n", errno, gps_errstr(errno));
    return EXIT_FAILURE;
}

while (true) {
        /* read data */
        if ((gps_read & gps_data,NULL,0 ) == -1) {
            printf("error occured reading gps data. code: %d, reason: %s\n", errno, gps_errstr(errno));
        } else {
            /* Display data from the GPS receiver. */
            if ((gps_data.status == STATUS_FIX) && 
                (gps_data.fix.mode == MODE_2D || gps_data.fix.mode == MODE_3D) &&
                !isnan(gps_data.fix.latitude) && 
                !isnan(gps_data.fix.longitude)) {
                    write_CSV(gps_data.fix.latitude, gps_data.fix.longitude, gps_data.fix.speed, gps_data.fix.time)
            } else {
                printf("no GPS data available\n");
            }
        }

    sleep(3);
}

/* When you are done... */
gps_close (&gps_data);

return EXIT_SUCCESS;
}