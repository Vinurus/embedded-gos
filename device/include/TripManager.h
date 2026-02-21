#include "Scheduler.h"
#include "MessageBus.h"

class TripManager{
    public:
    double totalDistance = 0;
    unsigned long movingTime = 0;
    unsigned long totalTime = 0;
    unsigned long lastUpdateTime= 0;
    double maxSpeed = 0;
    double avgSpeed = 0;
    float lastLat = 0.0;
    float lastLon = 0.0;
    bool isRunning = false;
    
    void startTrip();
    void stopTrip();
    void saveTrip();
    double distanceMeters(double lat1, double lon1, double lat2, double lon2);
    void moving(const Event& e);
    void onEvent(const Event& e);
};



