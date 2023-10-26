#pragma once
#include "Room.h"

class Prison {
public:
	Room* cell;
	Room* hallway;
	Room* cafe;
	Room* gym;
	Room* showers;
	Room* courtYard;
	Room* WardensOffice;

	Room* currentRoom;

	Prison();
	~Prison();

	void MoveRooms();

	void PrintRoom();

};