#pragma once
#include "Room.h"


class Prison {
	public:
		//defining the room objects that the prison itself has
		Room* cell;
		Room* hallway;
		Room* cafe;
		Room* gym;
		Room* showers;
		Room* courtYard;
		Room* WardensOffice;

		//this room will be the tracker for which room the player is currently in
		Room* currentRoom;


		Prison();
		~Prison();

		void PrintRoom();


};
