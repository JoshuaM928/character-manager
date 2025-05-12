#include "../include/CharacterManager.h"
#include "../include/models/LinkedList.h"
#include "../include/models/Node.h"
#include "../include/models/Actor.h"
#include "../include/CharacterCreationHandeler.h"

#include <iostream>
#include <cassert>

using namespace std;

void testCharacterCreationHandler()
{
	cout << "Testing CharacterCreationHandler...\n";
	LinkedList list;

	// Test createCharacter
    createCharacter(list, "TestChar1", true, false, false, true);
    assert(list.getSize() == 1);
    assert(list.getHead() != nullptr);
    assert(list.getHead()->getData()->getName() == "TestChar1");
    assert(list.getHead()->getData()->isPlayer());
    assert(list.getHead()->getData()->isHostile());

    // Test SearchForCharacter
    Node* found = SearchForCharacter(list, "TestChar1");
    assert(found != nullptr);
    assert(found->getData()->getName() == "TestChar1");

    Node* notFound = SearchForCharacter(list, "NonExistent");
    assert(notFound == nullptr);

    // Test removeCharacter
    bool remove = CharacterCreationHandeler::removeCharacter(list, "TestChar1");
    assert(remove == true);
    assert(list.getSize() == 0);
    assert(list.getHead() == nullptr);
    remove = CharacterCreationHandeler::removeCharacter(list, "NonExistent");
    assert(remove == false);

    cout << "CharacterCreationHandler tests passed!\n";
}