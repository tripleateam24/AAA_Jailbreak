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

int NPC::getHealth()
{
    return 0;
}

void NPC::takeDamage(Room* r, int damage)
{
    //defined in enemy
}

void NPC::attack(NPC* e, int num)
{
    //defined in enemy
}

string NPC::getWepon()
{
    return string();
}

void NPC::dropLoot(NPC* e)
{
    //defined in enemy
}

int NPC::getStrength()
{
    return 0;
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


// Randomize dialogue when player inputs "TALK" to NPC
string NPC::generateDialogue()
{
    
    string dialogue[] = { "You plan on getting out of here somehow?","How I got my name? You dont wanna know why.",
        "Have you done your shift today?", "Have you had went to the commissary?" };
    srand(time(NULL));
    int arraySize = sizeof(dialogue) / sizeof(dialogue[0]);
    int choice = rand() % arraySize;
    string dialogueSep = "\n============================================\n";
    cout << dialogueSep;
    return dialogue[choice] + dialogueSep;

}

string NPC::sethDialogue()
{
    string dialogue = "Yo Mouse. You remember that one case in the papers with the tax fraud and the wife? Yeah well, turns out the wife wasn't in the hospital at all!\n"
        "If I was that tax guy, I'd get out of here and get my revenge...\n";
    string dialogueSep = "\n============================================\n";
    cout << dialogueSep;
    return dialogue + dialogueSep;
}


Item NPC::getItemFromTrader(string itemName)
{
    return Item();
}



void NPC::DeleteTradeItem(string itemName)
{
    //defined in enemy
}




