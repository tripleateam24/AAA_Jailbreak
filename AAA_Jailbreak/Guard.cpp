#include "Guard.h"


Guard::Guard() {}
//guard constructor
Guard::Guard(string n, string desc, string id) {
    name = n;
    description = desc;
    ID = id;
    suspicionLevel = 6;
    
    //defualt emotional status to be used later(maybe)
    emotionStatus = Neutral;
     
    //greetings and responses for guards
    greetings = { "Hey you...what are you doing right now?", "Hey, you! Are you doing something you're not supposed to?", "What are you up to?" };
    neutralresponses = { "Alright, carry on.", "Ok...you may proceed", "hmm....alright then, carry on", "Alright, move along then", "Ok, but I've got my eye on you." };
    goodresponses = { "Why thank you, I agree", "how nice of you to say that, carry on", "thanks, I would say you're right, carry on" };
    badresponses = { "I don't like you very much....You're going to solitary", "I've had about enough of you....You're going to solitary", "Yeah, yeah, I've heard it all before, You're coming with me" };
}

//setter and getter for suspicion level
void Guard::setSuspicionLevel(int x) {
    suspicionLevel = x;
}
int Guard::getSuspicionLevel() {
    return suspicionLevel;
}

//setter and getter for emotion status
void Guard::setEmotionStatus(EmotionLevel eL) {
    emotionStatus = eL;
}
Guard::EmotionLevel Guard::getEmotionStatus() {
    return emotionStatus;
}

//getter for neutral responses
string Guard::getNeutralResponse() {
    int size = neutralresponses.size();
    int choice = rand() % size;
    string dialogueSep = "\n============================================\n";
    cout << dialogueSep;
    return neutralresponses[choice] + dialogueSep;

}
//getter for good responses
string Guard::getGoodResponse() {
    int size = goodresponses.size();
    int choice = rand() % size;
    string dialogueSep = "\n============================================\n";
    cout << dialogueSep;
    return goodresponses[choice] + dialogueSep;

}
//getter for bad responses
string Guard::getBadResponse() {
    int size = badresponses.size();
    int choice = rand() % size;
    string dialogueSep = "\n============================================\n";
    cout << dialogueSep;
    return badresponses[choice] + dialogueSep;

}

//refactor if-tree
//guard confrontation method
int Guard::Confront(int playerIntellect, int playerReputation) {
    string answer;
    int roll;
    int charm;
    int numSolitaryDays = 0;
    cout << "\nA Guard approaches you....\n";
    getGreeting();
    //response menu for player
    cout << "(A) NEUTRAL: \"I'm just trying to go on my way.\"\n(B) COMPLIMENT: \"I really like your uniform, I bet all the other guards are jealous\"\n(C) INSULT: \"Screw You!\"";
    cout << "\n\nEnter Response: ";
    getline(cin, answer);
    //whether the guard likes you or not depends on your intellect and reputation
    if (answer == "A" || answer == "a") {
        roll = rand() % (20 + playerIntellect) + 1;
        charm = roll + playerReputation;
        cout << charm << endl;
        if (charm >= suspicionLevel) {
            cout << getNeutralResponse() << endl;
            setEmotionStatus(Neutral);
        }
        else {
            cout << getBadResponse() << endl;
            setEmotionStatus(Angry);
        }
    }
    else if (answer == "B" || answer == "b") {
        roll = rand() % (15 + playerIntellect) + 1;
        charm = roll + playerReputation;
        if (charm >= suspicionLevel) {
            cout << getGoodResponse() << endl;
            setEmotionStatus(Friendly);
        }
        else {
            cout << getBadResponse() << endl;
            setEmotionStatus(Angry);
        }
    }
    else {
        roll = rand() % (8 + playerIntellect) + 1;
        charm = roll + playerReputation;
        if (charm >= suspicionLevel) {
            cout << getNeutralResponse() << endl;
            setEmotionStatus(Neutral);
        }
        else {
            cout << getBadResponse() << endl;
            setEmotionStatus(Angry);
        }
    }

    //whether or not the guard puts you in solitary
    switch (emotionStatus) {
    case Friendly:
        cout << "\nHe actually seems kind of friendly\nHe leaves you alone.\n";
        break;
    case Neutral:
        cout << "\nYou breathe a sight of relief...\nHe leaves you alone\n";
        break;
    case Angry:
        numSolitaryDays = (rand() % 10) + 1;
        cout << "You are put into solitary confinement for " << numSolitaryDays;
        if (numSolitaryDays == 1) cout << " day.\n";
        else cout << " days.\n";
        cout << "You are finally released.....You make your way back to your cell.\n";
        break;


    }
    //returns number of days that must be spent in solitary
    return numSolitaryDays;
}


