#ifndef CHARACTERCREATIONHANDELER_H
#define CHARACTERCREATIONHANDELER_H

#include "../include/models/LinkedList.h"
#include "../include/models/Actor.h"
#include <string>

class CharacterCreationHandeler {
public:
    // Creates a new character and adds it to the list
    void createCharacter(LinkedList& list, const std::string& name,
        bool isPlayer, bool isAlly,
        bool isNeutral, bool isHostile);

    // Removes a character by name from the list
    bool removeCharacter(LinkedList& list, const std::string& name);

    // Displays all characters in the list
    void displayCharacters(const LinkedList& list);

    //Searches for a character in the list by name
    Node* SearchForCharacter(const LinkedList& list, const std::string& name);
};

#endif