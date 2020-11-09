#include "Solution.h"


int main()
{
    Solution s;
    std::string st;
    std::getline(std::cin,st);
    std::string str = s.decodeString(st);

    for(int i = 0; i< str.size(); ++i)
    {
        std::cout << str[i];
    }


    return 0;
}