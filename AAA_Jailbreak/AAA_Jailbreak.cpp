#include <iostream>
#include <string>

using namespace std;

//draft of room class, need to add entities, items, etc...
class Room {
	string name;
	string description;
	//we can add more stuff here later

public:
	//pointers to other rooms within a room
	//sort of like doorways
	Room* backRoom;
	Room* leftRoom;
	Room* rightRoom;
	Room* forwardRoom;

	//constructor for each room
	Room(string n, string desc, Room* bR, Room* lR, Room* rR, Room* fR) {
		name = n;
		description = desc;
		backRoom = bR;
		leftRoom = lR;
		rightRoom = rR;
		forwardRoom = fR;

	}

	//getter functions for name and description
	string getName() {
		return name;
	}
	string getDescription() {
		return description;
	}


};

//manually defining the prison temporarily -only cell and cafe currently, will add more rooms - we might want to create a better framework later

//Reminder for later: I'm pretty sure this class causes a memory leak until I create a proper destructor
class Prison {
public:
	//defining the room objects that the prison itself has
	Room* cell;
	Room* cafe;

	//this room will be the tracker for which room the player is currently in
	Room* currentRoom;

	//constructing all of the rooms in the prison
	Prison() {
		cell = new Room("Your Cell", "DESCRIPTION HERE", nullptr, nullptr, nullptr, nullptr);
		cafe = new Room("The Cafeteria", "DESCRIPTION HERE", cell, nullptr, nullptr, nullptr); //the cafe is linked to cell, so it is created with the cell as it's "back room"

		cell->leftRoom = cafe; //setting the cell's "left room" to the cafeteria

		currentRoom = cell; //setting the tracker to the cell

	}

	void PrintRoom() {
		cout << "You are Currently inside " + currentRoom->getName() << endl;
		cout << currentRoom->getDescription() << endl;
		cout << "\n\n";
	}



};

//This function asks the player for input on where to go and then moves the tracker to that room and displays the description
//If there is no pointer to another room it assumes that there is no room there and tells the player he can't go there
//this can be left on own or put in either prison class or player class down the line
void MoveRooms(Prison* prison) {
	string answer;
	cout << "Move: ";
	getline(cin, answer);
	cout << "\n";
	if ((answer == "L") || (answer == "l") || (answer == "left") || (answer == "LEFT")) {
		if (prison->currentRoom->leftRoom != nullptr) {
			prison->currentRoom = prison->currentRoom->leftRoom;
			cout << "Moving into " << prison->currentRoom->getName() << ".....\n";
			prison->PrintRoom();
		}else {
			cout << "No Room to the Left.\n";
		}
	}else if ((answer == "R") || (answer == "r") || (answer == "right") || (answer == "RIGHT")) {
		if (prison->currentRoom->rightRoom != nullptr) {
			prison->currentRoom = prison->currentRoom->rightRoom;
			cout << "Moving into " << prison->currentRoom->getName() << ".,...\n";
			prison->PrintRoom();
		}else {
			cout << "No Room to the Right.\n";
		}
	}else if ((answer == "B") || (answer == "b") || (answer == "back") || (answer == "BACK")) {
		if (prison->currentRoom->backRoom != nullptr) {
			prison->currentRoom = prison->currentRoom->backRoom;
			cout << "Moving back into " << prison->currentRoom->getName() << "....\n";
			prison->PrintRoom();
		}else {
			cout << "You are in you're cell, there is no back room here.\n";
		}
	}else if ((answer == "F") || (answer == "f") || (answer == "forward") || (answer == "FORWARD")) {
		if (prison->currentRoom->forwardRoom != nullptr) {
			prison->currentRoom = prison->currentRoom->forwardRoom;
			cout << "Moving into " << prison->currentRoom->getName() << ".....\n";
		}else {
			cout << "No Room in Front of You.\n";
		}
	}else if (answer == "EXIT") {
		cout << "Exiting...\n";
		exit(0);

	}else {
		cout << "Sorry, I don't understand what you want to do here.\n";


	}

}

int main() {
	//creating prison in main 
	Prison* prison = new Prison();
	prison->PrintRoom();

	//moving within rooms demo
	while (true) {
		MoveRooms(prison);
	}



	delete prison;


	return 0;

}