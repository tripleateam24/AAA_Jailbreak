#pragma once
#include <iostream>
#include "Room.h"
#include "Enemy.h"
#include "Player.h"
using namespace std;

class fight {
private:
	string opp;

public:
	//function to throw you into a fighting match
	void fightScene(Room* room, bool cheapShot, NPC* Opp);
	//print a list of player attack options
};