#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Item {
	string name;
	string description;

public:
	Item();
	Item(string n, string desc);
	string getName() const;
	string getDescription() const;

};