#ifndef BFS_HPP
#define BFS_HPP

#include <list>

// Definição da classe
class Graph{
    int V; // conjunto de vértices
    std::list<int> *l;

public:
    // Construtor
    Graph(int V);
    // Funcao para adicionar uma nova aresta.
    void addEdge(int start, int end);
    // Funcao BFS
    void bfs(int s);
};

#endif 