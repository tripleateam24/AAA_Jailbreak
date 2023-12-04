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

	Room(string n, string desc, Room* bR, Room* lR, Room* rR, Room* fR);
	~Room();
	//checks to see if a given item is found in a room
	bool SearchForItem(string itemName);

	//get the name if an item
	Item GetItem(string itemName);

	bool isAnyoneThere();

	//add a given item to the current room
	void AddItemToRoom(Item item);

	//deletes an item from the current room
	void RemoveItemFromRoom(string itemName);

	void printPeopleInRoom();

	//insert an npc into a given room
	void AddNPCToRoom(NPC* npc);

	//checks to see if a given person is in the room.
	bool SearchForPerson(string personName);

	void RemoveNPCFromRoom(string name);

	//returns the npc object for a given name
	NPC* getNPC(string personName);

	//a checker to keep track of amount of times you entered a room
	int amountTimesInRoom;
	//returns the name of the room
	string getName() const;

	//reutrns the name of the current room
	string getDescription() const;

	//prints the item names in the current room
	void PrintItems();

	//prints all npc names in current room
	void PrintPeople();


};