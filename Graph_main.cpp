//
//Eduardo Beitia A00829121
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Graph.h"

int main(){

    //test cases
    //Creating vector for the constructor
    vector<string> V ={"A","B","C","E"};

    //Creating graph object
    Graph graph(V);

    //Adding the conection to the vertices passed on the graph object
    graph.addEdged("A","B");
    graph.addEdged("B","C");
    graph.addEdged("C","A");
    graph.addEdged("A","E");

    //Function to print graphs
    graph.printGraph();

    //Creating the vertex from where you want to start the travel
    Vertex v("A");

    //Printing DFS travel
    cout<<"DFS"<<endl;
    graph.DFS(v);
    cout<<endl;

    //Printing BFS travel
    cout<<"BFS"<<endl;
    graph.BFS(v);

    return 0;
}