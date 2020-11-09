#include <iostream>
#include "Room.h"

int main()
{
   Room r1(3,3,{0,0},{2,2},0,0), r2, r3;

   r2 = r3 = r1;

    std::cout << r2.getWidth() << std::endl;
    std::cout << r2.getTomPos().y << std::endl;

    for(int i = 0; i < r2.getLenght(); ++i)
    {
        for(int j = 0; j < r2.getWidth(); ++j)
        {
            std::cout << r2.getRoom()[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}