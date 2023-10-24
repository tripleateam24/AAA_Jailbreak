#include "Room.h"

//constructor for each room
Room::Room(string n, string desc, Room* bR, Room* lR, Room* rR, Room* fR) {
	name = n;
	description = desc;
	backRoom = bR;
	leftRoom = lR;
	rightRoom = rR;
	forwardRoom = fR;

}

//getter functions for name and description
string Room::getName() const{
	return name;
}
string Room::getDescription() const{
	return description;
}


