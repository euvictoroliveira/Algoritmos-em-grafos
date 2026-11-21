#include <iostream>
#include "bfs.hpp"

int main(){
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);


    // teste bfs
    g.bfs(0);




    return 0;
}