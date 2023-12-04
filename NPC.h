#pragma once

#include <string>
#include <iostream>
#include "Item.h"
#include <map>

using namespace std;

class NPC {
public:
    NPC(const string& name, const string& description)
        : name(name), description(description) {}
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

    string name; 
    string dialogue; 
    string description;
    int health = 15;
   // string getName() const; 
   //string getDescription() const; 
    string ID; 

    //For Enemy class
    virtual string getWeponName();

    virtual void attack(NPC* e, int number);

    //JP3: Causes import loop + unused
    //virtual void dropLoot(Prison* prison, NPC* e);
    //3PJ

    virtual int getStrength();

    //JP3: Already defined? Also needs prison object from main()
    // virtual void droploot(Prison* prison, NPC* e);
    //3PJ

    virtual int getHealth();

    virtual void takeDamage(int damage);

    virtual Item dropLoot();
    virtual void PrintTradeTable();
    virtual bool SearchForTradeItem(string itemName);
    virtual string ItemToGiveToTrader(string itemName);
    virtual Item getItemFromTrader(string itemName);
    virtual void DeleteTradeItem(string itemName);
protected:
    string generateGreetingDialogue();
private:
    /*
    string name;
    string dialogue;
    string description;
    string getName() const;
    string getDescription() const;
    string ID;
    */
};

