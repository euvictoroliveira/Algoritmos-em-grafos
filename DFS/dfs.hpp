#ifndef DFS_HPP
#define DFS_HPP

#include <list>
#include <vector>


class Graph{
    int V; // número de vértices do grafo
    std::list<int> *l; // lista de ponteiros de inteiros

public:
    // Construtor
    Graph(int V); 
    // função para adicionar novas arestas
    void addEdge(int start, int endpoint);
    // Função auxiliar
    void DFSutil(int v, std::vector<bool>& visited);
    // Função dfs
    void DFS(int s);

};

#endif