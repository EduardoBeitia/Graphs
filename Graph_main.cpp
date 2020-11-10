//
//Eduardo Beitia A00829121
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Graph.h"

int main(){

    vector<string> V ={"A","B","C"};

    Graph graph(V);

    graph.addEdged("A","B");
    graph.addEdged("B","C");
    graph.addEdged("C","A");

    graph.printGraph();

    Vertex v("B");

    graph.DFS(v);
    return 0;
}