#include "Prison.h"

Prison::Prison() {
	cell = new Room("Your Cell", "CELL DESCRIPTION HERE", nullptr, nullptr, nullptr, nullptr);
	cafe = new Room("The Cafeteria", "A Large cafeteria with long tables, many other prisoners sit with their food. You see a Cookie on a table next to.", cell, nullptr, nullptr, nullptr);
	hallway = new Room("The A Block Hallway", "HALLWAY DESCRIPTION HERE", cell, nullptr, nullptr, nullptr);

	gym = new Room("The Gym", "GYM DESCRIPTION HERE", cafe, nullptr, nullptr, nullptr);
	showers = new Room("The Showers", "SHOWERS DESCRIPTION HERE", cafe, nullptr, nullptr, nullptr);

	courtYard = new Room("The Court Yard", "COURTYARD DESCRIPTION HERE", hallway, nullptr, nullptr, nullptr);
	WardensOffice = new Room("The Warden's Office", "WARDEN'S OFFICE DESCRIPTION HERE", hallway, nullptr, nullptr, nullptr);

	cell->leftRoom = cafe;
	cell->rightRoom = hallway;
	cafe->leftRoom = gym;
	cafe->rightRoom = showers;
	hallway->leftRoom = courtYard;
	hallway->rightRoom = WardensOffice;

	currentRoom = cell;

	//creating items within rooms
	Item cookie("Cookie", "A large, round cookie");
	Item biscuit("Biscuit", "A biscuit");
	Item apple("Apple", "A red apple");

	cafe->AddItemToRoom(cookie);
	cafe->AddItemToRoom(biscuit);
	cafe->AddItemToRoom(apple);


}

Prison::~Prison() {
	delete cell, cafe, hallway, gym, showers, courtYard, WardensOffice;
}

void Prison::MoveRooms() {
	string answer;
	cout << "Move: ";
	getline(cin, answer);
	cout << "\n";
	if ((answer == "left") || (answer == "LEFT") || (answer == "l") || (answer == "L") || (answer == "Left")) {
		if (currentRoom->leftRoom != nullptr) {
			currentRoom = currentRoom->leftRoom;
			cout << "Moving into " << currentRoom->getName() << ".....\n";

		}
		else {
			cout << "No Room to the Left.\n";
		}
	}
	else if ((answer == "right") || (answer == "RIGHT") || (answer == "r") || (answer == "R") || (answer == "Right")) {
		if (currentRoom->rightRoom != nullptr) {
			currentRoom = currentRoom->rightRoom;
			cout << "Moving into " << currentRoom->getName() << ".....\n";

		}
		else {
			cout << "No Room to the Right.\n";
		}
	}
	else if ((answer == "back") || (answer == "BACK") || (answer == "b") || (answer == "B") || (answer == "Back")) {
		if (currentRoom->backRoom != nullptr) {
			currentRoom = currentRoom->backRoom;
			cout << "Moving into " << currentRoom->getName() << ".....\n";

		}
		else {
			cout << "You are in you're cell, there is no back room here.\n";
		}
	}
	else if ((answer == "forward") || (answer == "FORWARD") || (answer == "f") || (answer == "F") || (answer == "Forward")) {
		if (currentRoom->forwardRoom != nullptr) {
			currentRoom = currentRoom->forwardRoom;
			cout << "Moving into " << currentRoom->getName() << ".....\n";

		}
		else {
			cout << "No Room in Front of you.\n";
		}
	}
	else if (answer == "EXIT") {
		cout << "Exiting Game...\n";
		exit(0);
	}
	else {
		"Sorry, I don't understand what you want to do here.\n";
	}



}

void Prison::PrintRoom() {
	cout << "You are currently inside " << currentRoom->getName() << "\n\n\n";
}