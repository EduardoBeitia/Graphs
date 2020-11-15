//
//Eduardo Beitia A00829121
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Graph.h"

int main(){

    vector<string> V ={"A","B","C","E"};

    Graph graph(V);

    graph.addEdged("A","B");
    graph.addEdged("B","C");
    graph.addEdged("C","A");
    graph.addEdged("A","E");

    graph.printGraph();

    Vertex v("A");

    cout<<"DFS"<<endl;
    graph.DFS(v);

    cout<<"BFS"<<endl;
    graph.BFS(v);
    
    return 0;
}