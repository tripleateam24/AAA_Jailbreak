#pragma once
#include "Room.h"

class Prison {
	int dayLight;
	int dayCounter;


public:
	Room* cell;
	Room* hallway;
	Room* cafe;
	Room* commonRoom;
	Room* gym;
	Room* showers;
	Room* workshopRoom;
	Room* courtYard;
	Room* WardensOffice;
	Room* airlock;

	Room* currentRoom;

	Prison();
	~Prison();

	void MoveRooms();

	void PrintRoom();

	void LoseDayLight(int x);
	void SetDayLight(int x);
	int getDaylight() const;

	void newDay();

	int getDay() const;



};