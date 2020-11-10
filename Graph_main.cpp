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
    return 0;
}