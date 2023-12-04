#include "Fighting.h"
#include "Enemy.h"
#include "Prison.h"
#include "Player.h"
#include <iostream>
#include "Room.h"
#include <cstdlib>
#include <chrono>
#include <thread>
#include <random>
using namespace std;


//is a timer function to give the user 5 seconds to have an answer to an attack from opp
bool getTimeLimitedUserInput(int& userInput, int timeLimitSeconds) {
	thread inputThread([&userInput, timeLimitSeconds]() {
		//cout << "Enter something within " << timeLimitSeconds << " seconds: ";
		cin >> userInput;
		});

	// Wait for the specified time limit or until user input is received
	this_thread::sleep_for(chrono::seconds(timeLimitSeconds));

	if (inputThread.joinable()) {
		//cout << "Time's up! You didn't enter anything." << std::endl;
		inputThread.join();
		return false;  // Input not received in time
	}
	else {
		//cout << "You entered: " << userInput << std::endl;
		return true;  // Input received
	}
}

void printplayermoves()
{
	cout << "Moves list:" << endl;
	cout << "----------------DEFEND-------------------\n";
	cout << "*Dodge right = 1\n";
	cout << "*Dodge left = 2\n";
	cout << "*Break grapple = 3 \n";
	cout << "Step back = 4\n";
	cout << "----------------ATTACKS------------------\n";
	cout << "*Punch left = 5\n";
	cout << "*Punch right = 6\n";
	cout << "*Attack with wepon = 7\n";
}


