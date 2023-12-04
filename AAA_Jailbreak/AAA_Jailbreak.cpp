#include <iostream>
#include <string>
#include "Player.h"

using namespace std;


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



int main() {
	int daysUntilInspection = 5;
	//Displaying Game title
	cout << "-------Jailbreak-------\n";
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

	player1.PrintInstructions();

	//main game loop
	while (true) {
		player1.InputMenu(prison);
		player1.CheckDressAsGuardCondition(prison);
		player1.CheckWinCondition(prison);
		if (prison->getDaylight() <= 0 && !player1.dressedAsGuard) {
			//resetting day
			cout << "\n\nDay's Over....You walk back to your cell and go to sleep....Lights Out!\n\nYou Wake Up bright and early the next day.\n\n";
			prison->currentRoom = prison->cell;
			prison->SetDayLight(24);
			prison->newDay();
			player1.resetExerciseCount();
			player1.resetStudyCount();
			prison->RefreshTraderTables();

			daysUntilInspection--;
		}
		
		//once every 5 - 10 days a random inspection will occur
		if (daysUntilInspection == 0 && prison->getDay() != 0 && prison->getDaylight() == 24) {
			prison->Inspection();
			player1.LoseItemsToGuard(prison);
			prison->LoseDayLight(1);
			daysUntilInspection = rand() % 6 + 5;
		}


		
	}

	cout << "You spent " << prison->getDay() << " days in jail.\n";


	delete prison;


	return 0;

}