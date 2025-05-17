#ifndef CHARACTERMANAGER_H
#define CHARACTERMANAGER_H

#include "../include/models/LinkedList.h"

class CharacterManager
{
public:
	CharacterManager();
	void run();

	void loadCharactersFromFile();
    void saveCharactersToFile(); 
	void addCharacterToFile(Node* newNode);
    void removeCharacterFromFile(Node* nodeToRemove);

	void displayMenu();
	void handleUserInput(int choice);
	std::string getFileName() const;
	

private:
	LinkedList characterList;
	const std::string fileName = "characters.txt";
	int characterCount;
};

#endif