void fist3()
{
	/*	std::cout << "███████████████████████████████████████████▓▓██████████████████████████████████████████████████████" << std::endl;
		std::cout << "████▓▓████████████████████▒▒░░░░░░▓▓████████████████████████████████████████████████████████████" << std::endl;
		std::cout << "██████████████████████████░░░░░░░░░░░░██████████████████████████████████████████████████████████" << std::endl;
		std::cout << "████████████████████████▒▒▓▓▓▓▓▓▒▒▒▒▒▒░░████████████████████████████████████████████████████████" << std::endl;
		std::cout << "████████████████████████▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒████████████████████████▓▓██████████████████████████████" << std::endl;
		std::cout << "████████████████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██████████████████████████▓▓████████████████████████████████" << std::endl;
		std::cout << "████████████████████████▓▓▓▓▒▒▓▓▓▓▓▓▓▓▒▒░░▒▒░░░░░░██████████████████▓▓██████▓▓▒▒▓▓▓▓████████████████" << std::endl;
		std::cout << "████████████████████████▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒░░██████████████████████▓▓██▓▓▓▓▓▓██████████████" << std::endl;
		std::cout << "██████████████████████░░▒▒▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░░░▓▓██████████████▒▒██████████▓▓████████████" << std::endl;
		std::cout << "██████████████████▓▓  ░░▒▒▓▓▓▓▓▓▓▓▓▓▓████████████▒▒▒▒▒▒▓▓▒▒▒▒▒▒██████████░░▒▒▓▓██████▓▓████████████" << std::endl;
		std::cout << "████████████████░░  ░░▒▒▓▓▓▓▓▓▓▓▓▓▓████████████████▓▓▓▓▓▓▒▒▓▓▒▒▒▒▓▓████░░░░▓▓▓▓▓▓██████████████████" << std::endl;
		std::cout << "████████████████    ░░  ▒▒▓▓▓▓▓▓▓▓████████▒▒██████████▓▓▓▓▓▓▓▓░░▒▒  ▒▒▒▒░░▒▒▒▒▓▓▓▓██████████████████" << std::endl;
		std::cout << "██████████████░░░░░░░░░░▒▒▒▒▒▒▓▓▒▒████▓▓░░▓▓▒▒████████████▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▒▒▒▒▒▒▓▓▓▓██▓▓██▒▒▓▓▓▓████" << std::endl;
		std::cout << "████████████░░▒▒░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒██  ▓▓▓▓▓▓▓▓▒▒▓▓▓▓▒▒▒▒▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓██▓▓▒▒    ▓▓░░▒▒▓▓░░░░░░" << std::endl;
		std::cout << "▓▓▓▓▓▓▓▓▓▓▒▒░░░░░░░░░░░░▒▒▒▒▒▒▒▒▓▓▒▒████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓██████▓▓▓▓▒▒▓▓▓▓████████████▓▓" << std::endl;
		std::cout << "████████████▒▒░░░░░░░░░░░░▒▒░░▒▒▓▓▓▓▓▓████████▓▓████████████▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒████████████████" << std::endl;
		std::cout << "██████▓▓▓▓▓▓▒▒░░░░░░░░░░░░▒▒▒▒▒▒▓▓▓▓▓▓██████████████████████░░▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒░░▒▒██████████████" << std::endl;
		std::cout << "██████▒▒▒▒▒▒▒▒▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▓▓██████████████████████████░░▒▒▒▒▒▒▓▓▒▒▓▓▒▒░░▒▒░░░░▓▓████████████" << std::endl;
		std::cout << "██████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓████████████████████████████░░▒▒▒▒▒▒▓▓▒▒▒▒▓▓▒▒▒▒▓▓▒▒░░░░████████████" << std::endl;
		std::cout << "██████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓██████████████████████████████▓▓░░▒▒▒▒▒▒▓▓▒▒▒▒▓▓▒▒████▓▓▒▒▒▒▒▒██████████" << std::endl;
		std::cout << "██████▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒██████████████████████████████░░▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒██▓▓██▒▒▒▒▒▒██████████" << std::endl;
		std::cout << "██████    ▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒████████████████████████████▒▒░░▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓██▓▓▒▒    ▓▓░░▒▒████████▓▓" << std::endl;
		std::cout << "██████▒▒▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒████████████████████████████░░░░▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▒▒▒▒▒▒████████" << std::endl;
		std::cout << "██████▒▒  ▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒██████████████████████▓▓████████▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░▒▒████████" << std::endl;
		std::cout << "██████  ░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒████████████████████████████████▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓██████" << std::endl;
		std::cout << "██████░░▓▓░░░░▒▒▓▓▓▓██████▓▓██████████████████████████████▓▓▓▓▒▒▓▓▒▒▒▒▓▓██████████▓▓▓▓▓▓▓▓████████" << std::endl;
		std::cout << "██████████████▓▓░░░░▒▒▒▒▒▒░░██████████████████████████████▓▓▓▓▓▓██████▓▓▒▒▓▓██████████████████" << std::endl;
		std::cout << "██████████████████░░░░░░░░  ░░██████████████████████████████████████▓▓████▒▒██▓▓████████████████████" << std::endl;
		this_thread::sleep_for(3s);
		system("cls");
		*/

}

void dodge1()
{
	/*
	std::cout << "⠀⠀⠀⠀⣠⣶⣶⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⣶⣦⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⢿⣿⣿⣿⠀⠀⠀⢀⣀⣠⣤⣄⠀⢿⣿⣿⣿⠇⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠈⣉⣩⣥⣶⣶⣿⣿⣿⡿⠿⠋⣀⣀⣉⣉⡁⠀⠀" << std::endl;
	std::cout << "⠀⠀⣠⣾⣿⣿⣿⣿⡟⠛⠋⠉⠀⣠⣴⣿⣿⣿⣿⣿⣿⣧⠀" << std::endl;
	std::cout << "⣴⣾⣿⣿⣿⣿⣿⣿⢁⣤⣶⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⠀" << std::endl;
	std::cout << "⠻⠿⣿⣿⣿⣿⣿⠇⠈⠻⠟⠋⠉⠁⢰⣿⣿⣿⣿⣿⣿⡿⠂" << std::endl;
	std::cout << "⠀⢠⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⢠⣿⣿⣿⣿⡏⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⣸⣿⣿⠟⣿⣿⣧⠀⠀⠀⠀⣰⣿⣿⡿⣿⣿⣷⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⣿⣿⡟⠀⠘⣿⣿⡇⠀⠀⢰⣿⣿⠟⠀⠸⣿⣿⡄⠀⠀⠀" << std::endl;
	std::cout << "⣰⣿⣿⠃⠀⠀⣿⣿⡇⠀⠀⢸⣿⣿⠀⠀⠀⢿⣿⣧⠀⠀⠀" << std::endl;
	std::cout << "⣿⣿⠇⠀⠀⠀⣿⣿⡇⠀⠀⢸⣿⣿⠀⠀⠀⠘⣿⣿⡆⠀⠀" << std::endl;
	std::cout << "⠉⠉⠀⠀⠀⠀⠈⠉⠀⠀⠀⠀⠉⠉⠀⠀⠀⠀⠈⠉⠀⠀⠀" << std::endl;
	this_thread::sleep_for(3s);
	system("cls");
	*/
}


