#include "bfs.hpp"
#include <iostream>

using namespace std;

Graph::Graph(int V){
    this->V = V;
    l = new list<int>[V];
}

void Graph::addEdge(int start, int end){
    l[start].push_back(end);
}

void Graph::bfs(int s){
    bool *visited = new bool[V];

    for(int i = 0; i < V; i++)
        visited[i] = false; // inicialmente, nenhum vetor foi visitado.
    
    list<int> queue;

    visited[s] = true; // o vértice inicial foi visitado.
    queue.push_back(s);

    list<int>::iterator i;
    while(!queue.empty()){
        s = queue.front();
        queue.pop_front();

        for(i = l[s].begin(); i != l[s].end(); i++){
            if(!visited[*i]){
                visited[*i] = true; // marca elemento como visitado
                queue.push_back(*i);   
            }
        }
    

        cout <<  s << " ";
    }

    cout << endl;
}