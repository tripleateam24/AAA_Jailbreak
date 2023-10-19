#pragma once

#include <string>
#include <iostream>
using namespace std;

class NPC {
public:
    NPC(const string& name, const string& dialogue)
        : name(name), dialogue(dialogue) {}

    void talkToPlayer() {
        cout << name << ": " << dialogue << endl;
    }
    

private:
    string name;
    string dialogue;
    string description;
    string getName() const;
    string getDescription() const;
};

