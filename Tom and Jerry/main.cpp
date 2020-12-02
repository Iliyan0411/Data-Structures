#include "PathTree.h"
#include <fstream>


int main()
{
   PTree t;
   std::queue<char> q, q1, q2;
   q.push('N');
   q.push('N');
   q.push('N');
   q.push('E');
   q.push('E');

   q1.push('N');
   q1.push('N');
   q1.push('E');
   q1.push('P');
   q1.push('N');
   q1.push('E');

   q2.push('N');
   q2.push('N');
   q2.push('E');
   q2.push('P');
   q2.push('E');
   q2.push('N');

   t.add(q);
   t.add(q1);
   t.add(q2);

    std::ofstream out("viz.dot");
    t.viz(out);
    out.close();


    return 0;
}