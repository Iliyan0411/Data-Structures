#ifndef _GRAPH_CPP_
#define _GRAPH_CPP_

#include "Graph.h"

template <class vertexT, class weightT>
Graph<vertexT, weightT>::Graph(std::vector<std::pair<edgeType, weightT>> v)
{
    for(std::pair<edgeType, weightT> e : v)
    {
        addEdge(e.first.first, e.first.second, e.second);
    }
}

template <class vertexT, class weightT>
void Graph<vertexT, weightT>::addVertex(const vertexT& v)
{
    vertices.insert(v);
    neighs[v];
}

template <class vertexT, class weightT>
void Graph<vertexT, weightT>::addEdge(const vertexT& v1, const vertexT& v2, const weightT& weight)
{
    vertices.insert(v1);
    vertices.insert(v2);
    
    neighs[v1].insert(v2);
    weights[std::make_pair(v1, v2)] = weight;
}

template <class vertexT, class weightT>
bool Graph<vertexT, weightT>::hasVertex(const vertexT& v) const
{
    return vertices.count(v) == 1;
}

template <class vertexT, class weightT>
bool Graph<vertexT, weightT>::hasEdge(const vertexT& v1, const vertexT& v2) const
{
    return vertices.count(v1) == 1 && vertices.count(v2) == 1 && neighs[v1].count(v2) == 1;
}

template <class vertexT, class weightT>
weightT Graph<vertexT, weightT>::getEdge(const vertexT& v1, const vertexT& v2) const
{
    if(!hasEdge(v1, v2))
    {
        throw std::invalid_argument("No such edge");
    }

    return weights[std::make_pair(v1, v2)];
}

template <class vertexT, class weightT>
std::set<vertexT> Graph<vertexT, weightT>::getNeighs(const vertexT& v)
{
    if(!hasVertex(v))
    {
        throw std::invalid_argument("No such vertex");
    }

    return neighs[v];
}

template <class vertexT, class weightT>
void Graph<vertexT, weightT>::print()
{
    for(auto v : vertices)
    {
        for(auto s : neighs[v])
        {
            std::cout << v << "  ->[" << weights[std::make_pair(v,s)] << "]  " << s << std::endl;
        }
    }
}

template <class vertexT, class weightT>
void Graph<vertexT, weightT>::viz(std::ostream& out)
{
    out << "digraph G{\n";

    for(auto v : vertices)
    {
        //out << v << "[label=\"" << v << "\"]\n";

        for(auto s : neighs[v])
        {
            out << v << "->" << s << "[label=\"" << weights[std::make_pair(v,s)] << "\"]\n";
        }
    }

    out << "}";
}

#endif