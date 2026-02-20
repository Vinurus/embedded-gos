#include "GpsSensor.h"
#include <HardwareSerial.h>

HardwareSerial gpsSerial(1); // UART2

GpsSensor::GpsSensor(MessageBus& b) : bus(b) {}

static bool lastFix = false;


void GpsSensor::init() {
    gpsSerial.begin(9600, SERIAL_8N1, 16, 17); // RX=16, TX=17
}
static unsigned long rxCount = 0;


void GpsSensor::update() {
    while (gpsSerial.available()) {
        gps.encode(gpsSerial.read());
        rxCount++;
    }

    
    static unsigned long last = 0;
    if (millis() - last > 1000) {
        bus.publish({ EV_GPS_RX_BYTES, (int)rxCount });
        rxCount = 0;
        last = millis();
    }

    bus.publish({EV_GPS_SPEED, gps.speed.kmph() });
    bus.publish({EV_GPS_ALT, gps.altitude.meters()});
    bus.publish({EV_GPS_HEADING, gps.course.deg() });
    bus.publish({EV_GPS_LAT, gps.location.lat() });
    bus.publish({EV_GPS_LON, gps.location.lng() });

    bool fix = gps.location.isValid() && gps.location.age() < 2000;

    if (fix != lastFix) {
       // bus.publish({ EV_GPS_FIX_STATE, fix ? 1 : 0 });
        lastFix = fix;
    }

    if (gps.speed.isUpdated()) {
        bus.publish({ EV_GPS_SPEED, (int)gps.speed.kmph() });
    }

}