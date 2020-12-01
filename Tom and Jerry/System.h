#ifndef SYSTEM_H
#define SYSTEM_H
#include "Drone.h"


class System
{
private:
    Drone drone;

public:
    System(std::iostream& in);
};


#endif