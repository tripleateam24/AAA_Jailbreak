#include "Room.h"

Room::Room(string n, string desc, Room* bR, Room* lR, Room* rR, Room* fR) {
	name = n;
	description = desc;
	backRoom = bR;
	leftRoom = lR;
	rightRoom = rR;
	forwardRoom = fR;
	numTimesInRoom = 0;
}

Room::~Room() {
	for (auto person : PeopleInRoom) {
		delete person;
	}
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

vector<Item> Room::GetContraband() {
	
	vector<Item> itemsToConfiscate;
	for (auto item : ItemsInRoom) {
		if (item.getType() == "valuable" || item.getType() == "key_item" || item.getType() == "objective_item" || item.getType() == "wepons") {
			itemsToConfiscate.push_back(item);
			
		}
	}

	//will return an empty vector if there are no items in the room - make sure to use if statement in INSPECTION method
	return itemsToConfiscate;
	
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

NPC* Room::getNPCByIndex(int index) {
	if (PeopleInRoom.size() == 0) {
		return nullptr;
	}else{
		return PeopleInRoom[index];
	}
}

//getter methods:
string Room::getName() const {
	return name;
}
string Room::getDescription() const {
	return description;

}

int Room::getNumPeopleInRoom() {
	int total = PeopleInRoom.size();
	return total;

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

void Room::PrintPeople() {
	if (!PeopleInRoom.empty()) {
		cout << "\nYou look around you....\n\nYou see: \n";
		for (auto person : PeopleInRoom) {
			cout << person->getName() << ":\n\t" << person->getDescription() << "\n\n";
		}

	}
}