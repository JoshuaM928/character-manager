# include "../include/models/Node.h"

// Default constructor, copy constructor, & deconstructor
    Node::Node() 
        : data(nullptr), next(nullptr), prev(nullptr) {
            // intentionally left blank
    }

    Node::Node(Actor *other)
        : data(other), next(nullptr), prev(nullptr) {
            // intentially left blank
        }

    Node::~Node() {
        delete data;
        this->setData(nullptr);
        delete next;
        this->setNext(nullptr);
        delete prev;
        this->setPrev(nullptr);
    }

// Getters
    Actor* Node::getData() {
        return this->data;
    }

    Node* Node::getNext() {
        return this->next;
    }

    Node* Node::getPrev() {
        return this->prev;
    }

// Setters
    void Node::setData(Actor *data) {
        this->data = data;
    }

    void Node::setNext(Node *next) {
        this->next = next;
    }

    void Node::setPrev(Node *prev) {
        this->prev = prev;
    }

// Operator overloads
    // lhs is "left hand side" abbreviated
    bool operator==(Node *lhs, Node *rhs) {
        if ((*lhs).getData() == (*rhs).getData()) { 
            return true;
        } else {
            return false;
        }
    }