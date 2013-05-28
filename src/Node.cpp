//
//  Node.cpp
//  lowPassFilter
//
//  Created by Christian Rapp on 26.05.13.
//
//

#include "Node.h"

Node::Node(double dist, double alti, double altiup, double altidown, double lat, double lon, long ts) : distance(dist), altitude(alti), altitudeup(altiup), altitudedown(altidown), latitude(lat), longitude(lon), timestamp(ts)
{
}

double Node::getAltitude()
{
    return this->altitude;
}

double Node::getAltitudeup()
{
    return this->altitudeup;
}

double Node::getAltitudedown()
{
    return this->altitudedown;
}
