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
    
    list<Vertex> setStack(list<Vertex> adj, vector<Vertex> visited);
    list<Vertex> Stack();

    list<Vertex> setQueue(list<Vertex> adj, vector<Vertex> visited);
    list<Vertex> Queue();

    bool operator==(Vertex thatguy){return thatguy.label==this->label;};
};

//Constructor

Vertex::Vertex(string name){
    this->label=name;
    count=0;
    
}

//Methods

//function to add vertex to connections vertor
void Vertex::addConnections(Vertex who){
    this->connections.push_back(who);
}

//Function to get the vertex neighbors
void Vertex::getNeighborhood(){
    
    for (int i = 0; i < connections.size(); i++){
        cout<<connections[i].getName()<<" ";
    }
    
}

//Function to add vertex to the stack if they doesnt exist in the stack and in the visited vector
list<Vertex> Vertex::setStack(list<Vertex> adj,vector<Vertex> visited){
    
    for (int j = 0; j < connections.size(); j++){

        //Boolean variables to know if the neighbors already exits
        bool condition1=false;
        bool condition2=false;

        //check the existing stack with the current neighbor
        if(adj.size()!=0){
            for (auto i : adj){
            if(connections[j].getName()==i.getName()){
                condition1=true;
                }
            }
        }else{
            condition1=false;
        }
        
        //check the visited vector with the current neighbor
        for (auto i : visited){
            if(connections[j].getName()==i.getName()){
                condition2=true;
            }
        }

        //If no of the stack and the visited vector got the neighbor vertex then make a push front of the vertex
        if((!condition1)&&(!condition2)){
            
            adj.push_front(connections[j]);
        }
    }

    //return the new stack
    return adj;
}

//function to return a stack with the neighbors of the vertex
list<Vertex> Vertex::Stack(){
    
    list<Vertex> adj;

    for (int i = 0; i < connections.size(); i++){
        adj.push_front(connections[i]);
    }

    return adj;
}

//Function to add vertex to the queue if they doesnt exist in the queue and in the visited vector
list<Vertex> Vertex::setQueue(list<Vertex> adj,vector<Vertex> visited){
    
    for (int j = 0; j < connections.size(); j++){

        //Boolean variables to know if the neighbors already exits
        bool condition1=false;
        bool condition2=false;

        //check the existing queue with the current neighbor
        if(adj.size()!=0){
            for (auto i : adj){
            if(connections[j].getName()==i.getName()){
                condition1=true;
                
                }
            }
        }else{
            condition1=false;
        }
        
        //check the visited vector with the current neighbor
        for (auto i : visited){
            if(connections[j].getName()==i.getName()){
                condition2=true;
            }
        }

        //If no of the queue and the visited vector got the neighbor vertex then make a push back of the vertex
        if((!condition1)&&(!condition2)){
            
            adj.push_back(connections[j]);
        }
    }

    //return the new queue
    return adj;
}

//function to return a queue with the neighbors of the vertex
list<Vertex> Vertex::Queue(){
    
    list<Vertex> adj;

    for (int i = 0; i < connections.size(); i++){
        adj.push_back(connections[i]);
    }

    return adj;
}

#endif