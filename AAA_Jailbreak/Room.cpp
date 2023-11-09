
#include "Room.h"

Room::Room(string n, string desc, Room* bR, Room* lR, Room* rR, Room* fR, int moveCounter) {
	name = n;
	description = desc;
	backRoom = bR;
	leftRoom = lR;
	rightRoom = rR;
	forwardRoom = fR;
	amountTimesInRoom = moveCounter;
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

Room::~Room() {
	for (auto person : PeopleInRoom) {
		delete person;
	}
}

// duplicate bool Room::SearchForItem(string itemName) removed

// duplicate Item Room::GetItem(string itemName) removed



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

void Room::AddNPCToRoom(NPC* npc) {
	PeopleInRoom.push_back(npc);
}

bool Room::SearchForPerson(string personName) {

	vector<NPC*>::iterator it;
	it = PeopleInRoom.begin();
	while (it != PeopleInRoom.end()) {
		if (personName == (*it)->getName()) {
			cout << (*it)->getName();
			return true;
		}
		++it;
	}

	return false;
}


NPC* Room::getNPC(string personName) {
	vector<NPC*>::iterator it;
	it = PeopleInRoom.begin();
	while (it != PeopleInRoom.end()) {
		if (personName == (*it)->getName()) {
			return *it;
		}
		++it;
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
			cout << item.getName() << "\n\t" << item.getDescription() << "\n\n";
		}

	}
}
