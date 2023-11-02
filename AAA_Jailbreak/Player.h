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
	void PrintInstructions();
	void TakeItem(Prison* prison, string itemName);
	void DiscardItem(Prison* prison, string itemName);
	void PrintInventory();
	void TalkToNPC(Prison* prison);
	void Trade(Prison* prison, string traderName);

	bool HasItem(string itemName);

	void Exercise(Prison* prison);

	void InputMenu(Prison* prison);

	void setName(string n);
	void setHealth(int x);
	void setStrengthModifier(int x);

	string getName() const;
	int getHealth() const;
	int getStrengthModifier() const;

	void manipulateItem();

};