
#include "Room.h"

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


//getter methods:
string Room::getName() const {
	return name;
}
string Room::getDescription() const {
	return description;

}
