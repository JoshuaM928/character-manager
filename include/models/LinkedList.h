#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

class LinkedList {
    public:
        // Default constructor, copy constructor, & deconstructor
            LinkedList();
            LinkedList(const LinkedList &other);
            ~LinkedList();
        // Getters
            Node* getHead() const;
            Node* getTail() const;
            int getSize() const;
        // Setters
            void setSize(const int newSize);
            void setHead(Node *newHead);
            void setTail(Node *newTail);
        // Actions
            Node* linearSearch(Actor *target) const;
            void mergeSort();
    private:
        // Members
            int size;
            Node *head;
            Node *tail;
};

#endif // LINKEDLIST_H