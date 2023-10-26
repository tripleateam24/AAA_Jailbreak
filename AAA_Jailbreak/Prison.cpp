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

	//Items in Cell
	Item toothbrush("Tooth Brush", "A blue, plastic toothbrush. You can't seem to find toothpaste anywhere.", "A blue, plastic toothbrush.");
	Item razor("Razor", "A red, disposable shaving razor that's made specifically for prisoners, as they can't have normal razors blades.", "A red, disposable shaving razor");
	cell->AddItemToRoom(toothbrush);
	cell->AddItemToRoom(razor);

	//Items in cafe
	Item cookie("Cookie", "A large, round cookie", "A large, round cookie");
	Item plate("Plate", "A small, paper plate", "A small, paper plate");
	Item apple("Apple", "A red apple", "A red apple");
	cafe->AddItemToRoom(cookie);
	cafe->AddItemToRoom(plate);
	cafe->AddItemToRoom(apple);

	//Items in hallway
	Item toothpickspack("Toothpicks", "A small pack of toothpicks sitting in the corner, clearly someone must have dropped this here.", "A small pack of toothpicks");
	hallway->AddItemToRoom(toothpickspack);

	//Items in gym
	Item weight("Weight", "A 5 pound curling weight resting near a bench press.", "A 5 pound curling weight");
	gym->AddItemToRoom(weight);

	//Items in showers
	Item soap("Soap", "A small bar of soap, smells like lavender", "A small bar of soap, smells like lavender");
	Item shampoo("Shampoo Bottle", "A small shampoo bottle, barely the size of your hand. \"Peppermint Scent\" written on the back", "A small shampoo bottle, barely the size of your hand. \"Peppermint Scent\" written on the back");

	showers->AddItemToRoom(soap);
	showers->AddItemToRoom(shampoo);

	//Items in Courtyard
	Item basketball("Basketball", "An old, deflated basketball", "An old, deflated basketball");
	Item pebble("Pebble", "A small pebble lying on the ground", "A small pebble");
	courtYard->AddItemToRoom(basketball);
	courtYard->AddItemToRoom(pebble);

	//Items in Wardens Office
	Item roledex("Roledex", "The Warden's roledex, lots of phone numbers that you can't make out", "The Warden's roledex, lots of phone numbers that you can't make out");
	Item cellphone("Cellphone", "The Warden's cell phone, he still uses a flip phone.", "The Warden's cell phone, he still uses a flip phone.");
	WardensOffice->AddItemToRoom(roledex);
	WardensOffice->AddItemToRoom(cellphone);




	//adding people to rooms
	NPC fork("Fork", "You're cellmate");
	NPC bob("Bob", "Line Cook");

	cell->AddNPCToRoom(fork);

	cafe->AddNPCToRoom(bob);


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