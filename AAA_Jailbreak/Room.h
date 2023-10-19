#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Item.h"

using namespace std;


class Room {
	string name;
	string description;

	vector<Item> ItemsInRoom;
public:
	Room* backRoom;
	Room* leftRoom;
	Room* rightRoom;
	Room* forwardRoom;

	Room(string n, string desc, Room* bR, Room* lR, Room* rR, Room* fR);

	bool SearchForItem(string itemName);
	Item GetItem(string itemName);

	void AddItemToRoom(Item item);
	void RemoveItemFromRoom(string itemName);

	string getName() const;
	string getDescription() const;

};