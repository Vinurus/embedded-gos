#include "TripManager.h"

void TripManager::startTrip(){
    isRunning = true;

}

void TripManager::stopTrip(){}
void TripManager::saveTrip(){}
void TripManager::moving(const Event& e){

    

    switch (e.type) {
        case EV_GPS_SPEED:      speed = e.value/10.0;
        case EV_GPS_ALT:        altitude = e.value;
        case EV_GPS_HEADING:    heading = e.value;
        case EV_GPS_SATS:       sats = e.value;
        case EV_GPS_FIX_STATE:  fix = e.value;
        case EV_GPS_HDOP:       hdop = e.value/10.0;
        case EV_GPS_LAT:        lat = e.value/1000000.0; 
        case EV_GPS_LON:        lon = e.value/1000000.0;
        case EV_GPS_RX_BYTES:   rxBytes = e.value; 
    }
}

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
}
long timeline = 0;
void TripManager::onEvent(const Event& e){
    
    if(isRunning == true){
        if((millis() - timeline) >= 3600){
            timeline = millis();
            moving(e);
        }
    }
}

