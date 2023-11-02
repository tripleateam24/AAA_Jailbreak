#pragma once
#include <string>
#include <iostream>
#include "Item.h"
#include <map>

using namespace std;

class NPC {
public:
    NPC() {}
    NPC(const string& name, const string& description, const string& id)
        : name(name), description(description), ID(id) {}

    void talkToPlayer()
    {
        cout << "\n" << name << ", your " << description << ", says:" << endl;
    }

    string generateDialogue();
    string getName() const;
    string getDescription() const;
    string getID() const;


    virtual void PrintTradeTable();
    virtual bool SearchForTradeItem(string itemName);
    virtual string ItemToGiveToTrader(string itemName);
    virtual Item getItemFromTrader(string itemName);
    virtual void DeleteTradeItem(string itemName);
protected:
    string name;
    string dialogue;
    string description;
    string ID;

};