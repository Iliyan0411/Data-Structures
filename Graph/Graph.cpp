#ifndef _GRAPH_CPP_
#define _GRAPH_CPP_

#include "Graph.h"
#include <stack>
#include <queue>


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
void Graph<vertexT, weightT>::printDFS(const vertexT start)
{
    std::stack<vertexT> dfsStack;
    std::set<vertexT> visitedVertices;

    vertexT fst = start;
    dfsStack.push(fst);
    visitedVertices.insert(fst);

    while(!dfsStack.empty())
    {
        vertexT top = dfsStack.top();
        dfsStack.pop();

        for(vertexT vert : getNeighs(top))
        {
            if(visitedVertices.count(vert) == 0)
            {
                visitedVertices.insert(vert);
                dfsStack.push(vert);
            }
        }

        std::cout << top << " ";
    }
    std::cout << std::endl;
}

template <class vertexT, class weightT>
void Graph<vertexT, weightT>::printBFS(const vertexT start)
{
    std::queue<vertexT> bfsQueue;
    std::set<vertexT> visitedVertices;

    vertexT fst = start;
    bfsQueue.push(fst);
    visitedVertices.insert(fst);

    while(!bfsQueue.empty())
    {
        vertexT top = bfsQueue.front();
        bfsQueue.pop();

        for(vertexT vert : getNeighs(top))
        {
            if(visitedVertices.count(vert) == 0)
            {
                visitedVertices.insert(vert);
                bfsQueue.push(vert);
            }
        }

        std::cout << top << " ";
    }
    std::cout << std::endl;
}

template <class vertexT, class weightT>
bool Graph<vertexT, weightT>::hasPath(const vertexT& start, const vertexT& end)
{
    if(!hasVertex(start) || !hasVertex(end))
    {
        throw std::invalid_argument ("There is no such vertex!");
    }

    std::stack<vertexT> dfsStack;
    std::set<vertexT> visitedVertices;

    vertexT fst = start;
    dfsStack.push(fst);
    visitedVertices.insert(fst);

    while(!dfsStack.empty())
    {
        vertexT top = dfsStack.top();
        dfsStack.pop();

        for(vertexT vert : getNeighs(top))
        {
            if(visitedVertices.count(vert) == 0)
            {
                visitedVertices.insert(vert);
                dfsStack.push(vert);
            }
        }

        if(visitedVertices.count(end) == 1)
        {
            return true;
        }
    }

    return false;
}

template <class vertexT, class weightT>
std::vector<vertexT> Graph<vertexT, weightT>::getPath(const vertexT& start, const vertexT& end)
{
    if(!hasVertex(start) || !hasVertex(end))
    {
        throw std::invalid_argument ("There is no such vertex!");
    }

    std::vector<vertexT> path;
    std::stack<edgeType> dfsStack;
    std::set<vertexT> visitedVertices;

    vertexT fst = start;
    dfsStack.push({fst,fst});
    visitedVertices.insert(fst);

    while(!dfsStack.empty())
    {
        auto [parentVert, currentVert] = dfsStack.top();
        dfsStack.pop();

        if(currentVert == end)
        {
            path.push_back(currentVert);
            return path;
        }

        while(!path.empty() && path[path.size() - 1] != parentVert)
        {
            path.pop_back();
        }

        path.push_back(currentVert);
        for(vertexT vert : getNeighs(currentVert))
        {
            if(visitedVertices.count(vert) == 0)
            {
                visitedVertices.insert(vert);
                dfsStack.push({currentVert, vert});
            }
        }
    }

    return path;
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
