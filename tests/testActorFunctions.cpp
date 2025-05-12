#include "../include/CharacterManager.h"
#include "../include/models/LinkedList.h"
#include "../include/models/Node.h"
#include "../include/models/Actor.h"
#include "../include/CharacterCreationHandeler.h"

#include <iostream>
#include <cassert>

using namespace std;

void testActor
{
    std::cout << "Testing Actor basic functions...\n";
    Actor actor;

    // Testing default values
    assert(actor.getName() == "__PlaceHolder__");
    assert(actor.getHp() == 10.0);
    assert(actor.getXp() == 0.0);
    assert(actor.isNeutral() == true);
    assert(actor.isPlayer() == false);
    assert(actor.isAlly() == false);
    assert(actor.isHostile() == false);

    // Testing setters
    actor.setName("TestActor");
    assert(actor.getName() == "TestActor");
    actor.setPlayer(true);
    assert(actor.isPlayer() == true);
    actor.setAlly(false);
    assert(actor.isAlly() == false);
    actor.setNeutral(false);
    assert(actor.isNeutral() == false);
    actor.setHostile(true);
    assert(actor.isHostile() == true);

    std::cout << "Actor tests passed!\n";  
}