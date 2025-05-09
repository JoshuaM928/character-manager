#ifndef NODE_H
#define NODE_H
#include "Actor.h"

class Node {
    public:
        // Default constructor, copy constructor, & deconstructor
            Node();
            Node(Actor *other);
            ~Node();
        // Getters
            Actor* getData();
            Node* getNext();
            Node* getPrev();
        // Setters
            void setData(Actor *data);
            void setNext(Node *next);
            void setPrev(Node *prev);
    private:
        // Members
            Actor *data;
            Node *next;
            Node *prev; 
};

bool operator==(Node *rhs); // rhs is "right hand side" abbreviated
#endif