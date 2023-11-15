#pragma once
#define PRISON_H
#include "Room.h"
#include <string>
#include "Enemy.h"
#include "Trader.h"
#include "Guard.h"
#include "QuestGiver.h"

class Prison {
	//day light and day counter
	int dayLight;
	int dayCounter;


public:
	//all rooms within prison
	Room* cell;
	Room* bathroom;
	Room* hallway;
	Room* cafe;
	Room* commonRoom;
	Room* gym;
	Room* showers;
	Room* workshopRoom;
	Room* courtYard;
	Room* WardensOffice;
	Room* airlock;
	Room* laundryRoom;

	Room* currentRoom;

	Prison();
	~Prison();

	void MoveRooms();

	void PrintRoom();

	void LoseDayLight(int);
	void SetDayLight(int);
	int getDaylight() const;

	void newDay();

	int getDay() const;



};