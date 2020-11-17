#include "UnsortedBinTree.h"
#include <fstream>

template<class T>
bool even(const T& x)
{
    return x % 2 == 0;
}

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
    
    

    std::ofstream dot("viz.dot");
    t.printDot(dot);
    dot.close();

    return 0;
}