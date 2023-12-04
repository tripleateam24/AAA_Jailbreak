#pragma once
#include <iostream>
#include "Item.h"
#include "Prison.h"

using namespace std;

class Player {
	string name;
	int health;
	int strengthModifier;

	vector<Item> PocketsInventory;

public:
	Player(string n);
	bool doesPlayerHaveItem(string item);
	bool doesPlayerHaveWepon(string wepon);
	//sneak attack someone to start fight
	//JP3 changed player to pointer argument
	void startFightBySneakAttack(Prison* prison, Player player);
	//JP3 Added addtional function declarator
	void startFightBySneakAttack(Room* room, Player player);
	//3PJ

	//start fight fairly 
	//JP3 changed player to pointer argument
	void startFightFairly(Prison* prison, Player player);

	//prints a list of instructions a player may use
	void PrintInstructions();

	//allows user to pick up item from a given room 
	void TakeItem(Prison* prison, string itemName);

	//allows user to get rid of an item in their inventory
	void DiscardItem(Prison* prison, string itemName);

	//prints list of items and discriptions of whats in users intentory 
	void PrintInventory();

	//interact with dialog with npc charaters
	void TalkToNPC(Prison* prison);

	//exchange valueable items with traders to advance in the game
	void Trade(Prison* prison, string traderName);

	//checks to see if a given item is found in inventory
	bool HasItem(string itemName);

	//allows user to get stronger by working out
	void Exercise(Prison* prison);

	//displays menu to get user input
	void InputMenu(Prison* prison, Player player);

	//sets the name of the player
	void setName(string n);

	//sets the health of the player
	void setHealth(int x);

	//set strength of player
	void setStrengthModifier(int x);

	//get name of player
	string getName() const;

	//return the current health
	int getHealth() const;

	//return the current strength
	int getStrengthModifier() const;

	//allow user to manipulate items found in inventory
	//JP3 Add prison Object
	void manipulateItem(Prison*);
	//3PJ

	//give player a moves too attack with
	void attack(Prison* prison, NPC* Opp, int f);
	//JP3 Additional function declarator
	void attack(Room* r, NPC* Opp, int temp);
	//3PJ

	//take damage
	void takeDamage(int damage);
};