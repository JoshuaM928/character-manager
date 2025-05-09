#include "../include/models/Node.h"
#include <iostream>

// Test default constructor
    void createEmptyNode() {
        // Node pointer to perform test with
        Node *myNode = new Node();

        if ((*myNode).getData() == nullptr) {
            std::cout << "Node's data is: 'nullptr' \n"
            << "as expected!" << endl;
        } else {
            std::cout << "Node's data was NOT: 'nullptr' \n"
            << "as expected!" << endl;
        }
    }

// Test parameterized constructor
    void createNodeWithActor() {
        // Node & Actor pointer to perform test with
        Actor *myActor = new Actor();
        Node *myNode = new Node(myActor);

        // Checks if node was created or not
        if (myNode != nullptr) {
            std::cout << "'myNode' was successfully created!" << endl;
        } else {
            std::cout << "'myNode' was NOT successfully created!" << endl;
        }

        // Checks if the data was created with the data set to 'myActor'
        if ((*myNode).getData() == myActor) {
            std::cout << "'myNode' was created with data set to "
            << "'myActor'" << endl;
        } else {
            std::cout << "'myNode' was NOT created with data set to " 
            << "'myActor'" << endl;
        }
    }

