#include <iostream>
#include <string>
#include "Prison.h"

using namespace std;


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

	}else if(answer == "whereami" || answer == "w" || answer == "W" || answer == "where") {
		cout << "You are currently standing in " << prison->currentRoom->getName() << "\n\n";

	}
	else if (answer == "inspect" || answer == "i" || answer == "I") {
		cout << prison->currentRoom->getDescription() << "\n\n";

	}else{
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