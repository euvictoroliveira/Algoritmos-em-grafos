#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph{
    int V;
    std::vector<vector<int>> matrix;

public:

    Graph(int V){
        this->V = V;
        matrix.resize(V, std::vector<int>(V));

    }

    void addEdge(int start, int end, int is_bidir){
        matrix[start][end] = 1;

        if(is_bidir)
            matrix[end][start] = 1;
    }

    void printAdjMatrix(){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++)
                cout << matrix[i][j] << " ";

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

    g.printAdjMatrix();



    return 0;
}