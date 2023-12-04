#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Item {
	string name;
	string Type;
	string description;

public:
	Item();
	Item(string n, string desc, string type);
	string getName() const;
	string getDescription() const;
	string getType() const;
	void updateName(string updname);
	void updateType(string updty);
	void updatedesc(string upddesc);
};