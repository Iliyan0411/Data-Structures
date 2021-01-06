#include "HashMap.h"
#include "map_functions.h"


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
    // HashMap<const char*, int> hmap(hfunc);

    // hmap["Dimitar"] = 52;
    // hmap["Iliyan"] = 19;
    // hmap["Aneta"] = 47;
    // hmap["Georgi"] = 31;
    // hmap["Spasi"] = 37;
    // hmap["Asen"] = 80;
    // hmap["Kaloyan"] = 60;
    // hmap["Nikola"] = 5;
    // hmap["kolaNi"] = 15;
    // hmap["Stoikata"] = 22;
    // hmap["Krisko"] = 20;
    // hmap["Az"] = 30;

    // HashMap<const char*, int> map;
    // map = hmap;

    // std::ofstream out("players.txt");
    // out << map;
    // out.close();

    // std::cout << map.efficiency() << std::endl;

    // std::cout << map["Dimitar"] << std::endl;
    // std::cout << map["Iliyan"] << std::endl;
    // std::cout << map["Aneta"] << std::endl << std::endl;

    // std::cout << map.hasKey("Dimitar") << std::endl;
    // std::cout << map.hasKey("Iliyan") << std::endl;
    // std::cout << map.hasKey("Aneta") << std::endl;
    // std::cout << map.hasKey("Ivan") << std::endl << std::endl;

    // for(const char* c : map)
    // {
    //     std::cout << c << "\t" << map[c] << "\n";
    // }


    std::string t1, t2;

    std::getline(std::cin, t1);
    // std::getline(std::cin, t2);

    // mapf::textSection(t1, t2);
    // mapf::histogram(t1);
    // mapf::commonWord(t1);


    return 0;
}