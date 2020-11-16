#ifndef Graph_H
#define Graph_H
#include "Vertex.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Graph{
private:
    int V_count=0;
    vector<Vertex> vertices;
    vector<Vertex> DFSV;
    vector<Vertex> BFSVss;
public:
    Graph(vector<string> vertices);
    void addEdged(string u, string v);
    void addEdge(string u, string v);
    int getSize();
    void printGraph();
    void DFS(Vertex v);
    void BFS(Vertex v);
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

        U->addConnections(*V);
        V->addConnections(*U);

        this->vertices.push_back(*U);
        this->vertices.push_back(*V);

    }else if(pv == this->vertices.end()){
        Vertex *U= &this->vertices[pu-this->vertices.begin()];
        Vertex *V=new Vertex(v);

        U->addConnections(*V);
        V->addConnections(*U);

        this->vertices.push_back(*V);
    }
    else if(pu == this->vertices.end()){
        Vertex *V= &this->vertices[pv-this->vertices.begin()];
        Vertex *U=new Vertex(u);

        U->addConnections(*V);
        V->addConnections(*U);

        this->vertices.push_back(*U);
    }else{
        Vertex *U= &this->vertices[pu-this->vertices.begin()];
        Vertex *V= &this->vertices[pv-this->vertices.begin()];

        U->addConnections(*V);
        V->addConnections(*U);
    }
}

//Printing the graph with their conected vertices 
void Graph::printGraph(){
    vector<Vertex>::iterator it;

    for(it = this->vertices.begin(); it != this->vertices.end(); it++){
        auto current = this->vertices[it - this->vertices.begin()];
        cout << current.getName() << " has the following connections [";
        current.getNeighborhood();
        cout << "]" << endl;
    }
}

//Depth First Search algorithm
void Graph::DFS(Vertex v){

    //Creating needed variables and list
    Vertex current;
    vector<Vertex> visited;
    list<Vertex> stack;
    int count=0;

    //search for the vertex we choose to start
    for (int i = 0; i < vertices.size(); i++){
        if(v==vertices.at(i)){
            current=vertices.at(i);
        }
    }

    //adding the first vertex to visited vector
    visited.push_back(current);
    
    //Creating stack of the current vertex neighbors
    stack=visited[0].Stack();

    //Start looking to the stack element neighbors adding the to visited and deleting them
    visited.push_back(stack.front());
    stack.pop_front();
    count++;

    //Stop when visited got all the vertices in the graph 
    while (visited.size()<vertices.size()){

        //Find the next vertex to explore
        for (int i = 0; i < vertices.size(); i++){
            if(visited[count].getName()==vertices.at(i).getName()){
                current=vertices.at(i);
            }
        }

        //Creating stack of the current vertex neighbors
        stack=current.setStack(stack,visited);

        //looking to the stack element neighbors adding the to visited and deleting them
        visited.push_back(stack.front());
        stack.pop_front();
        count++;
        
    }
    
    //Printing the visited vector when we store the visited vertex
    for (int i = 0; i < visited.size(); i++){
        cout<<visited[i].getName()<<"->";
    }
    
}

//Breadth-First Search algorithm
void Graph::BFS(Vertex v){

    //Creating needed variables and list
    Vertex current;
    vector<Vertex> visited;
    list<Vertex> queue;
    int count=0;

    //search for the vertex we choose to start
    for (int i = 0; i < vertices.size(); i++){
        if(v==vertices.at(i)){
            current=vertices.at(i);
        }
    }

    //adding the first vertex to visited vector
    visited.push_back(current);
    
    //Creating queue of the current vertex neighbors
    queue=visited[0].Queue();

    //Start looking to the queue element neighbors adding the to visited and deleting them
    visited.push_back(queue.front());
    queue.pop_front();
    count++;

    //Stop when visited got all the vertices in the graph
    while (visited.size()<vertices.size()){

        //Find the next vertex to visit
        for (int i = 0; i < vertices.size(); i++){
            if(visited[count].getName()==vertices.at(i).getName()){
                current=vertices.at(i);
            }
        }

        //Creating queue of the current vertex neighbors
        queue=current.setQueue(queue,visited);

        //looking to the queue element neighbors adding the to visited and deleting them
        visited.push_back(queue.front());
        queue.pop_front();
        count++;
        
    }
    
    //Printing the visited vector when we store the visited vertex
    for (int i = 0; i < visited.size(); i++){
        cout<<visited[i].getName()<<"->";
    }
    
}
#endif