void fist1()
{
	/*
	std::cout << "      _    ,-,    _      " << std::endl;
	std::cout << "     ,--, /: :\\/: :\\      " << std::endl;
	std::cout << "    |`;  ' `,'   `.;    `: |" << std::endl;
	std::cout << "    |    |     |  '  |     |." << std::endl;
	std::cout << "    | :  |     | pb  |     ||" << std::endl;
	std::cout << "    | :. |  :  |  :  |  :  | \\" << std::endl;
	std::cout << "     \\__/: :.. : :.. | :.. |  )" << std::endl;
	std::cout << "          `---',\\___/,\\___/ /'" << std::endl;
	std::cout << "               `==._ .. . /'" << std::endl;
	std::cout << "                    `-::-'" << std::endl;
	this_thread::sleep_for(3s);
	system("cls");
	*/
}

void fist2()
{
	
	std::cout << "  .----.-----.-----.-----." << std::endl;
	std::cout << " /      \\     \\     \\     \\" << std::endl;
	std::cout << "|  \\/    |     |   __L_____L__" << std::endl;
	std::cout << "|   |    |     |  (           \\" << std::endl;
	std::cout << "|    \\___/    /    \\______/    |" << std::endl;
	std::cout << "|        \\___/\\___/\\___/       |" << std::endl;
	std::cout << " \\      \\     /               /" << std::endl;
	std::cout << "  |                        __/" << std::endl;
	std::cout << "   \\_                   __/" << std::endl;
	std::cout << "    |        |         |" << std::endl;
	std::cout << "    |                  |" << std::endl;
	std::cout << "    |                  |" << std::endl;
	
}
void punchedInFace()
{
	
	std::cout << "                __________                  __,___/  \",\"" << std::endl;
	std::cout << "         ___.--\"          \"\\'.         ____/  l   \\    \",',-" << std::endl;
	std::cout << "  ------f\"               // \\\\\\        \\  (l\\ \\    \\     \\ \\\",\" " << endl;
	std::cout << "        |                    |||       /   u       |      \\ \\ \\" << std::endl;
	std::cout << "        |                    |||     _ )          /       | |  \\" << std::endl;
	std::cout << "    ----L_-XXX-.             .|'    / U          <        | |  |" << std::endl;
	std::cout << "                \"\\   -<_____///     \\           6 )       | |  |" << std::endl;
	std::cout << "                  \\___)     -\"       '.       -.<\"       / /   |" << std::endl;
	std::cout << "                                      |'.___  |       _._.\"   /" << std::endl;
	std::cout << "                                      |     ./     _.\".\"   _.\"" << std::endl;
	std::cout << "                                     /      |\"----\"     _.\"" << std::endl;
	std::cout << "                                  jjs       \\" << std::endl;
	this_thread::sleep_for(3s);
	system("cls");
	
}


