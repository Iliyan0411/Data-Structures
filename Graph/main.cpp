#include "Graph.h"
#include <fstream>


int main()
{
    Graph<int,int> g({std::make_pair(std::make_pair(1,2), 1), std::make_pair(std::make_pair(2,3), 0),
                        std::make_pair(std::make_pair(2,4), 0), std::make_pair(std::make_pair(3,1), 0)});

    g.addVertex(5);
    g.addVertex(6);
    g.addEdge(2, 5, 0);
    g.addEdge(5, 3, 0);
    g.addEdge(3, 6, 2);
    g.addEdge(6, 3, 3);

    //g.print();
    
    // for(int i = 1; i < 6; i++)
    // {
    //     for(auto &&v : g.getNeighs(i))
    //     {
    //         std::cout << v << " -> ";
    //     }std::cout << std::endl;
    // }
   
    std::ofstream out("graph.dot");
    g.viz(out);
    out.close();

    return 0;
}