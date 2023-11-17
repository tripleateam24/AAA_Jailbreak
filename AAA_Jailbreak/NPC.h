#pragma once

#include <string>
#include <iostream>
#include "Item.h"
#include <map>
#include "Room.h"
#include "Enemy.h"

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
   // string getName() const; 
   //string getDescription() const; 
    string ID; 



    //Virtual Functions for Enemy

  virtual int getHealth();
    //Give ability to take damage
  virtual void takeDamage(Room* r, int damage);
    //function that allows computer to attack
  virtual void attack(NPC* e, int num);
    //return the type of wepon the opp has
  virtual string getWepon();
    //upon dying the opp would drop its items
  virtual void dropLoot(NPC* e);
    //return strenght
  virtual int getStrength();



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

