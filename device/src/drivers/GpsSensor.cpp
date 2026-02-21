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

    // RX bytes every second
    static unsigned long last = 0;
    if (millis() - last > 1000) {
        bus.publish({ EV_GPS_RX_BYTES, (int)rxCount });
        rxCount = 0;
        last = millis();
    }

    // --- GPS data publication ---

    // speed (km/h) (x10)
    if (gps.speed.isValid())
        bus.publish({ EV_GPS_SPEED, (int)(gps.speed.kmph()*10) });

    // alt (m)
    if (gps.altitude.isValid())
        bus.publish({ EV_GPS_ALT, (int)gps.altitude.meters() });

    // Heading (deg)
    if (gps.course.isValid())
        bus.publish({ EV_GPS_HEADING, (int)gps.course.deg() });

    // Satellites
    if (gps.satellites.isValid())
        bus.publish({ EV_GPS_SATS, (int)gps.satellites.value() });

    // HDOP ( ×10)
    if (gps.hdop.isValid())
        bus.publish({ EV_GPS_HDOP, (int)(gps.hdop.hdop() * 10) });

    // Lat/Lon ( ×1e6)
    if (gps.location.isValid()) {
        bus.publish({ EV_GPS_LAT, (int)(gps.location.lat() * 1000000) });
        bus.publish({ EV_GPS_LON, (int)(gps.location.lng() * 1000000) });
    }

    // Fix detection
    bool fix = gps.location.isValid() && gps.location.age() < 2000;

    if (fix != lastFix) {
        bus.publish({ EV_GPS_FIX_STATE, fix ? 1 : 0 });
        lastFix = fix;
    }
}

