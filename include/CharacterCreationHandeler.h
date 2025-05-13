#ifndef CHARACTERCREATIONHANDELER_H
#define CHARACTERCREATIONHANDELER_H

#include "../include/models/LinkedList.h"
#include "../include/models/Actor.h"
#include <string>

class CharacterCreationHandeler {
public:
    // Creates a new character and adds it to the list
    static void createCharacter(LinkedList& list, const std::string& name,
        bool isPlayer, bool isAlly,
        bool isNeutral, bool isHostile);

    // Removes a character by name from the list
    static bool removeCharacter(LinkedList& list, const std::string& name);

    // Displays all characters in the list
    static void displayCharacters(const LinkedList& list);

    //Searches for a character in the list by name
    static Node* SearchForCharacter(const LinkedList& list, const std::string& name);
};

#endif