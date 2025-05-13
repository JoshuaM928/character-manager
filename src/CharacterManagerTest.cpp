#include "../include/CharacterManager.h"
#include "../include/models/LinkedList.h"
#include "../include/models/Node.h"
#include "../include/models/Actor.h"
#include "../include/CharacterCreationHandeler.h"

#include <iostream>

void testCharacterManager() {
    std::cout << "Testing CharacterManager...\n";
    CharacterManager manager;


    // Test displayMenu 
    manager.displayMenu();

    // Test handleUserInput with various cases
    manager.handleUserInput(1);  // ADD
    manager.handleUserInput(2);  // REMOVE
    manager.handleUserInput(3);  // LIST
    manager.handleUserInput(4);  // SEARCH
    manager.handleUserInput(0);  // EXIT
    manager.handleUserInput(99); // Invalid

    std::cout << "CharacterManager tests passed!\n";
}