#include "Solution.h"
#include <iostream>


int main()
{
    Solution s;
    string str = s.decodeString("3[a2[c]]");

    for(int i = 0; i< str.size(); ++i)
    {
        std::cout << str[i];
    }


    return 0;
}