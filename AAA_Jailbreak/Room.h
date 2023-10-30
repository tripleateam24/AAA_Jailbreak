#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Item.h"
#include "NPC.h"

using namespace std;


class Room {
	string name;
	string description;

	vector<Item> ItemsInRoom;
	vector<NPC> PeopleInRoom;

public:
	Room* backRoom;
	Room* leftRoom;
	Room* rightRoom;
	Room* forwardRoom;

	Room(string n, string desc, Room* bR, Room* lR, Room* rR, Room* fR);

	bool SearchForItem(string itemName);
	Item GetItem(string itemName);
	void printIteminroom();
	void AddItemToRoom(Item item);
	void RemoveItemFromRoom(string itemName);

	void AddNPCToRoom(NPC npc);
	bool SearchForPerson(string personName);
	NPC getNPC(string personName);

	string getName() const;
	string getDescription() const;

	void PrintItems();
};