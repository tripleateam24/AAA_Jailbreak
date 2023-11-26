#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Prison.h"
#include "NPC.h"
#include "Player.h"
#include "Item.h"



void PrintBackStory() { // backstory function. Can call it when the user inputs "story"

	//backstory
	string backStory;
	backStory = "In the realm of tax consulting, you're a shining star, renowned for your prowess in deciphering the complex labyrinth of tax codes."
		" Your standing in the community is unblemished, but fate takes a dark turn when your neighbor, burdened by his ailing wife's medical bills,"
		"approaches you with a drastic proposal: to dance on the edge of legality and commit tax fraud. "
		"Brimming with integrity, you bravely decline, opting for the high road.Undeterred, your neighbor ventures forth, successfully securing the much"
		"- needed loan.However, this triumph is short - lived as the IRS sniffs out irregularities and turns the spotlight on him. Cornered, he deflects attention,"
		"naming you as his trusted tax advisor, leaving you in the crosshairs. Soon, you're summoned for a gripping interrogation, the gravity of the situation "
		"hanging heavy in the air. The legal battle that ensues is nothing short of a high-stakes drama, where your attempts to set the record straight fall on deaf ears."
		"Against all odds, you find yourself on a rollercoaster ride through the justice system, ultimately facing a daunting 15-year sentence in a federal prison. "
		"The tale of your unwavering moral compass and the fight for justice paints a riveting portrait of an unexpected journey through the twists and turns of the law. \n\n\n";
	cout << backStory;
}



//This function asks the player for input on where to go and then moves the tracker to that room and displays the description
//If there is no pointer to another room it assumes that there is no room there and tells the player he can't go there
//this can be left on own or put in either prison class or player class down the line
void MoveRooms(Prison* prison) {
	string answer;
	std::cout << "Your Move: ";
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

	}
	else if (answer == "story") {
		cout << "\n";
		PrintBackStory();
	}

	else{
		cout << "Sorry, I don't understand what you want to do here.\n";


	}

}


int main() {

	//Displaying Game title
	cout << "\t\t\t\t\t\t-------Jailbreak-------\n";
	Player player("Prisoner Name");
	player.PrintInstructions();

	//displaying backstory
	PrintBackStory();
	//Displaying game objective
	cout << endl << "Game Objective: Go through different tasks to escape the prison in the shortest amount of days possible."
		"You will have items and people to help you get out along the way.   \n";
	cout << "Type 'story' to see the backstory again.\n";
	cout << "Type 'start' to continue the game" << endl;


	string userInput;
	while (true) {
		getline(cin, userInput);
		if (userInput == "story") {
			PrintBackStory();
		}
		else if (userInput == "start")
		{
			break;
			// when the user enters start the game will start.  
		}
		// user can now redisplay story. 
	}

	Player player1 = Player("Mr. Prisoner");

	Prison* prison = new Prison();


	NPC* npc = new NPC("Fork","Cell Mate");


	string testinput;
	//moving within rooms demo
	while (true) {
		player1.InputMenu(prison, player1);
		if (prison->getDaylight() <= 0) {
			cout << "\nDay's Over....Lights Out!\n\n\n";
			prison->currentRoom = prison->cell;
			prison->SetDayLight(20);
			prison->newDay();

		}
		
	}
	
		MoveRooms(prison); 

	/*
		if (prison->currentRoom->getName() == "Your Cell") // if statement to ensure fork can only be "prompted" in cell
		{
			npc->talkToPlayer();
			cout << npc->generateGreetingDialogue() << endl;
			this_thread::sleep_for(5s); //a way to delay outputs useful for outputting multiple lines of dialogue over time 
			cout << npc->generateDialogue() << endl;
		}
	*/ 

	delete prison;

	return 0;

}