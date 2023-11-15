#pragma once
#define PLAYER_H
#include "Prison.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

class Player {
	string name;
	int health;
	int INVENTORYSIZE;
	int strengthModifier;
	int exerciseCount;
	int studyCount;
	int intellect;
	int reputation;

	vector<Item> PocketsInventory;

public:
	Player(string n);
	void PrintInstructions();
	void TakeItem(Prison*, string);
	void TakeItemFromNPC(Prison*, string, string, int);
	void DiscardItem(Prison*, string);
	void PrintInventory();
	void TalkToNPC(Prison*);
	void Trade(Prison*, string);

	bool HasItem(string);

	void Exercise(Prison*);
	void Study(Prison*);
	void CheckTime(Prison*);

	void GiveItemAway(string, string);

	void InputMenu(Prison*);
	void CheckQuestConditions(Prison*, string);

	void setName(string);
	void setHealth(int);
	void setStrengthModifier(int);
	void setIntellect(int);
	void setReputation(int);

	void resetExerciseCount();
	void resetStudyCount();

	string getName() const;
	int getHealth() const;
	int getStrengthModifier() const;
	int getIntellect() const;
	int getReputationLevel() const;


	void manipulateItem();

};