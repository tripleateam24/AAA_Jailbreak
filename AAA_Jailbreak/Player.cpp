#include "Player.h"
#include "Item.h"


Player::Player(string n) {
	name = n;
}

void Player::PrintInstructions() {
	string answer;
	string instructions = "Here's How to Play:\nMOVE - Move rooms\n\tleft - left\n\tright - right\n\tforward - forward\n\tback - back\n"
		"\nWHERE - Check where you are in the prison\nINSPECT - Inspect the room in which you are in"
		"\nTAKEITEM - Take an item in the room\nDISCARD - Discard an item from your inventory\n"
		"INVENTORY - See what you have in your inventory\n"
		"EXIT - Exit the game\nHELP - Print this menu again\n\n\n\n";
	cout << instructions << "\n\nress Enter to Continue ";
	getline(cin, answer);
	cout << "\n\n";

}



void Player::TakeItem(Prison* prison, string itemName) {
	if (PocketsInventory.size() >= 2) {
		cout << "You're pockets are already full!\n";
	}
	else {
		if (prison->currentRoom->SearchForItem(itemName)) {
			cout << "You have found " << itemName << endl;
			PocketsInventory.push_back(prison->currentRoom->GetItem(itemName));
			prison->currentRoom->RemoveItemFromRoom(itemName);
		}
		else {
			cout << "You cannot find " << itemName << " in this room.\n";
		}
	}
}

void Player::DiscardItem(Prison* prison, string itemName) {
	for (int i = 0; i < PocketsInventory.size(); i++) {
		if (PocketsInventory[i].getName() == itemName) {
			cout << "Dropping " << PocketsInventory[i].getName() << " on floor of the " << prison->currentRoom->getName() << endl;
			prison->currentRoom->AddItemToRoom(PocketsInventory[i]);
			PocketsInventory.erase(PocketsInventory.begin() + i);
		}
	}


}

bool Player::HasItem(string itemName) {
	for (auto item : PocketsInventory) {
		if (item.getName() == itemName) {
			return true;
		}
	}
	return false;

}

void Player::TalkToNPC(Prison* prison) {
	string answer;
	cout << "Who do you want to talk to? ";
	getline(cin, answer);
	if (prison->currentRoom->SearchForPerson(answer)) {
		cout << prison->currentRoom->getNPC(answer).generateDialogue();
	}
	else {
		cout << "There is no one in this room by that name.\n";
	}


}

//Input menu parser
//this method could be moved out of the class an be a standalone function
void Player::InputMenu(Prison* prison) {
	string answer;
	string itemAnswer;
	string dropAnswer;
	cout << "\nWhat would you like to do in " << prison->currentRoom->getName() << "?\n";
	cout << "Enter Choice: ";
	getline(cin, answer);
	if (answer == "TAKEITEM") {
		cout << "which item? ";
		getline(cin, itemAnswer);
		TakeItem(prison, itemAnswer);

	}
	else if (answer == "MOVE") {
		prison->MoveRooms();
	}
	else if (answer == "INVENTORY") {
		PrintInventory();
	}
	else if (answer == "whereami" || answer == "w" || answer == "W" || answer == "WhereAmI" || answer == "WHERE" || answer == "Where") {
		cout << "\nYou are currently standing in " << prison->currentRoom->getName() << "\n\n";
	}
	else if (answer == "inspect" || answer == "i" || answer == "I" || answer == "INSPECT") {
		cout << "\n" << prison->currentRoom->getDescription() << "\n\n";
	}
	else if (answer == "DISCARD") {
		if (PocketsInventory.empty()) {
			cout << "You have nothing in your pockets to discard.\n";
		}
		else {
			cout << "What would you like to drop? ";
			getline(cin, dropAnswer);
			if (HasItem(dropAnswer)) {
				DiscardItem(prison, dropAnswer);
			}
			else {
				cout << "You don't have this item.\n";
			}
		}
	}
	else if (answer == "SEARCH") {
		prison->currentRoom->PrintItems();
	}
	else if (answer == "HELP") {
		PrintInstructions();
	}
	else if (answer == "TALK") {
		TalkToNPC(prison);
	}
	else if (answer == "EXIT") {
		cout << "Exiting Game...\n";
		exit(0);
	}
	else if (answer == "USEITEM")
	{
		manipulateItem();
	}
	else {
		cout << "Sorry, didn't quite understand that.\n";
	}

}

void Player::PrintInventory() {
	cout << "\nYou feel around in your pockets....\n";
	if (PocketsInventory.empty()) cout << "You have nothing on you right now.\n";
	for (auto item : PocketsInventory) {
		cout << item.getName() << ":\n" << item.getDescription() << "\n\n";
	}

}

void Player::setName(string n) {
	name = n;
}

string Player::getName() const {
	return name;
}

// Revist
void Player::manipulateItem()
{
	//string itemType = Item.getType();
	string answer;
	cout << "Which item? \n";
	getline(cin, answer);
	if (answer == "Cookie")
	{
		string item = answer;
		for (int i = 0; i < PocketsInventory.size(); i++) {
			if (PocketsInventory[i].getName() == item) {
				cout << "You consumed " << item << endl;
				PocketsInventory.erase(PocketsInventory.begin() + i);
			}
		}
	}

	// add weapon item

	/*
	switch (itemType)
	{
	case "cookie":

		for (int i = 0; i < PocketsInventory.size(); i++) {
			if (PocketsInventory[i].getName() == item) {
				cout << "You consumed " << item << endl;
				PocketsInventory.erase(PocketsInventory.begin() + i);
			}
		}
		break;
	case "Wepon":
		cout << "Attacked with " << item << endl;
		break;

	}
	string Item::getType() const
	{
		return itemType();
	}
	*/
}
