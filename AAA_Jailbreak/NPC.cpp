#include "NPC.h"



//getter functions for name and description
string NPC::getName() const {
    return name;
}
string NPC::getDescription() const {
    return description;
}

string NPC::generateDialogue()
{
    string dialogue[2] = { "Hey cellie, what you up to?","What's up cellie?" };
    srand(time(NULL));
    int choice = rand() % 2;
    return dialogue[choice];
    
}