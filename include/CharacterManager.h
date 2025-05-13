#ifndef CHARACTERMANAGER_H
#define CHARACTERMANAGER_H

#include "../include/models/LinkedList.h"

class CharacterManager
{
public:
	CharacterManager();
	void run();

	void displayMenu();
	void handleUserInput(int choice);

private:
	LinkedList characterList;
};

#endif