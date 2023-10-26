#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Item {
	string name;
	string firstDescription;
	string description;


public:
	Item();
	Item(string n, string firstDesc, string desc);
	string getName() const;
	string getFirstDescription() const;
	string getDescription() const;
	string getType() const;
	string itemtype() const;
};