void fatality()
{
	
	cout << " ________ ________  _________  ________  ___       ___  _________    ___    ___ \n"
		"|\\  _____\\\\   __  \\|\\___   ___\\\\   __  \\|\\  \\     |\\  \|\___   ___\\ |\\  \\  /  /|\n"
		"\\ \\  \\__/\\ \\  \\|\\  \\|___ \\  \\_\\ \\  \\|\\  \\ \\  \\    \\ \\  \\|___ \\  \\_| \\ \\  \\/  / /\n"
		" \\ \\   __\\\\ \\   __  \\   \\ \\  \\ \\ \\   __  \\ \\  \\    \\ \\  \\   \\ \\  \\  \\ \\    / / \n"
		"  \\ \\  \\_| \\ \\  \\ \\  \\   \\ \\  \\ \\ \\  \\ \\  \\ \\  \\____\\ \\  \\   \\ \\  \\  \\/  /  /  \n"
		"   \\ \\__\\   \\ \\__\\ \\__\\   \\ \\__\\ \\ \\__\\ \\__\\ \\_______\\ \\__\\   \\ \\__\\__/  / /   \n"
		"    \\|__|    \\|__|\\|__|    \\|__|  \\|__|\\|__|\\|_______|\\|__|    \\|__|\\___/ /    \n"
		"                                                                 \\|___|/      \n"
		"                                                                                \n";
		
}

void printdefenseMoves()
{
	cout << "----------------DEFEND-------------------\n";
	cout << "*Dodge right = 1\n";
	cout << "*Dodge left = 2\n";
	cout << "*Break grapple = 3 \n";
	cout << "Step back = 4\n";
}
void printAttackMoves()
{
	cout << "----------------ATTACKS------------------\n";
	cout << "*Punch left = 5\n";
	cout << "*Punch right = 6\n";
	cout << "*Attack with wepon = 7\n";
}

