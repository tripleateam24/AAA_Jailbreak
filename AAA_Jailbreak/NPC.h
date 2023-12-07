#pragma once
#define NPC_H
#include <iostream>
#include "Quest.h"
 
class NPC {
public:
    enum EmotionLevel { Friendly, Neutral, Angry };

    //number of times you spoke to an npc
    int numTimesSpokenTo;

    //greeting and quest vectors
    vector<string> greetings;
    vector<Quest> quests;


    NPC() {}
    NPC(const string& name, const string& description, const string& id)
        : name(name), description(description), ID(id), greetings{ "Hey man...how's it going?", "How are ya?", "What's going on?", "Hey dude, how's it hanging?" }, numTimesSpokenTo(0) {}

    void talkToPlayer()
    {
        cout << "\n" << name << ", your " << description << ", says:" << endl;
    }

    string generateDialogue();
    string getName() const;
    string getDescription() const;
    string getID() const;

    //virtual methods for inherited classes
    virtual void PrintTradeTable();
    virtual bool SearchForTradeItem(string);
    virtual string ItemToGiveToTrader(string);
    virtual Item getItemFromTrader(string);
    virtual void DeleteTradeItem(string);
    virtual void RefreshTable();
    virtual string getGreeting();
    virtual string FightDialogue();
    virtual int getSuspicionLevel();
    virtual int Confront(int, int);
    virtual void IncrementQuestPosition();
    virtual void setQuestPosition(int);
    virtual int getQuestPosition();



protected:
    string name;
    string dialogue;
    string description;
    string ID;

};





