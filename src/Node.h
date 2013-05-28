//
//  Node.h
//  lowPassFilter
//
//  Created by Christian Rapp on 26.05.13.
//
//

#ifndef lowPassFilter_Node_h
#define lowPassFilter_Node_h

class Node {
private:
    double distance;
    double altitude;
    double altitudeup;
    double altitudedown;
    double latitude;
    double longitude;
    long timestamp;
    
public:
    Node(double dist, double alti, double altiup, double altidown, double lat, double lon, long ts);
    double getAltitude();
    double getAltitudeup();
    double getAltitudedown();
};



#endif
