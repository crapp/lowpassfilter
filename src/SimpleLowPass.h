//
//  SimpleLowPass.h
//  lowPassFilter
//
//  Created by Christian Rapp on 28.05.13.
//
//

#ifndef __lowPassFilter__SimpleLowPass__
#define __lowPassFilter__SimpleLowPass__

#include <iostream>
#include <vector>
#include <memory>
#include "Node.h"

class SimpleLowPass {
private:
    std::vector< std::shared_ptr<Node> > nodeList;
    
public:
    SimpleLowPass(std::vector< std::shared_ptr<Node> > nList);
    void applySLP();
};

#endif /* defined(__lowPassFilter__SimpleLowPass__) */
