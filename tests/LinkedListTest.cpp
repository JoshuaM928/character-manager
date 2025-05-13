#include "../include/CharacterManager.h"
#include "../include/models/LinkedList.h"
#include "../include/models/Node.h"
#include "../include/models/Actor.h"
#include "../include/CharacterCreationHandeler.h"

#include <iostream>
#include <cassert>

using namespace std;

void testLinkedList()
{
	cout << "Testing LinkedList...\n";
	LinkedList list;

	// Test empty list
	assert(list.getHead() == nullptr);
	assert(list.getTail() == nullptr);
	assert(list.getSize() == 0);

	// Test adding nodes
	Actor* actor1 = new Actor();
	actor1->setName("ListTest1");
	Node* node1 = new Node(actor1);
	list.setHead(node1);
	list.setTail(node1);
	list.setSize(1);
	assert(list.getHead() == node1);
	assert(list.getTail() == node1);
	assert(list.getSize() == 1);

	// Test linear search
	assert(list.linearSearch(actor1) == node1);
	Actor* emptyActor = new Actor();
	assert(list.linearSearch(emptyActor) == nullptr);
	delete emptyActor;
	
	// Test copy
	LinkedList list2(list);
	assert(list2.getSize() == list.getSize());
	assert(list2.getHead() != list.getHead()); // Should be deep copy
	assert(list2.getHead()->getData()->getName() == list.getHead()->getData()->getName());

	cout << "LinkedList tests passed!\n";
	delete actor1;
	delete node1;
}