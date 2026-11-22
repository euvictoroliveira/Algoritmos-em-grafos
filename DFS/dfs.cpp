#include "dfs.hpp"
#include <iostream>

using namespace std;

Graph::Graph(int V){
    this->V = V;
    l = new list<int>[V];
}

void Graph::addEdge(int start, int endpoint){
    l[start].push_back(endpoint);   
}

void Graph::DFSutil(int v, vector<bool>& visited){
    visited[v] = true; // marca o vértice como já visitado
    cout << v << " ";

    // percore vizinho do vértice de maneira recursiva
    for(int vizinho: l[v]){
        if(!visited[vizinho])
            DFSutil(vizinho, visited);
    }
}

void Graph::DFS(int s){
    vector<bool> visited(V, false);

    cout << "DFS a partir do vertice " << s << ": ";
    DFSutil(s, visited);
    cout << "\n";
}