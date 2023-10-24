#include "Prison.h"

//manually creating rooms in the prison

//constructing all of the rooms in the prison
Prison::Prison() {
	cell = new Room("Your Cell", "CELL DESCRIPTION HERE", nullptr, nullptr, nullptr, nullptr);
	cafe = new Room("The Cafeteria", "CAFE DESCRIPTION HERE", cell, nullptr, nullptr, nullptr); //the cafe is linked to cell, so it is created with the cell as it's "back room"
	hallway = new Room("The A block Hallway", "HALLWAY DESCRIPTION HERE", cell, nullptr, nullptr, nullptr);

	gym = new Room("The Gym", "GYM DESCRIPTION HERE", cafe, nullptr, nullptr, nullptr);
	showers = new Room("The Showers", "SHOWERS DESCRIPTION HERE", cafe, nullptr, nullptr, nullptr);

	courtYard = new Room("The Court Yard", "COURTYARD DESCRIPTION HERE", hallway, nullptr, nullptr, nullptr);
	WardensOffice = new Room("The Warden's Office", "WARDENS OFFICE DESCRIPTION HERE", hallway, nullptr, nullptr, nullptr);

	cell->leftRoom = cafe;
	cell->rightRoom = hallway;
	cafe->leftRoom = gym;									//here we are creating the map and layout for every room
	cafe->rightRoom = showers;
	hallway->leftRoom = courtYard;
	hallway->rightRoom = WardensOffice;


	currentRoom = cell; //setting the tracker to the cell

}

//attempt at a proper destructor
Prison::~Prison() {
	delete cell, cafe, hallway, gym, showers, courtYard, WardensOffice;
}

//prints the room the payer is standing in
void Prison::PrintRoom() {
	cout << "You are Currently inside " + currentRoom->getName() << endl;
	cout << currentRoom->getDescription() << endl;
	cout << "\n\n";
}





