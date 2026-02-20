#include "Scheduler.h"

class TripManager{
    public:
    long totalDistance = 0;
    unsigned long movingTime = 0;
    unsigned long totalTime = 0;
    unsigned long lastUpdateTime= 0;
    int maxSpeed = 0;
    int avgSpeed = 0;
    float lastLat = 0.0;
    float lastLon = 0.0;
    bool isRunning = false;
    
    void startTrip();
    void stopTrip();
    void saveTrip();
    void moving();
    void update();
};



