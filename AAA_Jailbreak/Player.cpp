#include "Player.h"

//player constructor
Player::Player(string n) {
	name = n;
	health = 15;
	INVENTORYSIZE = 3;
	strengthModifier = 10;
	exerciseCount = 0;
	studyCount = 0;
	intellect = 1;
	reputation = 1;
	dressedAsGuard = false;
}
  
//method for printing instructions
void Player::PrintInstructions() {
	string answer;
	string instructions = "\nHere's How to Play:\nMOVE - Move rooms\n\tleft - move left\n\tright - move right\n\tforward - move forward\n\tback - move back\n"
		"\nWHERE - Check where you are in the prison\nINSPECT - Inspect the room in which you are in"
		"\nTAKEITEM - Take an item in the room\nDISCARD - Discard an item from your inventory\nSEARCH - Search for items in a room"
		"\nTALK - Talk to someone\nINVENTORY - See what you have in your inventory\nCHECKTIME - Check the Time\n"
		"EXIT - Exit the game\nHELP - Print this menu again\n\n\n\n";
	cout << instructions << "\n\nress Enter to Continue ";
	getline(cin, answer);
	cout << "\n\n";

}

//method to take item from floor of room
void Player::TakeItem(Prison* prison, string itemName) {
	//if pockets are full - might want to increase this size to 3
	if (PocketsInventory.size() >= 2) {
		cout << "You're pockets are already full!\n";
	}
	else {
		//picking up item from the floor and removing from the room
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

//method to take item from npc - used mostly for questgivers
void Player::TakeItemFromNPC(Prison* prison, string npcName, string itemName, int questPOS) {
	if (!prison->currentRoom->getNPC(npcName)->quests[questPOS].itemsToGive.empty()) {
		PocketsInventory.push_back(prison->currentRoom->getNPC(npcName)->quests[questPOS].getItem(itemName));
		cout << "\n|" << npcName << " gives you " << prison->currentRoom->getNPC(npcName)->quests[questPOS].getItem(itemName).getName() << " in return.|\n";
	}
}

//method for discarding items by item name
void Player::DiscardItem(Prison* prison, string itemName) {
	for (int i = 0; i < PocketsInventory.size(); i++) {
		if (PocketsInventory[i].getName() == itemName) {
			cout << "Dropping " << PocketsInventory[i].getName() << " on floor of the " << prison->currentRoom->getName() << endl;
			prison->currentRoom->AddItemToRoom(PocketsInventory[i]);
			PocketsInventory.erase(PocketsInventory.begin() + i);
		}
	}


}

//if player has item this method will return true
bool Player::HasItem(string itemName) {
	for (auto item : PocketsInventory) {
		if (item.getName() == itemName) {
			return true;
		}
	}
	return false;

}

//method for trading with trader npcs
void Player::Trade(Prison* prison, string traderName) {
	string itemAnswer;
	string finalAnswer;
	//getting the trader's trading table
	prison->currentRoom->getNPC(traderName)->PrintTradeTable();
	cout << "Which Item would you like to trade for? ";
	getline(cin, itemAnswer);
	NPC* trader = prison->currentRoom->getNPC(traderName);
	//if the trader has the item entered
	if (trader->SearchForTradeItem(itemAnswer)) {
		if (HasItem(trader->ItemToGiveToTrader(itemAnswer))) { //if the player has the item to give
			cout << "Give " << traderName << " " << trader->ItemToGiveToTrader(itemAnswer) << " for " << itemAnswer << "? Y/N: ";
			getline(cin, finalAnswer);
			if (finalAnswer == "Y" || finalAnswer == "y") {
				//trading the items
				for (int i = 0; i < PocketsInventory.size(); i++) {
					if (PocketsInventory[i].getName() == trader->ItemToGiveToTrader(itemAnswer)) {
						PocketsInventory.erase(PocketsInventory.begin() + i);
					}
				}
				PocketsInventory.push_back(trader->getItemFromTrader(itemAnswer));
				trader->DeleteTradeItem(itemAnswer);
				prison->LoseDayLight(1);

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

//add in progress dialogue
void Player::TalkToNPC(Prison* prison) {
	string answer;
	string tradeAnswer;
	cout << "Who do you want to talk to? ";
	getline(cin, answer);
	if (prison->currentRoom->SearchForPerson(answer)) {
		cout << prison->currentRoom->getNPC(answer)->getGreeting();
		prison->currentRoom->getNPC(answer)->numTimesSpokenTo++;

		if (prison->currentRoom->getNPC(answer)->getID() == "TRADER") {
			cout << answer << " is a Trader.\nTrade With " << prison->currentRoom->getNPC(answer)->getName() << "? Y/N: ";
			getline(cin, tradeAnswer);
			if (tradeAnswer == "Y" || tradeAnswer == "y") {
				Trade(prison, answer);
			}
		}
		//if they are a questgiver, this will determine which dialogue to print
		if (prison->currentRoom->getNPC(answer)->getID() == "QUESTGIVER") {
			if (prison->currentRoom->getNPC(answer)->quests.size() > 0 && prison->currentRoom->getNPC(answer)->getQuestPosition() < prison->currentRoom->getNPC(answer)->quests.size()) {
				int questPOS = prison->currentRoom->getNPC(answer)->getQuestPosition();

				if (prison->currentRoom->numTimesInRoom >= 1 && prison->currentRoom->getNPC(answer)->numTimesSpokenTo > 1 && !(prison->currentRoom->getNPC(answer)->quests[questPOS].finished)) {
					prison->currentRoom->getNPC(answer)->quests[questPOS].setCondition(1);
				}

				if (prison->currentRoom->getNPC(answer)->quests[questPOS].CheckCondition() == 0) {
					cout << prison->currentRoom->getNPC(answer)->quests[questPOS].getQuestDialogue() << endl;
				}
				else if (prison->currentRoom->getNPC(answer)->quests[questPOS].CheckCondition() == 1) {
					cout << prison->currentRoom->getNPC(answer)->quests[questPOS].getInProgressDialogue() << endl;
				}
				else if (prison->currentRoom->getNPC(answer)->quests[questPOS].CheckCondition() == 2) {
					cout << prison->currentRoom->getNPC(answer)->quests[questPOS].getQuestFinishedDialogue() << endl;
					prison->currentRoom->getNPC(answer)->quests[questPOS].setCondition(3);
				}
				else {
					//do nothing
				}
			}
			else {

			}
			//check the defined quest conditions
			CheckQuestConditions(prison, answer);
		}

		prison->LoseDayLight(1);
	}
	else {
		cout << "There is no one in this room by that name.\n";
	}


}

//exercising method, can only exercise 3 times in one day
void Player::Exercise(Prison* prison) {
	if (exerciseCount < 3) {
		cout << "\nYou start lifting weights....\nYou feel yourself get stronger\n";
		health += 2;
		strengthModifier += 2;
		prison->LoseDayLight(3);
		exerciseCount++;
	}
	else {
		cout << "You feel too tired to exercise anymore.\n";
	}

}

//studying method, can only study 3 times in one day
void Player::Study(Prison* prison) {
	if (studyCount < 3) {
		//randomizing the book player reads
		string books[] = { "Botany", "Chemistry", "Physics", "Computer Science", "Architecture", "Philosophy" };
		int size = sizeof(books) / sizeof(books[0]);
		int bookChoice = rand() % size;
		cout << "You Read a book on " << books[bookChoice] << endl;
		cout << "You feel yourself get smarter.\n";
		intellect += 2;
		studyCount++;
		prison->LoseDayLight(3);
	}
	else {
		cout << "You don't feel like studying anymore.\n";
	}

}

//method for player to check time - gives general statement instead of the actual time
void Player::CheckTime(Prison* prison) {
	int time = prison->getDaylight();
	if (time <= 4) {
		cout << "\nIt's almost time for curfew.\n";
	}
	else if (time <= 7) {
		cout << "\nIt's getting late.\n";
	}
	else if (time <= 10) {
		cout << "\nIt's about mid-day.\n";
	}
	else if (time <= 13) {
		cout << "\nIt's almost mid-day.\n";
	}
	else if (time <= 18) {
		cout << "\nIt's still early.\n";
	}
	else {
		cout << "\nIt's early morning.\n";

	}

}


//might need to refactor this 
void Player::CheckQuestConditions(Prison* prison, string questGiverName) {
	string answer;
	int questPOS = prison->currentRoom->getNPC(questGiverName)->getQuestPosition();
	//start of fork's quest condition
	if (HasItem("Cookie") && prison->currentRoom->getNPC(questGiverName)->getName() == "Fork" && questPOS == 0) {
		//int questPOS = prison->currentRoom->getNPC(questGiverName)->getQuestPosition();
		cout << "Give Cookie to Fork? Y/N: ";
		getline(cin, answer);
		if (answer == "Y" || answer == "y") {
			GiveItemAway("Cookie", "Fork");
			TakeItemFromNPC(prison, "Fork", "Pills", questPOS);

		}

	}
	if (HasItem("Apple") && prison->currentRoom->getNPC(questGiverName)->getName() == "Fork" && questPOS == 1) {
		cout << "Give Apple to Fork? Y/N: ";
		getline(cin, answer);
		if (answer == "Y" || answer == "y") {
			GiveItemAway("Apple", "Fork");
			TakeItemFromNPC(prison, "Fork", "Lighter", questPOS);

		}
	}
	//end of fork's quest conditions

	//start of james's quest condition
	if (HasItem("Pills") && prison->currentRoom->getNPC(questGiverName)->getName() == "James" && questPOS == 0) {
		cout << "Give Pills to James? Y/N: ";
		getline(cin, answer);
		if (answer == "Y" || answer == "y") {
			GiveItemAway("Pills", "James");

		}
	}
	//end of james's quest condition

	//start of dan's quest conditions
	//should be rafactored but I think this will be the only quest where you can give 2 different items
	if ((HasItem("AAA Batteries") || HasItem("TV Remote")) && prison->currentRoom->getNPC(questGiverName)->getName() == "Dan" && questPOS == 0) {
		if (!HasItem("TV Remote")) {
			cout << "Give Batteries to Dan? Y/N: ";
			getline(cin, answer);
			if (answer == "Y" || answer == "y") {
				GiveItemAway("AAA Batteries", "Dan");
				TakeItemFromNPC(prison, "Dan", "Salt", questPOS);
			}
		}else if (!HasItem("AAA Batteries")) {
			cout << "Give TV Remote to Dan? Y/N: ";
			getline(cin, answer);
			if (answer == "Y" || answer == "y") {
				GiveItemAway("TV Remote", "Dan");
				TakeItemFromNPC(prison, "Fork", "Lighter", questPOS);
			}
		}else {
			cout << "(1)Give Batteries to Dan?\n";
			cout << "(2)Give TV Remote to Dan?\n";
			cout << "(3)Give nothing to Dan?\n";
			cout << "Enter Choice: ";
			getline(cin, answer);
			if (answer == "1") {
				GiveItemAway("AAA Batteries", "Dan");
				TakeItemFromNPC(prison, "Dan", "Salt", questPOS);
				answer = "Y";
			}
			else if (answer == "2") {
				GiveItemAway("TV Remote", "Dan");
				TakeItemFromNPC(prison, "Dan", "Salt", questPOS);
				answer = "Y";
			}

		}
		

	}
	if (HasItem("Phone Charger") && prison->currentRoom->getNPC(questGiverName)->getName() == "Dan" && questPOS == 1) {
		cout << "Give Phone Charger to Dan? Y/N: ";
		getline(cin, answer);
		if (answer == "Y" || answer == "y") {
			GiveItemAway("Phone Charger", "Dan");
			TakeItemFromNPC(prison, "Dan", "Radio", questPOS);

		}
	}
	
	//end of dan's quest conditions


	//start of will's quest conditions
	if (HasItem("Salt") && prison->currentRoom->getNPC(questGiverName)->getName() == "Will" && questPOS == 0) {
		cout << "Give Salt to Will? Y/N: ";
		getline(cin, answer);
		if (answer == "Y" || answer == "y") {
			GiveItemAway("Salt", "Will");
			TakeItemFromNPC(prison, "Will", "Trinket", questPOS);

		}

	}
	if (HasItem("Soda") && prison->currentRoom->getNPC(questGiverName)->getName() == "Will" && questPOS == 1) {
		cout << "Give Soda to Will? Y/N: ";
		getline(cin, answer);
		if (answer == "Y" || answer == "y") {
			GiveItemAway("Soda", "Will");

		}
	}
	//end of will's quest conditions

	//start of Bob's quest conditions
	if (HasItem("Trinket") && prison->currentRoom->getNPC(questGiverName)->getName() == "Bob" && questPOS == 0) {
		cout << "Give Trinket to Bob? Y/N: ";
		getline(cin, answer);
		if (answer == "Y" || answer == "y") {
			GiveItemAway("Trinket", "Bob");
			TakeItemFromNPC(prison, "Bob", "Permission Slip", questPOS);

		}
	}//end of Bob's quest conditions


	//start of Alex's quest conditions
	if (HasItem("Permission Slip") && prison->currentRoom->getNPC(questGiverName)->getName() == "Alex" && questPOS == 0) {
		cout << "Give Permission Slip to Alex? Y/N: ";
		getline(cin, answer);
		if (answer == "Y" || answer == "y") {
			GiveItemAway("Permission Slip", "Alex");
			prison->laundryAccess = true;
		}
	}

	if (HasItem("Radio") && prison->currentRoom->getNPC(questGiverName)->getName() == "Alex" && questPOS == 1) {
		cout << "Give Radio to Alex? Y/N: ";
		getline(cin, answer);
		if (answer == "Y" || answer == "y") {
			GiveItemAway("Radio", "Alex");
			TakeItemFromNPC(prison, "Alex", "Guards Hat", questPOS);
		}
	}
	if (HasItem("Roledex") && prison->currentRoom->getNPC(questGiverName)->getName() == "Alex" && questPOS == 2) {
		cout << "Give Roledex to Alex? Y/N: ";
		getline(cin, answer);
		if (answer == "Y" || answer == "y") {
			GiveItemAway("Roledex", "Alex");
			TakeItemFromNPC(prison, "Alex", "Guards Pants", questPOS);
		}
	}



	//end of Alex's quest conditions



	//update quests
	if (answer == "Y" || answer == "y") {
		prison->currentRoom->getNPC(questGiverName)->quests[questPOS].setCondition(2);
		prison->currentRoom->getNPC(questGiverName)->quests[questPOS].finished = true;
		cout << prison->currentRoom->getNPC(questGiverName)->quests[questPOS].getQuestFinishedDialogue();
		prison->currentRoom->getNPC(questGiverName)->IncrementQuestPosition();
	}

}




void Player::CheckDressAsGuardCondition(Prison* prison) {
	string answer;
	//laundry / guard impersonation win
	if (prison->currentRoom->SearchForItem("Guards Shirt") && prison->currentRoom->SearchForItem("Guards Shoes") && prison->currentRoom->SearchForItem("Guards Hat") && prison->currentRoom->SearchForItem("Guards Pants")) {
		cout << "Put on Guard's Uniform? Y/N: ";
		getline(cin, answer);
		if (answer == "Y" || answer == "y") {
			prison->currentRoom->RemoveItemFromRoom("Guards Shirt");
			prison->currentRoom->RemoveItemFromRoom("Guards Shoes");
			prison->currentRoom->RemoveItemFromRoom("Guards Hat");
			prison->currentRoom->RemoveItemFromRoom("Guards Pants");
			cout << "\nYou put on the guard's clothing...\nYou are now dressed as a Guard!\n";
			dressedAsGuard = true;
			prison->hallway->getNPC("Phil")->greetings = {"Hey there fellow guard, how are you?", "Nice weather today", "How's it going?", "Hello fellow guard"};
			prison->westWingHallway->getNPC("Andrew")->greetings = {"Hey there fellow guard, how are you?", "Nice weather today", "How's it going?", "Hello fellow guard"};
			prison->cafe->getNPC("James")->greetings = {"Hey man", "Hey there fellow guard, how are you?", "Nice weather today", "How's it going?", "Hello fellow guard"};
		}
		
	}
}

void Player::CheckWinCondition(Prison* prison) {
	if (prison->escaped) {
		if (prison->currentRoom->getName() == "Entrance To Prison" && dressedAsGuard) {
			cout << "YOU ESCAPED BY DRESSIING AS A GUARD!\nYOU WIN!";
		}
		

		//DisplayStats();
		exit(0);

	}
}



//giving item away to npc for quests
void Player::GiveItemAway(string itemName, string npcName) {
	for (int i = 0; i < PocketsInventory.size(); i++) {
		if (PocketsInventory[i].getName() == itemName) {
			cout << "Giving " << npcName << " " << itemName << endl;
			PocketsInventory.erase(PocketsInventory.begin() + i);
		}
	}

}
//right now this just takes the first contraband item from your iventory
//could make it take everything from your inventory but that might not be as fun
void Player::LoseItemsToGuard(Prison* prison) {
	for (int i = 0; i < PocketsInventory.size(); i++) {
		if (PocketsInventory[i].getType() == "Wepons" || PocketsInventory[i].getType() == "objective_item" || PocketsInventory[i].getType() == "key_Item" || PocketsInventory[i].getType() == "Valuable") {
			cout << "The guards also found your " << PocketsInventory[i].getName() << " on your person - They took it to the contraband closet!.\n";
			prison->contrabandCloset->AddItemToRoom(PocketsInventory[i]);
			PocketsInventory.erase(PocketsInventory.begin() + i);
		}
	}
}

bool GuessWardensCombo() {
	string answer;
	string guess;
	cout << "\nThe room is locked!\n\nThere is a 4 digit combination lock on the door from 0-9 \n";
	cout << "Try to guess? Y/N: ";
	getline(cin, answer);
	if (answer == "Y" || answer == "y") {
		cout << "0000\n";
		cout << "----\n";
		cout << "9999\n";
		cout << "Enter Combination: ";
		getline(cin, guess);
		if (guess == "5182") {
			cout << guess << endl;
			cout << "You Entered the correct combination.\n";
			return true;
		}else{
			cout << "You did not enter the correct combination.\n";
			return false;
		}
		
	}else {
		return false;
	}
}



//the player's input menu
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
		//random chance for a guard confrontation if they are in the room
		int solitaryDays;
		for (int i = 0; i < prison->currentRoom->getNumPeopleInRoom(); i++) {
			if (prison->currentRoom->getNPCByIndex(i)->getID() == "GUARD") {
				//the chance of a guard confronting the player is determined by their own suspicion level as well as players reputation
				int modifier = prison->currentRoom->getNPCByIndex(i)->getSuspicionLevel() + reputation;
				if (modifier <= 0) modifier = 5;
				int confrontationChance = rand() % modifier + 1;
				if (confrontationChance >= 9 && prison->hallway->numTimesInRoom > 1 && !dressedAsGuard) {
					//if they are confronted, they have a chance of being put into solitary
					solitaryDays = prison->currentRoom->getNPCByIndex(i)->Confront(intellect, reputation);
					if (solitaryDays > 0) {
						if (PocketsInventory.size() > 0) {
							//right now this just takes the first item from your iventory
							//could make it take everything from your inventory but that might not be as fun
							LoseItemsToGuard(prison);
						}
						
						for (int x = 0; x < solitaryDays; x++) prison->newDay();
						//resetting day
						prison->currentRoom = prison->cell;
						prison->newDay();
						resetExerciseCount();
						resetStudyCount();
						prison->SetDayLight(24);
						break;
					}
				}
				if (dressedAsGuard) {
					cout << "\nA Guard approaches you!\n";
					cout << prison->currentRoom->getNPCByIndex(i)->getGreeting() << endl;
				}

				
			}
		}
		if (prison->currentRoom->getName() == "The Warden's Office" && prison->wardensOfficeLocked) {
			if (GuessWardensCombo()) {
				cout << "You have unlocked the Warden's Office.\n";
				prison->wardensOfficeLocked = false;
			}else{
				prison->currentRoom = prison->eastWingHallway;
			}

		}
		if (prison->currentRoom->getName() == "Entrance To Prison") {
			if (dressedAsGuard) {
				cout << "\nYou walk out towards the exit of the Prison\n";
				prison->escaped = true;
			}else{
				cout << "\nYou aren't allowed to be this close to the exit.\n";
				prison->currentRoom = prison->westWingHallway;
			}
		}
		

	}
	else if (answer == "INVENTORY") {
		PrintInventory();
	}
	else if (answer == "whereami" || answer == "w" || answer == "W" || answer == "WhereAmI" || answer == "WHERE" || answer == "Where") {
		cout << "\nYou are currently standing in " << prison->currentRoom->getName() << "\n\n";
	}
	else if (answer == "inspect" || answer == "i" || answer == "I" || answer == "INSPECT") {
		cout << "\n" << prison->currentRoom->getName() << ":\n" << prison->currentRoom->getDescription() << "\n\n";
		prison->currentRoom->PrintPeople();

		if (prison->currentRoom->getName() == "The Showers" && prison->currentRoom->numTimesInRoom == 1) {
			cout << prison->currentRoom->getNPC("Seth")->getGreeting() << endl;
		}
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
	else if (answer == "FIGHT") {
		//fight
	}
	else if (answer == "EXERCISE" && prison->currentRoom->getName() == "The Gym") {
		Exercise(prison);

	}
	else if (answer == "STUDY" && prison->currentRoom->getName() == "The Common Room") {
		Study(prison);

	}else if (answer == "SLEEP" && prison->currentRoom->getName() == "Your Cell") {
		
		if (prison->getDaylight() > 12) {
			cout << "\nIt's too early to sleep now.\n";
		}else {
			cout << "You Lie down and go to sleep....\n\n";
			prison->SetDayLight(0);
		}
		


	}else if (answer == "EXIT") {

		cout << "Exiting Game...\n";
		exit(0);
	}
	else if (answer == "USEITEM") {
		manipulateItem();
	}
	else if (answer == "TIME" || answer == "CHECKTIME") {
		CheckTime(prison);
	}
	else {
		cout << "Sorry, didn't quite understand that.\n";
	}

}

//printing players inventory
void Player::PrintInventory() {
	cout << "\nYou feel around in your pockets....\n\n";
	if (PocketsInventory.empty()) cout << "You have nothing on you right now.\n";
	for (auto item : PocketsInventory) {
		cout << item.getName() << ":\n" << item.getDescription() << "\n\n";

	}



}

//setters and getters

void Player::setName(string n) {
	name = n;
}
void Player::setHealth(int x) {
	health = x;
}
void Player::setStrengthModifier(int x) {

	strengthModifier = x;
}
void Player::setIntellect(int x) {
	intellect = x;
}
void Player::setReputation(int x) {
	reputation = x;
}

void Player::resetExerciseCount() {
	exerciseCount = 0;
}

void Player::resetStudyCount() {
	studyCount = 0;

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
int Player::getIntellect() const {
	return intellect;
}
int Player::getReputationLevel() const {
	return reputation;
}



// Revist
//Function allows player to maniplulate object based on type
void Player::manipulateItem()
{
	//Prison* prison;
	vector<string>Item_Types = { "Consumeable","Wepons","potential_Wepons","Throwable","key_Item", "objective_item", "Valuable" };
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
					cout << "Would you like to throw " << PocketsInventory[i].getName() << "?" << endl;
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