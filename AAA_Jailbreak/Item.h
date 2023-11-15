#pragma once
#define ITEM_H
#include <string>


using namespace std;

class Item {
protected:
	//name, item type, and description
	string name;
	string Type;
	string description;


public:
	Item();
	Item(string, string, string);
	string getName() const;
	string getDescription() const;
	string getType() const;
	string itemtype() const;
	void updateName(string);
	void updateType(string);
	void updatedesc(string);


};

