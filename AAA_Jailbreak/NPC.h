#pragma once

#include <string>
#include <iostream>

using namespace std;

class NPC {
public:
    NPC(const string& name, const string& description)
        : name(name), description(description) {}

    void talkToPlayer()
    {
        cout << "\n" << name << ", your " << description << ", says:" << endl;
    }

    string generateDialogue();
    string getName() const;
    string getDescription() const;

private:
    string name;
    string dialogue;
    string description;


};