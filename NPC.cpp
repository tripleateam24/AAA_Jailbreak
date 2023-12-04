#include <iostream>
#include "NPC.h"

//getter functions for name and description
string NPC::getName() const {
    return name;
}
string NPC::getDescription() const {
    return description;
}
string NPC::getID() const {
    return ID;
}

string NPC::generateGreetingDialogue()
{
    //generic dialogue for just fork - will add/diversify future dialogues and responses
    string dialogue[] = { "Hey what you up to?","What's up, Cellie?", "You need something, Cellie?", "Sup, Cellie?", "How's it hanging, Cellie?" };
    srand(time(NULL));
    int arraySize = sizeof(dialogue) / sizeof(dialogue[0]);
    int choice = rand() % arraySize;
    string dialogueSep = "\n============================================\n";
    cout << dialogueSep;
    return dialogue[choice] + dialogueSep;

}
//JP3: No return value, faking one.
string NPC::getWeponName()
{
    cout << "[JP3] Error in NPC:getWeponName(). See header file." << endl;
    //defined in enemy.cpp
    return "[JP3] Error in NPC:getWeponName(). See header file.";
}
//3PJ

void NPC::attack(NPC* e, int number)
{
    //defined in enemy.cpp
}
//JP3 Disabling, see header file
/*
void NPC::dropLoot(Prison* prison, NPC* e)
{
    //defined in enemy.cpp
}
*/
//3PJ

//JP3: No return value, faking one.
int NPC::getStrength()
{
    //defined in enemy.cpp
    //If you decide to fight a regular npc, this is all their base stats
    return 4;
}
//3PJ

//JP3 Disabling, see header file.
/*
void NPC::droploot(Prison* prison, NPC* e)
{
    //defined in enemy.cpp
}
*/
//3PJ

//JP3: No return value, faking one.
int NPC::getHealth()
{
    //defined in enemy.cpp
    
    return health;
}
//3PJ


void NPC::takeDamage(int damage)
{
    //defined in enemy.cpp
    health -= damage;
    if (health < 0)
        health = 0;
}
//3PJ

Item NPC::dropLoot()
{
    Item Item("", "", "");
    //defined in enemy.cpp
    return Item;
}

void NPC::PrintTradeTable() {
    //defined in enemy
}

bool NPC::SearchForTradeItem(string itemName) {
    return false;
}

string NPC::ItemToGiveToTrader(string itemName) {
    return "";
}


string NPC::generateDialogue()
{

    string dialogue[] = { "You plan on getting out of here somehow?","How I got my name? You dont wanna know why.",
        "Have you done your shift today?", "Have you had went to the commissary" };
    srand(time(NULL));
    int arraySize = sizeof(dialogue) / sizeof(dialogue[0]);
    int choice = rand() % arraySize;
    string dialogueSep = "\n============================================\n";
    cout << dialogueSep;
    return dialogue[choice] + dialogueSep;

    //found this outside of this block, I assume it goes in here -NE

}


Item NPC::getItemFromTrader(string itemName)
{
    cout << "[JP3] Creating object does nothing @ Item NPC::getItemFromTrader(string itemName) " << endl;
    return Item();
}



void NPC::DeleteTradeItem(string itemName)
{
    cout << "[JP3] STUB!!! @ void NPC::DeleteTradeItem(string itemName) " << endl;
    //defined in enemy
}