void fight()
{
	cout << " __ _       _     _   \n"
		"/ _(_)     | |   | |  \n"
		"| |_ _  __ _| |__ | |_ \n"
		"|  _| |/ _` | '_ \\| __|\n"
		"| | | | (_| | | | | |_ \n"
		"|_| |_|\\__, |_| |_|\\__|\n"
		"        __/ |          \n"
		"       |___/           \n";
}
//JP3 added Player object
void Fighting::fightScene(Room* room, bool cheapShot, NPC* Opp, Player* player)
//3PJ
{
	
	string wepon;
	int AIturn;
	int userDefense;
	int ans;
	//JP3: removed
	//Player* player;
	//3PJ
	int turn = -1;
	//When turn is 2 its the Enemies turn. 

	//When turn is 1 its the players turn.

	//if a player tries to use a cheapshot then its automatically the computers turn
	if (cheapShot)
	{
		system("cls");
		cout << "You smacked the FIRE out " << Opp->getName() << endl;
		this_thread::sleep_for(3s);
		system("cls");
		cout << "Be prepared to stand on BIDNESS" << endl;
		this_thread::sleep_for(3s);
		system("cls");
		fight();
		this_thread::sleep_for(3s);
		system("cls");
		this_thread::sleep_for(3s);
		turn = 2;
		while (player->getHealth() != 0 && Opp->getHealth() != 0)
		{
			//Since cheapshot is true, the computer gets to start

			if (turn == 1)
			{
				system("cls");
				cout << "What attack will you choose?\n";
				printAttackMoves();
				cin >> ans;
				//player->attack(room, Opp, ans);
				fist1();
				switch (ans)
				{
				case 5:
					cout << "You threw a left hook." << endl;
					cout << endl;
					cout << endl;
					fist2();
					this_thread::sleep_for(3s);
					system("cls");
					//create a random number between 4-7. if the ai guesses 6, then the attack will be blocked
					srand(time(0));
					AIturn = rand() % 4 + 4;
					if (AIturn == ans)
					{
						cout << "Your attack was dodged...Its his turn to counter.\n";
						this_thread::sleep_for(2s);
						dodge1();
						turn = 2;
						system("cls");
					}
					else
					{
						cout << "Your attack connected!!!!!!!\n";
						punchedInFace();
						this_thread::sleep_for(3s);
						system("cls");
						//JP3 Removed paramter (OG: (room,4))
						Opp->takeDamage(player->getStrengthModifier());
						//3PJ
						cout << Opp->getName() << "Current health: " << Opp->getHealth();
						this_thread::sleep_for(3s);
						system("cls");
						turn = 2;
					}
					break;
				case 6:
					cout << "You threw a right hook. " << endl;
					fist2();
					this_thread::sleep_for(3s);
					system("cls");
					//create a random number between 5-10. if the ai guesses 6, then the attack will be blocked
					srand(time(0));
					AIturn = rand() % 6 + 5;
					if (AIturn == ans)
					{
						cout << "Your attack was dodged...Its his turn to counter.\n";
						dodge1();
						this_thread::sleep_for(3s);
						system("cls");
						turn = 2;
					}
					else
					{
						cout << "Your attack connected!!!!!!!\n";
						punchedInFace();
						this_thread::sleep_for(3s);
						system("cls");
						//JP3 Removed paramter (OG: (room,4))
						Opp->takeDamage(4);
						//3PJ
						cout << Opp->getName() << "Current health: " << Opp->getHealth();
						//fist2();
						this_thread::sleep_for(3s);
						system("cls");
						turn = 2;
					}
					break;
					//Attacking with Wepon
				case 7:
					system("cls");
					//create a random number between 4 and 7. if the ai guesses 7, then the attack will be blocked
					cout << "Which wepon?\n";
					cout << endl;
					cout << endl;
					cin >> wepon;
					cout << endl;
					if (player->doesPlayerHaveWepon(wepon))
					{

						cout << "You swung a " << wepon << " at your opponet." << endl;
						Opp->takeDamage(6);
						cout << Opp->getName() << "Current health: " << Opp->getHealth();
						this_thread::sleep_for(3s);
						system("cls");
						srand(time(0));
						AIturn = rand() % 4 + 4;
						if (AIturn == 7)
						{
							cout << "Your attack was dodged...Its his turn to counter.\n";
							dodge1();
							this_thread::sleep_for(3s);
							turn = 2;
							system("cls");
						}
						else
						{

							cout << "Your attack connected!!!!!!!\n";
							//Take away HP
							//JP3 Removed paramter (OG: (room,7))
							Opp->takeDamage(7);
							//3PJ
							//Update player on Enemy health
							cout << endl;
							cout << endl;
							cout << Opp->getName() << "Current health: " << Opp->getHealth();
							this_thread::sleep_for(3s);
							system("cls");
							//display graphic
							fist1();
							this_thread::sleep_for(3s);
							turn = 2;
							system("cls");

						}

					}
					else
					{
						turn = 2;
						this_thread::sleep_for(3s);
						cout << "You dont have this item, theres consequences for pump faking..." << endl;
						this_thread::sleep_for(3s);
						//turn = 2;
						system("cls");

					}

					break;


				}

			}
			else if (turn == 2)
			{
				//get a random number for opp attack
				mt19937 gen(time(0));

				// Define the distribution for random numbers between 5 and 7
				uniform_int_distribution<> dis(5, 7);

				// Generate a random number
				AIturn = dis(gen);
				//opp choices
				switch (AIturn)
				{
				case 5:
					userDefense;
					cout << endl;
					cout << endl;
					system("cls");
					//give user 5 seconds to come up with a response
					cout << Opp->getName() << " threw a right hook at you! Act fast!\n";
					cout << endl;
					cout << "Choose your defense!!!\n";
					printdefenseMoves();
					cin >> userDefense;

					if (userDefense == 1)
					{
						cout << "That was close! Good job dodging\n";
						this_thread::sleep_for(3s);
						turn = 1;
						system("cls");

					}
					else
					{
						cout << "Damn you got rocked! shake it off and get back in this!\n";
						player->takeDamage(Opp->getStrength());
						cout << "Your health: " << player->getHealth() << endl;
						fist3();
						this_thread::sleep_for(3s);
						turn = 1;
						system("cls");

					}


					break;
				case 6:
					userDefense;
					system("cls");
					//give user 5 seconds to come up with a response
					cout << Opp->getName() << " threw a left hook at you! Act fast!\n";
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "Choose your defense!!!\n";
					printdefenseMoves();
					cin >> userDefense;


					if (userDefense == 2)
					{
						cout << "That was close! Good job dodging\n";
						this_thread::sleep_for(3s);
						turn = 1;
						system("cls");

					}
					else
					{
						cout << "Damn you got rocked! shake it off and get back in this!\n";
						player->takeDamage(Opp->getStrength());
						cout << "Your health: " << player->getHealth() << endl;
						fist3();
						this_thread::sleep_for(3s);
						turn = 1;
						system("cls");

					}


					break;

					//For grab attacks, you must be 2 strength points above your opponet to sucessfully break the hold or else
					//He will drop you on your head
					//You have a 50 percent chance of countering with a right hook when breaking the hold
					//If this happens you may attack him again.

				case 7:
					system("cls");
					cout << endl;
					cout << endl;
					cout << endl;
					//give user 5 seconds to come up with a response
					cout << Opp->getName() << " Grabbed you! He's strong! Be careful!!\n";
					cout << endl;
					cout << "Choose your defense!!!\n";
					printdefenseMoves();
					cin >> userDefense;


					if (userDefense == 1 && player->getStrengthModifier() > Opp->getStrength() + 2)
					{

						srand(time(0));
						int randomCounterAttack = rand() % 2;
						if (randomCounterAttack == 1)
						{
							system("cls");
							cout << "You broke the hold and countered with a left hook! Youve got this!\n";
							//JP3 Removed paramter (OG: (room,2))
							Opp->takeDamage(2);
							//3PJ
							cout << endl;
							cout << Opp->getName() << "Current health: " << Opp->getHealth() << endl;
							this_thread::sleep_for(3s);
							turn = 1;
							system("cls");



						}
						else
						{
							system("cls");
							cout << "You broke the hold! Youve got this!\n";
							//find a acsii image
							this_thread::sleep_for(3s);
							turn = 1;
							system("cls");


						}
					}
					else
					{
						system("cls");
						cout << "He just slammed you on the ground and your body bounced off the floor like a basketball.\n";
						cout << endl;
						cout << "The sound of flesh rings through your ears...." << endl;
						player->takeDamage(Opp->getStrength());
						cout << "Your health: " << player->getHealth() << endl;
						fist3();
						this_thread::sleep_for(3s);
						turn = 1;
						system("cls");

					}


					break;
				}


			}

		}

		if (player->getHealth() <= 0)
		{
			system("cls");
			fatality();
			this_thread::sleep_for(3s);
			system("cls");
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "GAME OVER YOU DIED\n";
			exit(0);
		}
		else if (Opp->getHealth() <= 0)
		{

			system("cls");
			fatality();
			this_thread::sleep_for(3s);
			system("cls");
			room->AddItemToRoom(Opp->dropLoot());
			room->RemoveNPCFromRoom(Opp->getName());
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "You won!\n";
			this_thread::sleep_for(5s);
			system("cls");

		}


	}
	else
	{



		//fair fight if you didnt sneak attack
		cout << "Get ready to fight!!" << endl;
		cout << "-----------------------------------------------------------\n";
		this_thread::sleep_for(3s);
		system("cls");
		cout << "Remeber, keep your hands up...dont let them grab you." << endl;
		this_thread::sleep_for(3s);
		system("cls");
		printplayermoves();
		turn = rand() % 2 + 1;
		while (player->getHealth() != 0 && Opp->getHealth() != 0)
		{
			//Since cheapshot is true, the computer gets to start

			if (turn == 1)
			{
				system("cls");
				cout << "What attack will you choose?\n";
				printAttackMoves();
				cin >> ans;
				//player->attack(room, Opp, ans);
				fist1();
				switch (ans)
				{
				case 5:
					cout << "You threw a left hook." << endl;
					cout << endl;
					cout << endl;
					fist2();
					this_thread::sleep_for(3s);
					system("cls");
					//create a random number between 4-7. if the ai guesses 6, then the attack will be blocked
					srand(time(0));
					AIturn = rand() % 4 + 4;
					if (AIturn == ans)
					{
						cout << "Your attack was dodged...Its his turn to counter.\n";
						this_thread::sleep_for(2s);
						dodge1();
						turn = 2;
						system("cls");
					}
					else
					{
						cout << "Your attack connected!!!!!!!\n";
						punchedInFace();
						this_thread::sleep_for(3s);
						system("cls");
						//JP3 Removed paramter (OG: (room,4))
						Opp->takeDamage(player->getStrengthModifier());
						//3PJ
						cout << Opp->getName() << "Current health: " << Opp->getHealth();
						this_thread::sleep_for(3s);
						system("cls");
						turn = 2;
					}
					break;
				case 6:
					cout << "You threw a right hook. " << endl;
					fist2();
					this_thread::sleep_for(3s);
					system("cls");
					//create a random number between 5-10. if the ai guesses 6, then the attack will be blocked
					srand(time(0));
					AIturn = rand() % 6 + 5;
					if (AIturn == ans)
					{
						cout << "Your attack was dodged...Its his turn to counter.\n";
						dodge1();
						this_thread::sleep_for(3s);
						system("cls");
						turn = 2;
					}
					else
					{
						cout << "Your attack connected!!!!!!!\n";
						punchedInFace();
						this_thread::sleep_for(3s);
						system("cls");
						//JP3 Removed paramter (OG: (room,4))
						Opp->takeDamage(4);
						//3PJ
						cout << Opp->getName() << "Current health: " << Opp->getHealth();
						//fist2();
						this_thread::sleep_for(3s);
						system("cls");
						turn = 2;
					}
					break;
					//Attacking with Wepon
				case 7:
					system("cls");
					//create a random number between 4 and 7. if the ai guesses 7, then the attack will be blocked
					cout << "Which wepon?\n";
					cout << endl;
					cout << endl;
					cin >> wepon;
					cout << endl;
					if (player->doesPlayerHaveWepon(wepon))
					{

						cout << "You swung a " << wepon << " at your opponet." << endl;
						Opp->takeDamage(6);
						cout << Opp->getName() << "Current health: " << Opp->getHealth();
						this_thread::sleep_for(3s);
						system("cls");
						srand(time(0));
						AIturn = rand() % 4 + 4;
						if (AIturn == 7)
						{
							cout << "Your attack was dodged...Its his turn to counter.\n";
							dodge1();
							this_thread::sleep_for(3s);
							turn = 2;
							system("cls");
						}
						else
						{

							cout << "Your attack connected!!!!!!!\n";
							//Take away HP
							//JP3 Removed paramter (OG: (room,7))
							Opp->takeDamage(7);
							//3PJ
							//Update player on Enemy health
							cout << endl;
							cout << endl;
							cout << Opp->getName() << "Current health: " << Opp->getHealth();
							this_thread::sleep_for(3s);
							system("cls");
							//display graphic
							fist1();
							this_thread::sleep_for(3s);
							turn = 2;
							system("cls");

						}

					}
					else
					{
						turn = 2;
						this_thread::sleep_for(3s);
						cout << "You dont have this item, theres consequences for pump faking..." << endl;
						this_thread::sleep_for(3s);
						//turn = 2;
						system("cls");

					}

					break;


				}

			}
			else if (turn == 2)
			{
				//get a random number for opp attack
				mt19937 gen(time(0));

				// Define the distribution for random numbers between 5 and 7
				uniform_int_distribution<> dis(5, 7);

				// Generate a random number
				AIturn = dis(gen);
				//opp choices
				switch (AIturn)
				{
				case 5:
					userDefense;
					cout << endl;
					cout << endl;
					system("cls");
					//give user 5 seconds to come up with a response
					cout << Opp->getName() << " threw a right hook at you! Act fast!\n";
					cout << endl;
					cout << "Choose your defense!!!\n";
					printdefenseMoves();
					cin >> userDefense;

					if (userDefense == 1)
					{
						cout << "That was close! Good job dodging\n";
						this_thread::sleep_for(3s);
						turn = 1;
						system("cls");

					}
					else
					{
						cout << "Damn you got rocked! shake it off and get back in this!\n";
						player->takeDamage(Opp->getStrength());
						cout << "Your health: " << player->getHealth() << endl;
						fist3();
						this_thread::sleep_for(3s);
						turn = 1;
						system("cls");

					}


					break;
				case 6:
					userDefense;
					system("cls");
					//give user 5 seconds to come up with a response
					cout << Opp->getName() << " threw a left hook at you! Act fast!\n";
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "Choose your defense!!!\n";
					printdefenseMoves();
					cin >> userDefense;


					if (userDefense == 2)
					{
						cout << "That was close! Good job dodging\n";
						this_thread::sleep_for(3s);
						turn = 1;
						system("cls");

					}
					else
					{
						cout << "Damn you got rocked! shake it off and get back in this!\n";
						player->takeDamage(Opp->getStrength());
						cout << "Your health: " << player->getHealth() << endl;
						fist3();
						this_thread::sleep_for(3s);
						turn = 1;
						system("cls");

					}


					break;

					//For grab attacks, you must be 2 strength points above your opponet to sucessfully break the hold or else
					//He will drop you on your head
					//You have a 50 percent chance of countering with a right hook when breaking the hold
					//If this happens you may attack him again.

				case 7:
					system("cls");
					cout << endl;
					cout << endl;
					cout << endl;
					//give user 5 seconds to come up with a response
					cout << Opp->getName() << " Grabbed you! He's strong! Be careful!!\n";
					cout << endl;
					cout << "Choose your defense!!!\n";
					printdefenseMoves();
					cin >> userDefense;


					if (userDefense == 1 && player->getStrengthModifier() > Opp->getStrength() + 2)
					{

						srand(time(0));
						int randomCounterAttack = rand() % 2;
						if (randomCounterAttack == 1)
						{
							system("cls");
							cout << "You broke the hold and countered with a left hook! Youve got this!\n";
							//JP3 Removed paramter (OG: (room,2))
							Opp->takeDamage(2);
							//3PJ
							cout << endl;
							cout << Opp->getName() << "Current health: " << Opp->getHealth() << endl;
							this_thread::sleep_for(3s);
							turn = 1;
							system("cls");



						}
						else
						{
							system("cls");
							cout << "You broke the hold! Youve got this!\n";
							//find a acsii image
							this_thread::sleep_for(3s);
							turn = 1;
							system("cls");


						}
					}
					else
					{
						system("cls");
						cout << "He just slammed you on the ground and your body bounced off the floor like a basketball.\n";
						cout << endl;
						cout << "The sound of flesh rings through your ears...." << endl;
						player->takeDamage(Opp->getStrength());
						cout << "Your health: " << player->getHealth() << endl;
						fist3();
						this_thread::sleep_for(3s);
						turn = 1;
						system("cls");

					}
					break;
				}


			}

		}

		if (player->getHealth() <= 0)
		{
			system("cls");
			fatality();
			this_thread::sleep_for(3s);
			system("cls");
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "GAME OVER YOU DIED\n";
			exit(0);
		}
		else if (Opp->getHealth() <= 0)
		{
			system("cls");
			fatality();
			this_thread::sleep_for(3s);
			system("cls");
			room->AddItemToRoom(Opp->dropLoot());
			room->RemoveNPCFromRoom(Opp->getName());
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "You won!\n";
			this_thread::sleep_for(5s);
			system("cls");

		}
	}
}


//ASCII images to spice up the fight scenes
