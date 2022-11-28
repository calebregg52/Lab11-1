//graph.h
#pragma once
#include <list>

class graph {

public:
    graph(int num_v);
    bool addEdge(int i, int j);
    bool removeEdge(int i, int j);
    bool hasEdge(int i, int j);
    std::list<int> outEdges(int i);
    std::list<int> inEdges(int j);
    void PrintOutAdjacencyMatrix();
    ~graph();

private:
    int num_v;
    bool** adjM;

};
