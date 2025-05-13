#include "../include/CharacterManager.h"
#include "../include/models/LinkedList.h"
#include "../include/models/Node.h"
#include "../include/models/Actor.h"
#include "../include/CharacterCreationHandeler.h"

#include <iostream>
#include <cassert>

// Test default constructor
    void createEmptyNode() {
        // Node pointer to perform test with
        Node *myNode = new Node();

        if ((*myNode).getData() == nullptr) {
            std::cout << "Node's data is: 'nullptr' \n"
            << "as expected!" << std::endl;
        } else {
            std::cout << "Node's data was NOT: 'nullptr' \n"
            << "as expected!" << std::endl;
        }
    }

// Test parameterized constructor
    void createNodeWithActor() {
        // Node & Actor pointer to perform test with
        Actor *myActor = new Actor();
        Node *myNode = new Node(myActor);

        // Checks if node was created or not
        if (myNode != nullptr) {
            std::cout << "'myNode' was successfully created!" << std::endl;
        } else {
            std::cout << "'myNode' was NOT successfully created!" << std::endl;
        }

        // Checks if the data was created with the data set to 'myActor'
        if ((*myNode).getData() == myActor) {
            std::cout << "'myNode' was created with data set to "
            << "'myActor'" << std::endl;
        } else {
            std::cout << "'myNode' was NOT created with data set to " 
            << "'myActor'" << std::endl;
        }
    }


    void testNode()
    {
        std::cout << "Testing Node basic functions...\n";
        
        Actor* actor1 = new Actor();
        actor1->setName("NodeTest1");
        Actor* actor2 = new Actor();
        actor2->setName("NodeTest2");

        // Testing constructor and getters
        Node node1(actor1);
        assert(node1.getData() == actor1);
        assert(node1.getNext() == nullptr);
        assert(node1.getPrev() == nullptr);

        // Test setters
        Node node2(actor2);
        node1.setNext(&node2);
        node2.setPrev(&node1);
        assert(node1.getNext() == &node2);
        assert(node2.getPrev() == &node1);
    }
