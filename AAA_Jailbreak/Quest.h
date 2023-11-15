#pragma once
#define QUEST_H
#include "Item.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Quest {
    //dialogue for 3 stages of a quest
    string QuestDialogue;
    string QuestInProgressDialogue;
    string QuestFinishedDialogue;

    //condition if quest is completed or not
    int condition;


public:

    //list of items to give to player upon completion status
    vector<Item> itemsToGive;
    bool finished;

    Quest();
    Quest(string, string, string);

    void setQuestDialogue(string d);
    void setQuestFinishedDialogue(string fD);
    void setQuestInProgressDialogue(string);

    string getQuestDialogue();
    string getQuestFinishedDialogue();
    string getInProgressDialogue();

    Item getItem(string);

    int CheckCondition();

    void setCondition(int x);


};