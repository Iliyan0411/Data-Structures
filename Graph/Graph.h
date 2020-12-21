#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <set>
#include <map>
#include <optional>
#include <exception>
#include <vector>


template <class vertexT=int, class weightT=int>
class Graph
{
private:
    using edgeType = std::pair<vertexT, vertexT>;
    using neighbourType = std::set<vertexT>;

    std::set<vertexT> vertices;
    std::map<vertexT, neighbourType> neighs;
    std::map<edgeType, weightT> weights;

public:
    Graph(std::vector<std::pair<edgeType, weightT>>);
    Graph() = default;

    void addVertex(const vertexT& v);
    void addEdge(const vertexT& v1, const vertexT& v2, const weightT& weight);
    void print();
    void viz(std::ostream&);

    bool hasVertex(const vertexT& v) const;
    bool hasEdge(const vertexT& v1, const vertexT& v2) const;

    weightT getEdge(const vertexT& v1, const vertexT& v2) const;
    std::set<vertexT> getNeighs(const vertexT& v);
};


#endif

#include "Graph.cpp"