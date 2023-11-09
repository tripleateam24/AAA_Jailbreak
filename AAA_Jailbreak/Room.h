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
	vector<NPC*> PeopleInRoom;

public:
	Room* backRoom;
	Room* leftRoom;
	Room* rightRoom;
	Room* forwardRoom;

	Room(string n, string desc, Room* bR, Room* lR, Room* rR, Room* fR, int moveCounter);
	~Room();

	bool SearchForItem(string itemName);
	Item GetItem(string itemName);

	void AddItemToRoom(Item item);
	void RemoveItemFromRoom(string itemName);

	void AddNPCToRoom(NPC* npc);
	bool SearchForPerson(string personName);

	NPC* getNPC(string personName);

	int amountTimesInRoom;

	string getName() const;
	string getDescription() const;

	void PrintItems();



};