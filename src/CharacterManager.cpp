#include "../include/CharacterManager.h"
#include "../include/CharacterCreationHandeler.h"
#include <iostream>

enum MyEnum
{
    ADD = 1,
    REMOVE = 2,
    LIST = 3,
    SEARCH = 4,
    EXIT = 0
};

using namespace std;

CharacterManager::CharacterManager() {
    //intentionally left blank
}

void CharacterManager::run() {
    int choice = 0;
    do {
        displayMenu();
        cin >> choice;
        handleUserInput(choice);
    } while (choice != 0);
}

void CharacterManager::displayMenu() {
    cout << "\nCharacter Manager\n";
    cout << "1. Add Character\n";
    cout << "2. Remove Character\n";
    cout << "3. List Characters\n";
    cout << "4. Search Character\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

void CharacterManager::handleUserInput(int choice) {
    switch (choice) {
    case ADD: {

        string name; 
        char type;

        cout << "Enter Character Name:  ";
        getline(cin, name);

        cout << "Is your character a Player(P), Ally(A), Neutral(N), or Hostile(H)?:  ";
        cin >> type;
        cin.ignore();

        bool isPlayer = false, isAlly = false, isNeutral = false, isHostile = false;

        switch (toupper(type)) {
        case 'P':
        {
            isPlayer = true;
            break;
        }
        case 'A':
        {
            isAlly = true;
            break;
        }
        case 'N':
        {
            isNeutral = true;
            break;
        }
        case 'H': 
        {
            isHostile = true;
            break;
        }
        default: isNeutral = true;
        }
        CharacterCreationHandeler::createCharacter(characterList, name, isPlayer, isAlly, isNeutral, isHostile);
        cout << "Character added successfully!\n";
        break;
    }
    case REMOVE: {
        string name;
        cout << "Enter character name to remove: ";
        getline(cin, name);
        if (CharacterCreationHandeler::removeCharacter(characterList, name)) {
            std::cout << "Character removed successfully!\n";
        }
        else {
            std::cout << "Character not found!\n";
        }
        break;
    }
    case LIST: {
        
        std::cout << "Not Implemented\n";
        break;
    }
    case SEARCH: {
        
        std::cout << "Not Implemented\n";
        break;
    }
    case EXIT: {
        std::cout << "Exiting...\n";
        break;
    }
    default: {
        std::cout << "Invalid choice. Please try again.\n";
        break;
    }
    }
}