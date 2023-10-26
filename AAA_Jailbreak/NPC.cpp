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
    //generic dialogue for just fork - will add/diversify future dialogues and responses
    string dialogue[] = { "Hey Cellie, what you up to?","What's up, Cellie?", "You need something, Cellie?", "Sup, Cellie?", "How's it hanging, Cellie?" };
    srand(time(NULL));
    int arraySize = sizeof(dialogue) / sizeof(dialogue[0]);
    int choice = rand() % arraySize;
    string dialogueSep = "\n============================================\n";
    cout << dialogueSep;
    return dialogue[choice] + dialogueSep;

}


