#include "UnsortedBinTree.h"
#include <fstream>


int main()
{
    UnsBinTree<int> t;
    t.add(1,"");
    t.add(2,"L");
    t.add(5,"R");
    t.add(4,"LR");
    t.add(3,"LL");
    t.add(7,"RR");
    t.add(6,"RRL");
    
    std::cout << t.minElement();

    std::ofstream dot("viz.dot");
    t.printDot(dot);
    dot.close();

    return 0;
}