#include "../include/CharacterManager.h"
#include "../include/CharacterCreationHandeler.h"
#include <iostream>
#include <fstream>

enum MyEnum
{
    ADD = 1,
    REMOVE = 2,
    LIST = 3,
    SEARCH = 4,
    EXIT = 0
};

using namespace std;

CharacterManager::CharacterManager() 
{
    //loads the character.txt (filename is in .h)
    loadCharactersFromFile();
}

void CharacterManager::run() 
{
    int choice = 0;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
        handleUserInput(choice);
    } while (choice != 0);
}

void CharacterManager::displayMenu() 
{
    cout << "\nCharacter Manager\n";
    cout << "1. Add Character\n";
    cout << "2. Remove Character\n";
    cout << "3. List Characters\n";
    cout << "4. Search Character\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

void CharacterManager::handleUserInput(int choice) 
{
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
        
        Node* newNode = CharacterCreationHandeler::SearchForCharacter(characterList, name);
        if (newNode) 
        {
        addCharacterToFile(newNode);
        }
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
        
        Node* nodeToRemove = CharacterCreationHandeler::SearchForCharacter(characterList, name);
        if (nodeToRemove) 
        {
            removeCharacterFromFile(nodeToRemove);
            CharacterCreationHandeler::removeCharacter(characterList, name);
            cout << "Character removed successfully!\n";
        } 
        else
        {
        cout << "Character not found!\n";
        }
    break;
    }
    case LIST: 
    { 
        Node* current = characterList.getHead();
            if (current == nullptr) 
            {
            cout << "No characters found!\n";
            break;
            }
    
        cout << "\nCharacter List:\n";
        while (current != nullptr) 
        {
            Actor* actor = current->getData();
            cout << "- " << actor->getName() << " [";
            if (actor->isPlayer()) cout << "Player";
            else if (actor->isAlly()) cout << "Ally";
            else if (actor->isNeutral()) cout << "Neutral";
            else if (actor->isHostile()) cout << "Hostile";
            cout << "]\n";
            current = current->getNext();
        }
        break;
    }
    case SEARCH: 
    {
        string name;
        cout << "Enter character name to search: ";
        getline(cin, name);
    
        Node* found = CharacterCreationHandeler::SearchForCharacter(characterList, name);
        if (found) 
        {
            Actor* actor = found->getData();
            cout << "Character found!\n";
            cout << "Name: " << actor->getName() << "\n";
            cout << "Type: ";
            if (actor->isPlayer()) cout << "Player";
            else if (actor->isAlly()) cout << "Ally";
            else if (actor->isNeutral()) cout << "Neutral";
            else if (actor->isHostile()) cout << "Hostile";
            cout << "\n";
        } 
        else 
        {
            cout << "Character not found!\n";
        }
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

void CharacterManager::loadCharactersFromFile() 
{
    ifstream file(filename);
    if (!file.is_open()) return;  // No file exists yet

    string name, typeStr;
    bool isPlayer, isAlly, isNeutral, isHostile;

    while (getline(file, name)) {
        getline(file, typeStr);
        isPlayer = (typeStr.find('P') != string::npos);
        isAlly = (typeStr.find('A') != string::npos);
        isNeutral = (typeStr.find('N') != string::npos);
        isHostile = (typeStr.find('H') != string::npos);

        CharacterCreationHandeler::createCharacter(
            characterList, name, isPlayer, isAlly, isNeutral, isHostile
        );
    }
    file.close();
}

void CharacterManager::saveCharactersToFile() 
{
    ofstream file(filename);
    Node* current = characterList.getHead();

    while (current != nullptr) {
        Actor* actor = current->getData();
        file << actor->getName() << "\n";
        
        // Save character type flags
        string typeStr;
        if (actor->isPlayer()) typeStr += "P";
        if (actor->isAlly()) typeStr += "A";
        if (actor->isNeutral()) typeStr += "N";
        if (actor->isHostile()) typeStr += "H";
        
        file << typeStr << "\n";
        current = current->getNext();
    }
    file.close();
}

void CharacterManager::addCharacterToFile(Node* newNode) {
    ofstream file(filename, ios::app);//the ios::app is something i found when looking up how to do this, cause otherwise the text in the file gets deleted
    if (file.is_open()) {
        Actor* actor = newNode->getData();
        file << actor->getName() << "\n";
        
        // Determine single character type
        char type = 'N'; // Default to Neutral
        if (actor->isPlayer()) type = 'P';
        else if (actor->isAlly()) type = 'A';
        else if (actor->isHostile()) type = 'H';
        
        file << type << "\n";
        file.close();
    }
}

void CharacterManager::removeCharacterFromFile(Node* nodeToRemove) {
    ifstream inFile(filename);
    ofstream tempFile("temp.txt");
    string currentName;
    string currentType;
    bool found = false;
    Actor* actorToRemove = nodeToRemove->getData();

     while (getline(inFile, currentName)) 
     {
        getline(inFile, currentType);
        if (currentName != actorToRemove->getName()) 
        {
            tempFile << currentName << "\n" << currentType << "\n";
        } 
        else 
        {
            found = true;
        }
    }
    
    inFile.close();
    tempFile.close();
    
    if (found) {
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
    } else {
        remove("temp.txt"); // Delete temp file if no changes made
    }
}
