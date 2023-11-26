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
    string dialogue[] = { "Hey what you up to?","What's up, Cellie?", "You need something, Cellie?", "Sup, Cellie?", "How's it hanging, Cellie?"};
    srand(time(NULL));
    int arraySize = sizeof(dialogue) / sizeof(dialogue[0]);
    int choice = rand() % arraySize;
    string dialogueSep = "\n============================================\n";
    cout << dialogueSep;
    return dialogue[choice] + dialogueSep;
    
}

string NPC::getWeponName()
{
    //defined in enemy.cpp
}

void NPC::attack(NPC* e, int number)
{
    //defined in enemy.cpp
}

void NPC::dropLoot(Prison* prison, NPC* e)
{
    //defined in enemy.cpp
}

int NPC::getStrength()
{
    //defined in enemy.cpp
}

void NPC::droploot(Prison* prison,NPC* e)
{
    //defined in enemy.cpp
}

int NPC::getHealth()
{
    //defined in enemy.cpp
}

int NPC::takeDamage(int damage)
{
   //defined in enemy.cpp
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
    return Item();
}



void NPC::DeleteTradeItem(string itemName)
{
    //defined in enemy
}




