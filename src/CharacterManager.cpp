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
        cin.ignore();
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

        cout << "Enter Character Name: ";
        while (name.empty()) 
        {
            getline(cin, name);
            if (name.empty()) 
            {
            cout << "Name cannot be empty. Try again: ";
            }
        }

        while(toupper(type) != 'P' && toupper(type) != 'A' && toupper(type) != 'N' && toupper(type) != 'H')
        {
            cout << "Is your character a Player(P), Ally(A), Neutral(N), or Hostile(H)?:  ";
            cin >> type;
            if(toupper(type) != 'P' && toupper(type) != 'A' && toupper(type) != 'N' && toupper(type) != 'H')
            {
                cout << "Invalid response, please Enter P, A, N, or H\n";
            }

        }
        cin.ignore();
        cout << endl;

        bool isPlayer = false, isAlly = false, isNeutral = false, isHostile = false;

        switch (toupper(type)) {
        case 'P':
        {
            isPlayer = true;
            cout << "Character is a Player\n";
            break;
        }
        case 'A':
        {
            isAlly = true;
            cout << "Character is an Ally\n";
            break;
        }
        case 'N':
        {
            isNeutral = true;
            cout << "Character is a Neutral\n";
            break;
        }
        case 'H': 
        {
            isHostile = true;
            cout << "Character is a Hostile\n";
            break;
        }
        default: isNeutral = true;
        }
        CharacterCreationHandeler::createCharacter(characterList, name, isPlayer, isAlly, isNeutral, isHostile);
        cout << "Character \"" << name <<"\" added successfully!\n";
        break;
    }
    case REMOVE: {
        string name;
        cout << "Enter the Character's name you want to Remove: ";
        while (name.empty()) 
        {
            getline(cin, name);
            if (name.empty()) 
            {
            cout << "Name cannot be empty. Try again: ";
            }
        }
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