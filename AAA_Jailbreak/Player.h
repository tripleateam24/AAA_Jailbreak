#pragma once
#include <iostream>
#include "Item.h"
#include "Prison.h"

using namespace std;

class Player {
	string name;
	vector<Item> PocketsInventory;

public:
	Player(string n);
	void PrintInstructions();
	void TakeItem(Prison* prison, string itemName);
	void DiscardItem(Prison* prison, string itemName);
	void PrintInventory();
	bool HasItem(string itemName);

	void InputMenu(Prison* prison);

	void setName(string n);

	string getName() const;

	void manipulateItem();

};