#include "iostream"
#include "vector"
#include "fstream"

using std::vector, std::ifstream;

ifstream fin("input.in");

struct Node;

struct Edge {
    int neighborIndex = -1;
    int cost = 0;
};

struct Node {
    int index = -1;
    vector<Edge> neighbors;
    int indexGraf = -1;
};

using Graph = vector<Node>;

vector<Graph> grafuri;

void read_file() {
    int nodes, edges;
    fin >> nodes >> edges;

    Graph graf;

    for (int i = 0; i < nodes; i++) {
        Node node;
        node.index = i;
        node.indexGraf = grafuri.size();
        graf.push_back(node);
    }

    for (int i = 0; i < edges; i++) {
        int nod, vecin, cost;
        fin >> nod >> vecin >> cost;
        Edge edge;
        edge.neighborIndex = vecin - 1;
        edge.cost = cost;
        graf[nod - 1].neighbors.push_back(edge);
    }

    grafuri.push_back(graf);
}

int main() {
    printf("hi!\n");
    read_file();
    printf("ehe\n");
}
