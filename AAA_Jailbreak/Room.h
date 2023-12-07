#pragma once
#define ROOM_H
#include "NPC.h"

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

	int numTimesInRoom;

	Room(string, string, Room*, Room*, Room*, Room*);
	~Room();

	bool SearchForItem(string);
	Item GetItem(string);

	void AddItemToRoom(Item);
	void RemoveItemFromRoom(string);
	vector<Item> GetContraband();

	void AddNPCToRoom(NPC*);
	bool SearchForPerson(string);

	NPC* getNPC(string);
	NPC* getNPCByIndex(int index);

	string getName() const;
	string getDescription() const;
	int getNumPeopleInRoom();

	void PrintItems();
	void PrintPeople();


};