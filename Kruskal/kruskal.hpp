#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP

#include <iostream>
#include <list>
#include <vector>

struct Edge{
    int start;
    int endpoint;
    int weight;
};

class Graph{
    int V;
    std::vector<std::list<Edge>> adj;

public:
    Graph(int V);

    void addEdge(int start, int endpoint, int weight);

    int getVertices() const;

    const std::vector<std::list<Edge>>& getAdj() const;

};

class UnionFind{
    std::vector<int> father;
    std::vector<int> tam;

public:
    UnionFind(int n);

    int find(int x);

    bool unite(int x, int y);
};

class Kruskal{
public: 
    static std::vector<Edge> exec(const Graph& graph);
};



#endif 