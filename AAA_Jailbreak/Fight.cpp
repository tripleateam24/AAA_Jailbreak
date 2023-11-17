#include "Fight.h"
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
	/*
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
	this_thread::sleep_for(3s);
	system("cls");
	*/
}
void punchedInFace()
{
	/*
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
	*/
}


void fatality()
{
	/*
	cout << " ________ ________  _________  ________  ___       ___  _________    ___    ___ \n"
		"|\\  _____\\\\   __  \\|\\___   ___\\\\   __  \\|\\  \\     |\\  \|\___   ___\\ |\\  \\  /  /|\n"
		"\\ \\  \\__/\\ \\  \\|\\  \\|___ \\  \\_\\ \\  \\|\\  \\ \\  \\    \\ \\  \\|___ \\  \\_| \\ \\  \\/  / /\n"
		" \\ \\   __\\\\ \\   __  \\   \\ \\  \\ \\ \\   __  \\ \\  \\    \\ \\  \\   \\ \\  \\  \\ \\    / / \n"
		"  \\ \\  \\_| \\ \\  \\ \\  \\   \\ \\  \\ \\ \\  \\ \\  \\ \\  \\____\\ \\  \\   \\ \\  \\  \\/  /  /  \n"
		"   \\ \\__\\   \\ \\__\\ \\__\\   \\ \\__\\ \\ \\__\\ \\__\\ \\_______\\ \\__\\   \\ \\__\\__/  / /   \n"
		"    \\|__|    \\|__|\\|__|    \\|__|  \\|__|\\|__|\\|_______|\\|__|    \\|__|\\___/ /    \n"
		"                                                                 \\|___|/      \n"
		"                                                                                \n";
		*/
}
void fight::fightScene(Room* room, bool cheapShot, NPC* Opp)
{
	int AIturn;
	int userDefense;
	int ans;
	Player* player;
	int turn = -1;
	//When turn is 2 its the Enemies turn. 
	
	//When turn is 1 its the players turn.
	
	//if a player tries to use a cheapshot then its automatically the computers turn
	if (cheapShot)
	{
		
		while(player->getHealth() != 0 && Opp->getHealth() != 0)
		{
			//Since cheapshot is true, the computer gets to start
			turn = 2;
			if (turn == 1)
			{
				cout << "What attack will you choose?\n";
				printplayermoves();
				cin >> ans;
				player->attack(room, Opp, ans);
				fist1();
				switch (ans)
				{
				case 5:
					//create a random number between 5-10. if the ai guesses 6, then the attack will be blocked
					srand(time(0));
				     AIturn = rand() % 6 + 5;
					if (AIturn == ans)
					{
						cout << "Your attack was dodged...Its his turn to counter.\n";
						this_thread::sleep_for(2s);
						dodge1();
						turn = 2;
					}
					else
					{
						cout << "Your attack connected!!!!!!!\n";
						Opp->takeDamage(room, 4);
						cout << Opp->getName() << "Current health: " << Opp->getHealth();
						punchedInFace();
						turn = 2;
					}
					break;
				case 6:
					//create a random number between 5-10. if the ai guesses 6, then the attack will be blocked
					srand(time(0));
				     AIturn = rand() % 6 + 5;
					if (AIturn == ans)
					{
						cout << "Your attack was dodged...Its his turn to counter.\n";
						dodge1();
						turn = 2;
					}
					else
					{
						cout << "Your attack connected!!!!!!!\n";
						Opp->takeDamage(room, 4);
						cout << Opp->getName() << "Current health: " << Opp->getHealth();
						fist2();
						turn = 2;
					}
					break;
					//Attacking with Wepon
				case 7:
					//create a random number between 5-11. if the ai guesses 7, then the attack will be blocked
					srand(time(0));
					 AIturn = rand() % 7 + 5;
					if (AIturn == ans)
					{
						cout << "Your attack was dodged...Its his turn to counter.\n";
						dodge1();
						turn = 2;
					}
					else
					{
						cout << "Your attack connected!!!!!!!\n";
						//Take away HP
						Opp->takeDamage(room, 7);
						//Update player on Enemy health
						cout << Opp->getName() << "Current health: " << Opp->getHealth();
						//display graphic
						fist1();
						turn = 2;
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
					//give user 5 seconds to come up with a response
					cout << Opp->getName() << " threw a right hook at you! Act fast!\n";
					cout << endl;
					cout << "Choose your defense!!!\n";
					
					printplayermoves();
					if (getTimeLimitedUserInput(userDefense, 5))
					{
						if (userDefense == 1)
						{
							cout << "That was close! Good job dodging\n";
							turn = 1;
						}
						else
						{
							cout << "Damn you got rocked! shake it off and get back in this!\n";
							player->takeDamage(Opp->getStrength());
							cout << "Your health: " << player->getHealth();
							fist3();
							turn = 1;
						}

					}
					else
					{
						cout << "Damn you got rocked! Shake it off and get back in this!\n";
						player->takeDamage(Opp->getStrength());
						cout << "Your health: " << player->getHealth();
						fist3();
						turn = 1;
					}
					break;
				case 6:
					 userDefense;
					//give user 5 seconds to come up with a response
					cout << Opp->getName() << " threw a left hook at you! Act fast!\n";
					cout << endl;
					cout << "Choose your defense!!!\n";
					printplayermoves();
					if (getTimeLimitedUserInput(userDefense, 5))
					{
						if (userDefense == 2)
						{
							cout << "That was close! Good job dodging\n";
							turn = 1;
						}
						else
						{
							cout << "Damn you got rocked! shake it off and get back in this!\n";
							player->takeDamage(Opp->getStrength());
							cout << "Your health: " << player->getHealth();
							fist3();
							turn = 1;
						}

					}
					else
					{
						cout << "Damn you got rocked! Shake it off and get back in this!\n";
						player->takeDamage(Opp->getStrength());
						cout << "Your health: " << player->getHealth();
						fist3();
						turn = 1;
					}
					break;

					//For grab attacks, you must be 2 strength points above your opponet to sucessfully break the hold or else
					//He will drop you on your head
					//You have a 50 percent chance of countering with a right hook when breaking the hold
					//If this happens you may attack him again.

				case 7:
				 
					//give user 5 seconds to come up with a response
					cout << Opp->getName() << "Grabbed you! He's strong! Be careful!!\n";
					cout << endl;
					cout << "Choose your defense!!!\n";
					printplayermoves();
					if (getTimeLimitedUserInput(userDefense, 5))
					{
						if (userDefense == 1 && player->getStrengthModifier() > Opp->getStrength() + 2)
						{

							srand(time(0));
							int randomCounterAttack = rand() % 2;
							if (randomCounterAttack == 1)
							{
								cout << "You broke the hold and countered with a left hook! Youve got this!\n";
								Opp->takeDamage(room, 2);
								cout << endl;
								cout << Opp->getName() << "Current health: " << Opp->getHealth();
								turn = 1;


							}
							else
							{
								cout << "You broke the hold! Youve got this!\n";
								//find a acsii image
								turn = 1;

							}
						}
						else
						{
							cout << "He just slammed you on the ground and your body bounced off the floor like a basketball.\n";
							cout << endl;
							cout << "The sound of flesh rings through your ears...." << endl;
							player->takeDamage(Opp->getStrength());
							cout << "Your health: " << player->getHealth();
							fist3();
							turn = 1;
						}

					}
					else
					{
						cout << "He just slammed you on the ground and your body bounced off the floor like a basketball.\n";
						cout << endl;
						cout << "The sound of flesh rings through your ears." << endl;
						player->takeDamage(Opp->getStrength() + 2);
						cout << "Your health: " << player->getHealth();
						fist3();
						turn = 1;
					}
					break;
				}


			}



		}
		if (player->getHealth() <= 0)
		{
			fatality();
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "GAME OVER YOU DIED\n";
			exit(0);
		}
		else if (Opp->getHealth() <= 0)
		{
			fatality();
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "You won!\n";
			cout << endl;
			
			

		}
		
	}
	else
	{
		//fair fight if you didnt sneak attack
		cout << "Get ready to fight!!" << endl;
		cout << "-----------------------------------------------------------\n";
		printplayermoves();
		while (player->getHealth() != 0 || Opp->getHealth() != 0) 
		{
			//decide who is going first
			srand(time(nullptr));
			turn = rand() % 2;
			if (turn == 1)
			{
				cout << "What attack will you choose?\n";
				printplayermoves();
				cin >> ans;
				player->attack(room,Opp,ans);
				fist1();
				switch (ans)
				{
				case 5: 
					//create a random number between 5-10. if the ai guesses 6, then the attack will be blocked
					srand(time(0));
				 AIturn = rand() % 6 + 5;
					if (AIturn == ans)
					{
						cout << "Your attack was dodged...Its his turn to counter.\n";
						this_thread::sleep_for(2s);
						dodge1();
						turn = 2;
					}
					else
					{
						cout << "Your attack connected!!!!!!!\n";
						Opp->takeDamage(room, 4);
						cout << Opp->getName() << "Current health: " << Opp->getHealth();
						punchedInFace();
						turn = 2;
					}
					break;
				case 6:
					//create a random number between 5-10. if the ai guesses 6, then the attack will be blocked
					srand(time(0));
					 AIturn = rand() % 6 + 5;
					if (AIturn == ans)
					{
						cout << "Your attack was dodged...Its his turn to counter.\n";
						dodge1();
						turn = 2;
					}
					else
					{
						cout << "Your attack connected!!!!!!!\n";
						Opp->takeDamage(room, 4);
						cout << Opp->getName() << "Current health: " << Opp->getHealth();
						fist2();
						turn = 2;
					}
					break;
				//Attacking with Wepon
				case 7:
					//create a random number between 5-11. if the ai guesses 7, then the attack will be blocked
					srand(time(0));
					 AIturn = rand() % 7 + 5;
					if (AIturn == ans)
					{
						cout << "Your attack was dodged...Its his turn to counter.\n";
						dodge1();
						turn = 2;
					}
					else
					{
						cout << "Your attack connected!!!!!!!\n";
						//Take away HP
						Opp->takeDamage(room, 7);
						//Update player on Enemy health
						cout << Opp->getName() << "Current health: " << Opp->getHealth();
						//display graphic
						fist1();
						turn = 2;
					}
					break;


				}
				
			}
			else if (turn == 2)
			{
				//get a random number for opp attack
				srand(time(0));
				 AIturn = rand() % 6 + 5;
				//opp choices
				switch (AIturn)
				{
				case 5:
					int userDefense;
					//give user 5 seconds to come up with a response
					cout << Opp->getName() << " threw a right hook at you! Act fast!\n";
					cout << endl;
					cout << "Choose your defense!!!\n";
					printplayermoves();
					if (getTimeLimitedUserInput(userDefense, 5))
					{
						if (userDefense == 1)
						{
							cout << "That was close! Good job dodging\n";
							turn = 1;
						}
						else
						{
							cout << "Damn you got rocked! shake it off and get back in this!\n";
							player->takeDamage(Opp->getStrength());
							cout << "Your health: " << player->getHealth();
							fist3();
							turn = 1;
						}
						
					}
					else
					{
						cout << "Damn you got rocked! Shake it off and get back in this!\n";
						player->takeDamage(Opp->getStrength());
						cout << "Your health: " << player->getHealth();
						fist3();
						turn = 1;
					}
					break;
				case 6:
					 userDefense;
					//give user 5 seconds to come up with a response
					cout << Opp->getName() << " threw a left hook at you! Act fast!\n";
					cout << endl;
					cout << "Choose your defense!!!\n";
					printplayermoves();
					if (getTimeLimitedUserInput(userDefense, 5))
					{
						if (userDefense == 2)
						{
							cout << "That was close! Good job dodging\n";
							turn = 1;
						}
						else
						{
							cout << "Damn you got rocked! shake it off and get back in this!\n";
							player->takeDamage(Opp->getStrength());
							cout << "Your health: " << player->getHealth();
							fist3();
							turn = 1;
						}

					}
					else
					{
						cout << "Damn you got rocked! Shake it off and get back in this!\n";
						player->takeDamage(Opp->getStrength());
						cout << "Your health: " << player->getHealth();
						fist3();
						turn = 1;
					}
					break;

					//For grab attacks, you must be 2 strength points above your opponet to sucessfully break the hold or else
					//He will drop you on your head
					//You have a 50 percent chance of countering with a right hook when breaking the hold
					//If this happens you may attack him again.

				case 7: 
					 userDefense;
					//give user 5 seconds to come up with a response
					cout << Opp->getName() << "Grabbed you! He's strong! Be careful!!\n";
					cout << endl;
					cout << "Choose your defense!!!\n";
					printplayermoves();
					if (getTimeLimitedUserInput(userDefense, 5))
					{
						if (userDefense == 1 && player->getStrengthModifier() > Opp->getStrength() + 2)
						{
							
							srand(time(0));
							int randomCounterAttack = rand() % 2;
							if (randomCounterAttack == 1)
							{
								cout << "You broke the hold and countered with a left hook! Youve got this!\n";
								Opp->takeDamage(room,2);
								cout << endl;
								cout << Opp->getName() << "Current health: " << Opp->getHealth();
								turn = 1;

								
							}
							else
							{
								cout << "You broke the hold! Youve got this!\n";
								//find a acsii image
								turn = 1;

							}
						}
						else
						{
							cout << "He just slammed you on the ground and your body bounced off the floor like a basketball.\n";
							cout << endl;
							cout << "The sound of flesh rings through your ears...." << endl;
							player->takeDamage(Opp->getStrength());
							cout << "Your health: " << player->getHealth();
							fist3();
							turn = 1;
						}

					}
					else
					{
						cout << "He just slammed you on the ground and your body bounced off the floor like a basketball.\n";
						cout << endl;
						cout << "The sound of flesh rings through your ears." << endl;
						player->takeDamage(Opp->getStrength() + 2);
						cout << "Your health: " << player->getHealth();
						fist3();
						turn = 1;
					}
					break;
				}
				

			}

		}
		
	}
}


//ASCII images to spice up the fight scenes

