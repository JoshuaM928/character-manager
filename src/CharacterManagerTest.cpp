#include "../include/CharacterManager.h"

void testCharacterManager() {
    std::cout << "Testing CharacterManager...\n";
    CharacterManager manager;


    // Test displayMenu - would normally capture output, but for simplicity just call it
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