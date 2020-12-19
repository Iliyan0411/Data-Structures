#include "HashMap.h"
#include <iostream>
#include <cstring>


size_t hfunc(const char* key)
{
    size_t res = 0;

    for(int i = 0; i < strlen(key); ++i)
    {
        res += (size_t)key[i];
    }

    return res;
}


int main()
{
    HashMap<const char*, int> hmap(15, hfunc);

    hmap["Dimitar"] = 52;
    hmap["Iliyan"] = 19;
    hmap["Aneta"] = 47;
    hmap["Georgi"] = 31;
    hmap["Spasi"] = 37;
    hmap["Asen"] = 80;
    hmap["Kaloyan"] = 60;
    hmap["Nikola"] = 5;
    hmap["kolaNi"] = 15;
    hmap["Stoikata"] = 22;
    hmap["Krisko"] = 20;
    hmap["Az"] = 30;

    HashMap<const char*, int> map;
    map = hmap;

    std::cout << map["Dimitar"] << std::endl;
    std::cout << map["Iliyan"] << std::endl;
    std::cout << map["Aneta"] << std::endl << std::endl;

    std::cout << map.hasKey("Dimitar") << std::endl;
    std::cout << map.hasKey("Iliyan") << std::endl;
    std::cout << map.hasKey("Aneta") << std::endl;
    std::cout << map.hasKey("Ivan") << std::endl << std::endl;

    for(const char* c : map)
    {
        std::cout << c << "\t" << map[c] << "\n";
    }

    return 0;
}