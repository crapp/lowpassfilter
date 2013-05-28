//
//  SimpleLowPass.cpp
//  lowPassFilter
//
//  Created by Christian Rapp on 28.05.13.
//
//

#include "SimpleLowPass.h"

SimpleLowPass::SimpleLowPass(std::vector< std::shared_ptr<Node> > nList) : nodeList(nList)
{
    
}

void SimpleLowPass::applySLP()
{
    double altiUp = 0;
    double altiDown = 0;
    double prevAlti = this->nodeList[0]->getAltitude();
    double newAlti = prevAlti;
    for (auto n : this->nodeList)
    {
        double cur = n->getAltitude();
//        All the power of the filter is in the line
//        newAlti += (cur - newAlti) / smoothing.
//        This finds the difference between the new value and the current (smoothed)
//        value, shrinks it based on the strength of the filter, and then adds it
//        to the smoothed value. You can see that if smoothing is set to 1 then the
//        smoothed value always becomes the next value. If the smoothing is set to
//        2 then the smoothed value moves halfway to each new point on each new
//        frame. The larger the smoothing value, the less the smoothed line is
//        perturbed by new changes.
        newAlti += (cur - newAlti) / 20.0;
        std::cout << "newAlti: " << newAlti << std::endl;
        if (prevAlti > newAlti)
        {
            altiDown += prevAlti - newAlti;
        }
        if (newAlti > prevAlti)
        {
            altiUp += newAlti - prevAlti;
        }
        prevAlti = newAlti;
        
    }
    std::cout << "Alti UP total: " << altiUp << std::endl;
    std::cout << "Alti DOWN total: " << altiDown << std::endl;
}