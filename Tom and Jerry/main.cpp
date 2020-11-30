#include "Drone.h"

int main()
{
    Room r(3,3,{0,0},{2,2});
    Drone d(r);

    d.getRoom().getDronePos().print();

    d.W();
    d.W();
    d.N();
    

    d.getRoom().getDronePos().print();


    return 0;
}