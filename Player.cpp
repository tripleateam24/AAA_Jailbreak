#include "Player.h"
#include "Item.h"
#include "Fighting.h"
#include "InputHandling.h"
#include <chrono>
#include <thread>
#include <cctype>
using namespace std;
Player::Player(string n) {
	name = n;
	health = 15;
	strengthModifier = 10;
}

bool Player::doesPlayerHaveItem(string item)
{
	for (int i = 0; i < PocketsInventory.size(); i++)
	{
		if (PocketsInventory[i].getName() == item)
		{
			return true;
		}
	}
	return false;
}
bool Player::doesPlayerHaveWepon(string wepon)
{
	for (int i = 0; i < PocketsInventory.size(); i++)
	{
		if (PocketsInventory[i].getName() == wepon && PocketsInventory[i].getType() == "Wepon")
		{
			return true;
		}
	}
	return false;

}
void Player::startFightBySneakAttack(Prison* prison, Player player)
{
	system("cls");
	bool cheapShot = true;
	Fighting Currentmatch;
	string ans;
	while (true) {
		cout << "Who do you want to pick a fight with?" << endl;
		prison->currentRoom->PrintPeople();
		cout << endl;
		cout << endl;
		cout << endl;
		getline(cin, ans);
		if (prison->currentRoom->SearchForPerson(ans)) {
			//cout << "You smacked fire out " << ans << endl;
			//JP3 changed arguments (OG: (prison, cheapShot, prison->currentRoom->getNPC(ans), player);)
			Currentmatch.fightScene(prison->currentRoom, cheapShot, prison->currentRoom->getNPC(ans), &player);
			//3PJ
			break;
		}
		else if (ans == "nevermind")
		{
			break;
		}
		else {
			cout << "Who? They are not in the room...." << endl;
		}

	}

}

void Player::startFightFairly(Prison* prison, Player player)
{
	bool cheapShot = true;
	Fighting Currentmatch;
	string ans;

	while (true) {
		cout << "Who do you want to pick a fight with?" << endl;
		prison->currentRoom->PrintPeople();
		getline(cin, ans);
		if (prison->currentRoom->SearchForPerson(ans)) {
			//JP3 Changed arguements (OG: (prison, cheapShot, prison->currentRoom->getNPC(ans), player);)
			Currentmatch.fightScene(prison->currentRoom, !cheapShot, prison->currentRoom->getNPC(ans), &player);
			//3PJ
			break;
		}
		else if (ans == "nevermind")
		{
			break;
		}
		else {
			cout << "Who? They are not in the room...." << endl;
		}

	}
}

