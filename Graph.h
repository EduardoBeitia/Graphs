#ifndef Graph_H
#define Graph_H
#include "Vertex.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Graph{
private:
    int V=0;
    vector<Vertex> vertices;
    void DFSUtil(Vertex v, bool visited[]);
public:
    Graph(vector<string> vertices);
    void addEdged(string u, string v);
    void addEdge(string u, string v);
    int getSize();
    void printGraph();
    void DFS(Vertex v);
};

//Constructor

Graph::Graph(vector<string> vertices){
    vector<string>::iterator it;

    for (it = vertices.begin(); it != vertices.end(); it++){
        Vertex newboy = Vertex(*it);
        this->vertices.push_back(newboy);
        V++;
    }
    
}

//Methods

//Adding a new edged for the search vertices
void Graph::addEdged(string u, string v){
    vector<Vertex>::iterator pu, pv;

    pu=find(this->vertices.begin(),this->vertices.end(), u);
    pv=find(this->vertices.begin(),this->vertices.end(), v);

    if (pu == this->vertices.end() && pv == this->vertices.end()){
        Vertex *U=new Vertex(u);
        Vertex *V=new Vertex(v);

        U->addConnections(V);
        V->addConnections(U);

        this->vertices.push_back(*U);
        this->vertices.push_back(*V);
    }else if(pv == this->vertices.end()){
        Vertex *U= &this->vertices[pu-this->vertices.begin()];
        Vertex *V=new Vertex(v);

        U->addConnections(V);
        V->addConnections(U);

        this->vertices.push_back(*V);
    }
    else if(pu == this->vertices.end()){
        Vertex *V= &this->vertices[pv-this->vertices.begin()];
        Vertex *U=new Vertex(u);

        U->addConnections(V);
        V->addConnections(U);

        this->vertices.push_back(*U);
    }else{
        Vertex *U= &this->vertices[pu-this->vertices.begin()];
        Vertex *V= &this->vertices[pv-this->vertices.begin()];

        U->addConnections(V);
        V->addConnections(U);

    }

}

void Graph::printGraph(){
    vector<Vertex>::iterator it;

    for(it = this->vertices.begin(); it != this->vertices.end(); it++){
        auto current = this->vertices[it - this->vertices.begin()];
        cout << current.getName() << " has the following connections [";
        current.getNeighborhood();
        cout << "]" << endl;
    }
}

void Graph::DFSUtil(Vertex v, bool visited[]){
    // vector<int>::iterator pv;
    // pv=find(this->vertices.begin(),this->vertices.end(), v);
    vector<Vertex>::iterator it;
    int count=0,num;
    for(it = this->vertices.begin(); it != this->vertices.end(); it++){
        if(auto current = this->vertices[it - this->vertices.begin()]==v){
            
            num=count;
            count++;
        }
        count++;
    }
    visited[num]=true;

    cout<< v.getName() << " ";

    for (int i = 0; i < V; i++){
        if(!visited[i]){
            DFSUtil(vertices[i],visited);
        }
    }
    
    
}

void Graph::DFS(Vertex v){
    bool *visited= new bool[V];

    for (int i = 0; i < V; i++){
        visited[i]=false;
    }

    DFSUtil(v,visited);
    
}
#endif