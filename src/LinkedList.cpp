#include "../include/models/LinkedList.h"

// Default constructor, copy constructor, & deconstructor
    LinkedList::LinkedList() : size(0), head(nullptr), tail(nullptr) {
        // Intentionally left blank
    }

//Since this is the copy for the Linked List,  it  should be copying the entire list, not just the head and tail node.
    LinkedList::LinkedList(const LinkedList &other) {
        this->size = other.getSize(); 
        
        //Empty List check
        if (other.getHead() == nullptr) {
            this->head = this->tail = nullptr;
            return;
        }

        this->head = new Node((*other.getHead()).getData());
        Node* current = this->head;
        Node* nextCurrent = other.getHead()->getNext();

        while (nextCurrent != nullptr) {
            Node* copiedNode = new Node(nextCurrent->getData());
            current->setNext(copiedNode);
            copiedNode->setPrev(current);
            nextCurrent = nextCurrent->getNext();
        }
        this->tail = current;
    } 

    LinkedList::~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->getNext();
            delete current;
            current = next;
        }
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
//I don't think this should be creating a new Node. Creating new Nodes and adding them to the List should happen in Node    
    void LinkedList::setHead(Node *newHead) {
        this->head = newHead;
    }

    void LinkedList::setTail(Node *newTail) {
        this->tail = newTail;
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