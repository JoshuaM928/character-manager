#include "../include/models/LinkedList.h"

// Default constructor, copy constructor, & deconstructor
    LinkedList::LinkedList() : size(0), head(nullptr), tail(nullptr) {
        // Intentionally left blank
    }

    LinkedList::LinkedList(const LinkedList &other) {
        this->size = other.getSize(); 
        this->head = new Node((*other.getHead()).getData());
        this->tail = new Node((*other.getTail()).getData());
    } 

    LinkedList::~LinkedList() {
        delete head;
        this->setHead(nullptr);
        delete tail;
        this->setTail(nullptr);
    }

// Getters
    Node* LinkedList::getHead() const {
        return this->head;
    }

    Node* LinkedList::getTail() const {
        return this->tail;
    }

    int LinkedList::getSize() const {
        return this->size;
    }

// Setters
    void LinkedList::setSize(const int newSize) {
        this->size = newSize;
    }

    void LinkedList::setHead(Node *newHead) {
        this->head = new Node((*newHead).getData());
    }

    void LinkedList::setTail(Node *newTail) {
        this->tail = new Node((*newTail).getData());
    }

// Actions
    Node* LinkedList::linearSearch(Actor *target) const {
        // Local variables
        Node *currNode = this->getHead();
        
        // Search every Node's data till you find the 'target' data
        while (currNode != nullptr) {

            // If current node contains 'target' data
            if ((*currNode).getData() == target) {
                return currNode; // return current node
            }

            currNode = (*currNode).getNext(); // Move to the next Node
        }
        
        // List didn't contain 'target' data, return nullptr
        return nullptr; 
    }

    void LinkedList::mergeSort() {
        // TODO: Implement merge sort 
    }