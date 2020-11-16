#ifndef Vertex_H
#define Vertex_H

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Vertex{
private:
    string label;
    int count=0;
    
public:
    Vertex(string name="");
    vector<Vertex> connections;
    string getName(){return label;};
    void addConnections(Vertex who);
    void getNeighborhood();
    vector<Vertex> neighbord(){return connections;};
    Vertex travel();
    
    list<Vertex> setStack(list<Vertex> adj, vector<Vertex> visited);
    list<Vertex> Stack();

    void addCount(){count++;};
    bool operator==(Vertex thatguy){return thatguy.label==this->label;};
};

//Constructor

Vertex::Vertex(string name){
    this->label=name;
    count=0;
    
}

//Methods

void Vertex::addConnections(Vertex who){
    this->connections.push_back(who);
}

void Vertex::getNeighborhood(){
    
    for (int i = 0; i < connections.size(); i++){
        cout<<connections[i].getName()<<" ";
    }
    

}

Vertex Vertex::travel(){
    return connections[count];
}


list<Vertex> Vertex::setStack(list<Vertex> adj,vector<Vertex> visited){
    
    for (int j = 0; j < connections.size(); j++){
        bool condition1=false;
        bool condition2=false;
        if(adj.size()!=0){
            for (auto i : adj){
            if(connections[j].getName()==i.getName()){
                condition1=true;
                
                }
            }
        }else{
            condition1=false;
        }
        
        for (auto i : visited){
            if(connections[j].getName()==i.getName()){
                condition2=true;
            }
        }
        if((!condition1)&&(!condition2)){
            
            adj.push_front(connections[j]);
        }
    }

    return adj;
}

list<Vertex> Vertex::Stack(){
    
    list<Vertex> adj;

    for (int i = 0; i < connections.size(); i++){
        adj.push_front(connections[i]);
    }

    return adj;
}

#endif