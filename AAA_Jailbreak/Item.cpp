#include "Item.h"
#include "Player.h"

Item::Item() {
	name = "UNDEFINED ITEM";
	description = "UNDEFINED ITEM DESCRIPTION";
}


Item::Item(string n, string firstDesc, string desc) {
	name = n;
	firstDescription = firstDesc;
	description = desc;

}

string Item::getName() const {
	return name;
}

string Item::getFirstDescription() const {
	return firstDescription;
}

string Item::getDescription() const {
	return description;
}



