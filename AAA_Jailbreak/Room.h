#pragma once
#include <string>
#include <vector>
#include "NPC.h"
#include "Trader.h"
#include "Enemy.h"
#include "Item.h"

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
	~Room();

	bool SearchForItem(string itemName);
	Item GetItem(string itemName);
	bool isAnyoneThere();
	void AddItemToRoom(Item item);
	void RemoveItemFromRoom(string itemName);
	void printPeopleInRoom();
	void AddNPCToRoom(NPC* npc);
	bool SearchForPerson(string personName);
	void RemoveNPCFromRoom(string name);
	NPC* getNPC(string personName);
	string getName() const;
	string getDescription() const;

	void PrintItems();



};