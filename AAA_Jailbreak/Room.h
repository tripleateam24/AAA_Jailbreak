#pragma once
#include <string>
#include <iostream>

using namespace std;

class Room{
	string name;
	string description;
	//we can add more stuff here later

public:
	//pointers to other rooms within a room
	//sort of like doorways
	Room* backRoom;
	Room* leftRoom;
	Room* rightRoom;
	Room* forwardRoom;

	//constructor for each room
	Room(string n, string desc, Room* bR, Room* lR, Room* rR, Room* fR);

	//getter functions for name and description
	string getName() const;
	string getDescription() const;

};