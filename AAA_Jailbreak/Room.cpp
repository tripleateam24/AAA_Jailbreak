#include "Room.h"
#include <iostream>
using namespace std;
Room::Room(string n, string desc, Room* bR, Room* lR, Room* rR, Room* fR) {
	name = n;
	description = desc;
	backRoom = bR;
	leftRoom = lR;
	rightRoom = rR;
	forwardRoom = fR;

}


bool Room::SearchForItem(string itemName) {
	for (auto item : ItemsInRoom) {
		if (item.getName() == itemName) {
			return true;
		}
	}
	return false;
}

Item Room::GetItem(string itemName) {
	for (auto item : ItemsInRoom) {
		if (item.getName() == itemName) {
			return item;
		}
	}
}
void Room::printIteminroom()
{
	cout << "items in Room: \n";
		for (int i = 0; i < ItemsInRoom.size(); i++) {
			cout << "*"<< ItemsInRoom[i].getName() << endl;
		}
}
void Room::AddItemToRoom(Item item) {
	ItemsInRoom.push_back(item);
}

void Room::RemoveItemFromRoom(string itemName) {
	for (int i = 0; i < ItemsInRoom.size(); i++) {
		if (ItemsInRoom[i].getName() == itemName) {
			ItemsInRoom.erase(ItemsInRoom.begin() + i);
		}
	}
}

void Room::AddNPCToRoom(NPC npc) {
	PeopleInRoom.push_back(npc);
}

bool Room::SearchForPerson(string personName) {
	for (auto person : PeopleInRoom) {
		if (personName == person.getName()) {
			return true;
		}
	}
	return false;
}

NPC Room::getNPC(string personName) {
	for (auto person : PeopleInRoom) {
		if (personName == person.getName()) {
			return person;
		}
	}
}

//getter methods:
string Room::getName() const {
	return name;
}
string Room::getDescription() const {
	return description;

}

void Room::PrintItems() {
	cout << "\nYou Look around you....\n";
	if (ItemsInRoom.empty()) {
		cout << "Nothing catches your eye.\n";
	}
	else {
		cout << "\nYou see:\n";
		for (auto item : ItemsInRoom) {
			cout << item.getName() << "\n\t" << item.getName() << "\n\n";
		}

	}
}
