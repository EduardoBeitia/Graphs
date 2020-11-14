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
    int V_count=0;
    vector<Vertex> vertices;
    vector<Vertex> DFSV;
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
        V_count++;
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



void Graph::DFS(Vertex v){

    int count=0,check=0;
    DFSV.push_back(v);


    while (DFSV.size()<V_count){

        bool condition = false;

        for (int i = 0; i < DFSV.size(); i++){
            if(vertices.at(count).travel()==DFSV.at(i).getName()){
                condition=true;
            }
        }

        if(!condition){
            DFSV.push_back(vertices.at(count++).travel());
            vertices.at(count).addCount();
        }

        check++;

        if(check==5){
            for (int i = 0; i < vertices.size(); ++i) {
                vertices.at(i).addCount();
            }
            count=0;
            check=0;
        }

    }

    for (int i = 0; i < DFSV.size(); i++){
        cout<<DFSV.at(i).getName()<< "->" ;
    }

    cout<<endl;

}
#endif