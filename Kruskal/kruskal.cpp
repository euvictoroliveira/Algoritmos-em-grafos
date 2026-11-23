#include "kruskal.hpp"
#include <algorithm>


Graph::Graph(int V){
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int start, int endpoint, int weight){
    adj[start].push_back({start, endpoint, weight});
    adj[endpoint].push_back({endpoint, start, weight});
}

int Graph::getVertices() const{
    return V;
}

const std::vector<std::list<Edge>>& Graph::getAdj() const{
    return adj;
}

UnionFind::UnionFind(int n){
    father.resize(n);
    tam.resize(n, 1);

    for(int i = 0; i < n; i++)
        father[i] = i;
}

int UnionFind::find(int x){
    if(father[x] != x){
        father[x] = find(father[x]);
    }

    return father[x];
}

bool UnionFind::unite(int x, int y){
    x = find(x);
    y = find(y);

    if( x == y)
        return false;

    if(tam[x] < tam[y])
        std::swap(x, y);

    father[y] = x;
    tam[x] += tam[y];

    return true;
}

std::vector<Edge> Kruskal::exec(const Graph& graph){
    std::vector<Edge> edges;

    const auto& adj = graph.getAdj();

    for(int u = 0; u < graph.getVertices(); u++){
        for(const Edge& a : adj[u]){
            if(u < a.endpoint){
                edges.push_back(a);
            }
        }
    }

    std::sort(edges.begin(), edges.end(),[](const Edge& a, const Edge& b) {return a.weight < b.weight;} );

    UnionFind uf(graph.getVertices());
    std::vector<Edge> MST;

    for (const Edge& a : edges) {

        if (uf.unite(a.start, a.endpoint)) {
            MST.push_back(a);
        }

        if ((int) MST.size() == (int) graph.getVertices() - 1) {
            break;
        }
    }

    return MST;
}