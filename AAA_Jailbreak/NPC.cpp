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

string NPC::generateDialogue()
{
    //generic dialogue for just fork - will add/diversify future dialogues and responses
    string dialogue[] = { "Hey Cellie, what you up to?","What's up, Cellie?", "You need something, Cellie?", "Sup, Cellie?", "How's it hanging, Cellie?" };
    srand(time(NULL));
    int arraySize = sizeof(dialogue) / sizeof(dialogue[0]);
    int choice = rand() % arraySize;
    string dialogueSep = "\n============================================\n";
    cout << dialogueSep;
    return dialogue[choice] + dialogueSep;

}

//greeting for npcs
string NPC::getGreeting() {
    int size = greetings.size();
    int choice = rand() % size;
    string dialogueSep = "\n============================================\n";
    cout << dialogueSep;
    return greetings[choice] + dialogueSep;
}

void NPC::PrintTradeTable() {

}

//virtual methods for traders, enemies, guards, and questgivers
bool NPC::SearchForTradeItem(string itemName) {
    return false;
}

string NPC::ItemToGiveToTrader(string itemName) {
    return "";
}

Item NPC::getItemFromTrader(string itemName) {
    return Item();
}

void NPC::DeleteTradeItem(string itemName) {

}

string NPC::FightDialogue() {
    return "";
}

int NPC::getSuspicionLevel() {
    return 1;
}

int NPC::Confront(int playerIntellect, int playerReputation) {
    return 0;
}

void NPC::IncrementQuestPosition() {

}

void NPC::setQuestPosition(int) {

}

int NPC::getQuestPosition() {
    return 0;
}