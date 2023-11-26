#include "Player.h"
#include "Room.h"
#include "Item.h"
#include "NPC.h"

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

bool Room::isAnyoneThere()
{
	if (PeopleInRoom.empty())
		return false;
	else
		return true;

}

Room::~Room() {
	for (auto person : PeopleInRoom) {
		delete person;  // Assuming person is of type NPC*
	}
	PeopleInRoom.clear();
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
void Room::printPeopleInRoom()
{
	for (const auto& person : PeopleInRoom) {
		cout << person->getName();
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


void Room::RemoveNPCFromRoom(string name)
{
	for (int i = 0; i < ItemsInRoom.size(); i++) {
		if (PeopleInRoom[i]->getName() == name) {
			PeopleInRoom.erase(PeopleInRoom.begin() + i);
		}
	}
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

void Room::PrintPeople()
{
	if (PeopleInRoom.empty()) {
		cout << "This room is empty.......\n";
	}
	else {
		cout << "\nYou see:\n";
		for (auto people : PeopleInRoom) {
			cout << people->getName() << "\n\t";
		}

	}
}