void Player::PrintInstructions() {
	string answer;
	string instructions = "Here's How to Play:\nMOVE - Move rooms\n\tleft - left\n\tright - right\n\tforward - forward\n\tback - back\n"
		"\nWHERE - Check where you are in the prison\nINSPECT - Inspect the room in which you are in"
		"\nVIOLATE - Start fight by sneak attack. (Will do some damage but fight will start with oppent going first)\n"
		"\FIGHT - Start a fair fight. Randomzies who goes first.\n"
		"\nTAKEITEM - Take an item in the room\nDISCARD - Discard an item from your inventory\n"
		"INVENTORY - See what you have in your inventory\nSEARCH - look for items in a room\nTALK- Talk to person in a room\nUSEITEM - Use an item"
		"\nEXIT - Exit the game\nHELP - Print this menu again\n\n\n\n";

	cout << instructions << "\n\nPress Enter to Continue ";
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
			prison->LoseDayLight(1);
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

//absolutely need to refactor this with proper variable names 
//also add a condition that tells if they have anything to trade today
void Player::Trade(Prison* prison, string traderName) {
	string itemAnswer;
	string finalAnswer;
	NPC* trader = prison->currentRoom->getNPC(traderName);
	trader->PrintTradeTable();
	cout << "Which Item would you like to trade for? ";
	getline(cin, itemAnswer);
	if (trader->SearchForTradeItem(itemAnswer)) {
		if (HasItem(trader->ItemToGiveToTrader(itemAnswer))) {
			cout << "Give " << traderName << " " << trader->ItemToGiveToTrader(itemAnswer) << " for " << itemAnswer << "? Y/N: ";
			getline(cin, finalAnswer);
			if (finalAnswer == "Y" || finalAnswer == "y") {
				if (PocketsInventory.size() >= 2) {
					cout << "\nYou're Pockets are Already Full!\n";
				}
				else {
					for (int i = 0; i < PocketsInventory.size(); i++) {
						if (PocketsInventory[i].getName() == trader->ItemToGiveToTrader(itemAnswer)) {
							PocketsInventory.erase(PocketsInventory.begin() + i);
						}
					}
					PocketsInventory.push_back(trader->getItemFromTrader(itemAnswer));
					trader->DeleteTradeItem(itemAnswer);
				}

			}
			else {
				cout << "\nCancelling Trade.\n\n";
			}
		}
		else {
			cout << "You don't have the " << trader->ItemToGiveToTrader(itemAnswer) << " in order to make that trade!\n";
		}
	}
	else {
		cout << traderName << " does not have that item.\n";
	}

}

void Player::startFightBySneakAttack(Room* room, Player player)
{
	bool cheapShot = true;
	Fighting Currentmatch;
	string ans;

	while (true) {
		cout << "Who do you want to pick a fight with?" << endl;
		room->PrintPeople();
		getline(cin, ans);
		if (room->SearchForPerson(ans)) {
			cout << "You smacked fire out " << ans << endl;
			//JP3 added player obj
			Currentmatch.fightScene(room, cheapShot, room->getNPC(ans), &player); //check
			break;
		}
		else if (ans == "nevermind")
		{
			break;
		}
		else {
			cout << "Who? They are not in the room...." << endl;
		}

	}

}


void Player::TalkToNPC(Prison* prison) {
	string answer;
	string tradeAnswer;
	cout << "Who do you want to talk to? ";
	getline(cin, answer);
	if (prison->currentRoom->SearchForPerson(answer)) {
		cout << prison->currentRoom->getNPC(answer)->generateDialogue();

		if (prison->currentRoom->getNPC(answer)->getID() == "TRADER") {
			cout << answer << " is a Trader.\nTrade With " << prison->currentRoom->getNPC(answer)->getName() << "? Y/N: ";
			getline(cin, tradeAnswer);
			if (tradeAnswer == "Y" || tradeAnswer == "y") {
				Trade(prison, answer);
			}
		}

		prison->LoseDayLight(1);
	}
	else {
		cout << "There is no one in this room by that name.\n";
	}


}

void Player::Exercise(Prison* prison) {
	cout << "You start lifting weights....\nYou feel yourself get stronger";
	health += 2;
	strengthModifier += 2;
	prison->LoseDayLight(3);

}


void Player::InputMenu(Prison* prison, Player player) {
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
	else if (answer == "VIOLATE")
	{
		startFightBySneakAttack(prison, player);
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
	else if (answer == "EXERCISE" && prison->currentRoom->getName() == "The Gym") {
		Exercise(prison);

	}
	else if (answer == "EXIT") {
		cout << "Exiting Game...\n";
		exit(0);
	}
	else if (answer == "USEITEM") {
		//JP3: Added prison object
		manipulateItem(prison);
		//3PJ
	}
	else if (answer == "STARTFIGHT")
	{
		
		startFightFairly(prison, player);
		cout << answer;
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
void Player::setHealth(int x) {
	health = x;
}
void Player::setStrengthModifier(int x) {


	strengthModifier = x;
}

//Player can attack enemy
void Player::attack(Room* r, NPC* Opp, int temp)
{
	//choices
	string wepon;
	switch (temp)
	{
	case 5:
		cout << "You threw a left hook." << endl;
		break;
	case 6:
		cout << "You threw a right hook. " << endl;
	case 7:
		cout << "Which wepon?\n";
		PrintInventory();
		cin >> wepon;
		for (int i = 0; i < PocketsInventory.size(); i++) {
			if (PocketsInventory[i].getName() == wepon && PocketsInventory[i].getType() == "Wepon")
			{
				cout << "You swung a " << temp << " at your opponet." << endl;
				Opp->takeDamage(5);
			}

		}
	}
}




string Player::getName() const {
	return name;
}
int Player::getHealth() const {
	return health;
}
int Player::getStrengthModifier() const {
	return strengthModifier;
}

void Player::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
	}
}

// Revist
//Function allows player to maniplulate object based on type
//JP3 Added prison object
void Player::manipulateItem(Prison* prison)
//3PJ
{
	vector<string>Item_Types = { "Consumeable","Wepons","potential_Wepons","Throwable","key_Item", "objective_item", "Valuable" };
	string answer;
	cout << "Which item? \n";
	getline(cin, answer);
	string temp = clearWhiteSpaceAndCapitalize(answer);
	//check to see if the item exsit in inventory
	for (int i = 0; i < PocketsInventory.size(); i++) {
		if (PocketsInventory[i].getName() == temp) {
			if (PocketsInventory[i].getType() == Item_Types[0])
			{
				cout << "You consumed " << temp << endl;
				PocketsInventory.erase(PocketsInventory.begin() + i);
			}
			else if (PocketsInventory[i].getType() == Item_Types[1])
			{
				cout << "You swung a " << temp << endl;

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
				//JP3 removed
				//Prison* prison;
				//prison->currentRoom;
				//3PJ
				bool ticker = false;
				while (!ticker)
				{
					string choice;
					cout << "Would you like to throw " << PocketsInventory[i].getName() << "?" << endl;
					cout << "Enter Y or N.\n";
					cin >> choice;
					if (choice == "y" || choice == "Y")
					{
						cout << "You chucked a " << PocketsInventory[i].getName() << endl;
						DiscardItem(prison, PocketsInventory[i].getName());
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
				cout << "This will definitely come in handy....\n";
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

void Player::attack(Prison* prison, NPC* Opp, int temp)
{

	//choices
	string wepon;
	switch (temp)
	{
	case 5:
		cout << "You threw a left hook." << endl;
		break;
	case 6:
		cout << "You threw a right hook. " << endl;
	case 7:
		cout << "Which wepon?\n";
		PrintInventory();
		cin >> wepon;
		for (int i = 0; i < PocketsInventory.size(); i++) {
			if (PocketsInventory[i].getName() == wepon && PocketsInventory[i].getType() == "Wepon")
			{
				cout << "You swung a " << temp << " at your opponet." << endl;
				Opp->takeDamage(temp);
			}

		}
	}
}