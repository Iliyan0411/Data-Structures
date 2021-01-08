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


    // std::string t1, t2;

    // std::getline(std::cin, t1);
    // std::getline(std::cin, t2);

    // mapf::textSection(t1, t2);
    // mapf::histogram(t1);
    // mapf::commonWord(t1);

    
    
    
    
    
    // std::vector<int> v = {1,20,13,41,35,62,-7,5,9};

    // std::cout << std::boolalpha << mapf::check2Sum(v, 21)
    //         << std::endl << mapf::check2Sum(v, -3)
    //         << std::endl << mapf::check2Sum(v, 14)
    //         << std::endl << mapf::check2Sum(v, -14)
    //         << std::endl << mapf::check2Sum(v, 10)
    //         << std::endl << mapf::check2Sum(v, 100) << std::endl;

    // 3SUM
    // std::cout << std::boolalpha << mapf::check3Sum(v, 34)
    //           << std::endl << mapf::check3Sum(v, -21) // important (expect false)
    //           << std::endl << mapf::check3Sum(v, -9) // important (expect false)
    //           << std::endl << mapf::check3Sum(v, 60)
    //           << std::endl << mapf::check3Sum(v, 10)
    //           << std::endl << mapf::check3Sum(v, 100) << std::endl;

    // WordPattern
    // std::cout << std::boolalpha << mapf::wordPattern("abba", "dog cat cat dog") // expected true
    //             << std::endl << mapf::wordPattern("abba", "dog cat cat fish") // expected false
    //             << std::endl << mapf::wordPattern("aaaa", "dog cat cat dog") // expected false
    //             << std::endl << mapf::wordPattern("abba", "dog dog dog dog") // expected false
    //             << std::endl << mapf::wordPattern("aaaa", "dog dog dog dog") // expected true
    //             << std::endl << mapf::wordPattern("aaa", "dog dog dog dog") // expected false
    //             << std::endl; 


    return 0;
}