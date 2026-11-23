
#include "kruskal.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {

    // Criar grafo com 5 vertices
    Graph g(5);

    // Adicionar arestas (origem, destino, peso)
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 4, 6);
    g.addEdge(3, 4, 7);

    // Executar algoritmo de Kruskal
    vector<Edge> MST = Kruskal::exec(g);

    // Verificar se o grafo e conexo
    if ((int) MST.size() != (int) g.getVertices() - 1) {
        cout << "O grafo nao e conexo!" << endl;
        return 0;
    }

    // Imprimir arestas da AGM
    cout << "Arestas da Arvore Geradora Minima:\n";

    int custo_total = 0;

    for (const Edge& a : MST) {
        cout << a.start << " - "
             << a.endpoint << " : "
             << a.weight << endl;

        custo_total += a.weight;
    }

    // Imprimir custo total
    cout << "\nCusto total da AGM: "
         << custo_total << endl;

    return 0;
}
