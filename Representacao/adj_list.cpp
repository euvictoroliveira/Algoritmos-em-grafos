#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Graph{
    int V; // número de vértices.
    list<int> *l; // linked list de ponteiros

public:
    // Construtor
    Graph(int V){
        this->V = V;
        l = new list<int>[V];   // aloca espaço para lista de ponteiros.
    }
    // Função para adicionar as arestas
    void addEdge(int start, int end, bool is_bidir){
        l[start].push_back(end);

        // Caso o grafo seja bidirecionado
        if(is_bidir)
            l[end].push_back(start); // volta
    }
    // Função para imprimir grafo
    void printAdjList(){
        for(int i = 0; i < V; i++){
            cout << "vertex " << i << "->" << " "; 
            for(int adj:l[i])
                cout << adj << ",";

            cout << endl;
        }
    }
};


int main(){
    Graph g(6);
    g.addEdge(0, 1, true);
    g.addEdge(0, 2, true);
    g.addEdge(0, 3, true);
    g.addEdge(0, 4, true);
    g.addEdge(1, 2, true);
    g.addEdge(2, 3, true);
    g.addEdge(3, 4, true);

    g.printAdjList();

    return 0;
}