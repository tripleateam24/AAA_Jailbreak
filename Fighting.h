#pragma once
#include <iostream>
#include "Room.h"
#include "Enemy.h"
#include "Player.h"
using namespace std;

class Fighting {
private:
	string opp;

public:
	//function to throw you into a fighting match
	//JP3 Added Player object
	void fightScene(Room* room, bool cheapShot, NPC* Opp, Player* player);
	//3PJ
	//print a list of player attack options
};