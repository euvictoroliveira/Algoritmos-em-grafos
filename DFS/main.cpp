#include "dfs.hpp"
#include <iostream>

int main(){
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    // Saída esperada: 0 1 3 4 2
    g.DFS(0);

    return 0;
}