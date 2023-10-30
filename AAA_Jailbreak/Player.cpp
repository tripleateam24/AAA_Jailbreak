#include "Player.h"
#include "Item.h"
#include <chrono>
#include <thread>

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
		prison->currentRoom->printIteminroom();
	}
	else if (answer == "DISCARD") {
		if (PocketsInventory.empty()) {
			cout << "You have nothing in your pockets to discard.\n";
		}
		else {
			cout << "What would you like to drop? ";
			getline(cin, dropAnswer);
			this_thread::sleep_for(2s);
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
	this_thread::sleep_for(3s);
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
//Function allows player to maniplulate object based on type
void Player::manipulateItem()
{
	//Prison* prison;
	vector<string>Item_Types = {"Consumeable","Wepons","potential_Wepons","Throwable","key_Item", "objective_item", "Valuable"};
	string answer;
	cout << "Which item? \n";
	getline(cin, answer);

		//check to see if the item exsit in inventory
		for (int i = 0; i < PocketsInventory.size(); i++) {
			if (PocketsInventory[i].getName() == answer) {
				if (PocketsInventory[i].getType() == Item_Types[0])
				{
					cout << "You consumed " << answer << endl;
					PocketsInventory.erase(PocketsInventory.begin() + i);
				}
				else if (PocketsInventory[i].getType() == Item_Types[1])
				{
					cout << "You swung a " << answer << endl;

				}
				else if (PocketsInventory[i].getType() == Item_Types[2])
				{
					bool ticker = false;
					while (!ticker)
					{
						if (PocketsInventory[i].getName() == "Tooth Brush")
						{
							string choice;
							cout << "To sharpen, enter S.\n";
							cout << "To brush Teeth enter B.\n";
							getline(cin, choice);
							if (choice == "s" || choice == "S")
							{
								cout << "Sharpening Tooth Brush...\n";
								this_thread::sleep_for(3s);
								PocketsInventory[i].updateName("Shank");
								PocketsInventory[i].updateType("Wepon");
								PocketsInventory[i].updatedesc("You sharpended the end of the toothbrush to create a shank. You can use this to injure others.");
								cout << "You now have a shank.\n";
								ticker = true;
							}
							else if (choice == "b" || choice == "B")
							{
								cout << "Brushing teeth...\n";
								this_thread::sleep_for(5s);
								cout << "You now have fresh breath!\n";
								ticker = true;
							}
							else
							{
								cout << "Invalid input\n";
								cout << "To sharpen, enter S.\n";
								cout << "To brush Teeth enter B.\n";
								cout << "__________________________________\n";

							}
						}
					}
				}
				else if (PocketsInventory[i].getType() == Item_Types[3])
				{
					bool ticker = false;
					while (!ticker)
					{
							string choice;
							cout << "Would you like to throw " << PocketsInventory[i].getName() <<"?"<< endl;
							cout << "Enter Y or N.\n";
							cin >> choice;
							if (choice == "y" || choice == "Y")
							{
								cout << "You chucked a " << PocketsInventory[i].getName() << endl;
								//DiscardItem(prison, PocketsInventory[i].getName());
								ticker = true;
							}
							else if (choice == "n" || choice == "N")
							{
								cout << "I guess we will keep this in our pocket...\n";
								this_thread::sleep_for(3s);
								ticker = true;
							}
							else
							{
								cout << "Invalid input\n";
								cout << "Enter Y or N.\n";
								cout << "__________________________________\n";
							}
					}
				}
				//have to configure some sort of door to be able to use key item..
				else if (PocketsInventory[i].getType() == Item_Types[4])
				{
					cout << "We have to use this on a door....\n";
				}
				//must figure out how objective items will be used
				else if (PocketsInventory[i].getType() == Item_Types[5])
				{
					cout << "This will definitely come in handy\n";
				}
				//will create a trading / barter system
				else if (PocketsInventory[i].getType() == Item_Types[6])
				{
					cout << "I could trade this for something....\n";
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
