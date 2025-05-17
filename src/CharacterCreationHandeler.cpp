#include "../include/CharacterCreationHandeler.h"
#include <iostream>

using namespace std;

void CharacterCreationHandeler::createCharacter(LinkedList& list, const string& name, bool isPlayer,
     bool isAlly, bool isNeutral, bool isHostile, const double x, const double y, const double z)
{
    // Create new Actor
    Actor* newActor = new Actor();
    newActor->setName(name);
    newActor->setPlayer(isPlayer);
    newActor->setAlly(isAlly);
    newActor->setNeutral(isNeutral);
    newActor->setHostile(isHostile);
    newActor->setPos(x,y,z);
    // Create new Node with the Actor
    Node* newNode = new Node(newActor);

    // Add to list (simple implementation - adds to end)
    if (list.getHead() == nullptr) 
    {
        list.setHead(newNode);
        list.setTail(newNode);
    }
    else
    {
        newNode->setPrev(list.getTail());
        list.getTail()->setNext(newNode);
        list.setTail(newNode);
    }
    list.setSize(list.getSize() + 1);
}

Node* CharacterCreationHandeler::SearchForCharacter(const LinkedList& list, const string& name)
{
    Node* current = list.getHead();
    while (current != nullptr) {
        if (current->getData()->getName() == name) 
        {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

bool CharacterCreationHandeler::removeCharacter(LinkedList& list, const string& name) 
{
    Node* current = SearchForCharacter(list, name);
    
    if (current != nullptr){
        Node* prevNode = current->getPrev();
        Node* nextNode = current->getNext();
        if (prevNode != nullptr) 
        {
            prevNode->setNext(nextNode);
        }
        else 
        {
            list.setHead(nextNode);
        }
        if (nextNode != nullptr)
        {
            nextNode->setPrev(prevNode);
        }
        else 
        {
            list.setTail(prevNode);
        }
        delete current;
        list.setSize(list.getSize() - 1);
        
        return true;
    }
    return false; // Character not found
}
