#ifndef NODE_H
#define NODE_H
#include <string>

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
            void sePrev(Node *prev);
    private:
        Actor *data;
        Node *next;
        Node *prev; 
}

#endif