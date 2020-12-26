#include "Graph.h"
#include <fstream>
#include <string>


int main()
{
    Graph<std::string,int> g({std::make_pair(std::make_pair("Sofia","Svilengrad"), 300), 
                            std::make_pair(std::make_pair("Svilengrad","Plovdiv"), 150),
                            std::make_pair(std::make_pair("Sofia","Plovdiv"), 150), 
                            std::make_pair(std::make_pair("Sofia","Varna"), 400)});

    g.addEdge("Burgas", "Svilengrad", 150);
    g.addEdge("Vidin", "Burgas", 500);
    g.addEdge("Liubimec", "Svilengrad", 15);
    g.addEdge("Vidin", "Sofia", 200);

    for(std::string vert : g.getPath("Vidin", "Plovdiv"))
    {
        std::cout << vert << " ";
    }

    // g.printDFS("Vidin");
    // g.printBFS("Vidin");
    // g.print();
    
    // std::cout << g.hasPath("Vidin", "Sofia") << std::endl;
    // std::cout << g.hasPath("Vidin", "Liubimec") << std::endl;

   
    std::ofstream out("graph.dot");
    g.viz(out);
    out.close();

    return 0;
}