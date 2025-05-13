#ifndef CHARACTERMANAGER_H
#define CHARACTERMANAGER_H

#include "../include/models/LinkedList.h"

class CharacterManager
{
public:
	CharacterManager();
	void run();

private:
	LinkedList characterList;
	void displayMenu();
	void handleUserInput(int choice);
};

#endif