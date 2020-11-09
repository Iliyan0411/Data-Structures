#include "Solution.h"


int main()
{
    Solution s;
    string st;
    getline(cin,st);
    string str = s.decodeString(st);

    for(int i = 0; i< str.size(); ++i)
    {
        std::cout << str[i];
    }


    return 0;
}