#include "Enemy.h"

//enemy constructor
Enemy::Enemy(string n, string desc, string id, int h, int s, Item w) {
    name = n;
    description = desc;
    ID = id;
    health = h;
    strength = s;

    numTimesSpokenTo = 0;

    greetings = { "Hey you, get outta here before something bad happens to ya", "Get lost", "don't show your face around here", "I don't like the way your looking at me" };

}

//fighting dialogue for enemies
string Enemy::FightDialogue() {
    string dialogue[] = { "You just made a big mistake!", "You're done for!", "You shouldn't have done that.", "Your time is up" };
    int arrSize = sizeof(dialogue) / sizeof(dialogue[0]);
    int choice = rand() % arrSize;
    string dialogueSep = "\n============================================\n";
    cout << dialogueSep;
    return dialogue[choice] + dialogueSep;
}







