#ifndef Vertex_H
#define Vertex_H

#include <iostream>
#include <string>
#include <vector>

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
    vector<Vertex*>::iterator it;
    for (int i = 0; i < connections.size(); i++){
        cout<<connections[i].getName()<<" ";
    }
    

}

Vertex Vertex::travel(){
    return connections[count];
}

#endif