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
	//print actions a player can take
	void PrintInstructions();
	//allow user to pick up item
	void TakeItem(Prison* prison, string itemName);
	//get rid of item and place in current room 
	void DiscardItem(Prison* prison, string itemName);
	//print pockets
	void PrintInventory();
	void TalkToNPC(Prison* prison);
	//exchange items with npcs
	void Trade(Prison* prison, string traderName);
	//sneak attack someone to start fight
	void startFightBySneakAttack(Room* room);
	bool HasItem(string itemName);
	//start fight fairly 
	void startFightFairly(Room* room);

	void Exercise(Prison* prison);

	void InputMenu(Prison* prison);

	void setName(string n);
	void setHealth(int x);
	void setStrengthModifier(int x);
	void attack(Room* r,NPC* Opp,int f);
	string getName() const;
	int getHealth() const;
	int getStrengthModifier() const;
	void takeDamage(int damage);
	string clearWhiteSpaceAndCapitalize(string input);
	void manipulateItem();

};