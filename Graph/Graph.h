#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <set>
#include <map>
#include <optional>
#include <exception>
#include <vector>


template <class vertexT, class weightT>
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

    void addVertex(const vertexT&);
    void addEdge(const vertexT&, const vertexT&, const weightT&);
    void print();
    void printDFS(const vertexT);
    void printBFS(const vertexT);
    void viz(std::ostream&);

    bool hasVertex(const vertexT&) const;
    bool hasEdge(const vertexT&, const vertexT&) const;
    bool hasPath(const vertexT&, const vertexT&);

    std::vector<vertexT> getPath(const vertexT&, const vertexT&);

    weightT getEdge(const vertexT&, const vertexT&) const;
    std::set<vertexT> getNeighs(const vertexT&);
};


#endif

#include "Graph.cpp"