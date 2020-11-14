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
    vector<Vertex*> connections;
    string getName(){return label;};
    void addConnections(Vertex* who);
    void getNeighborhood();
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

void Vertex::addConnections(Vertex* who){
    this->connections.push_back(who);
}

void Vertex::getNeighborhood(){
    vector<Vertex*>::iterator it;
    for (it = this->connections.begin(); it != this->connections.end(); it++){
        cout<< (*it)->getName()<<" ";
    }

}

Vertex Vertex::travel(){
    return *connections[count];
}

#endif