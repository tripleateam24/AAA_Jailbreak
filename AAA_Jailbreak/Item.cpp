#include "Item.h"

Item::Item() {
	name = "UNDEFINED ITEM";
	description = "UNDEFINED ITEM DESCRIPTION";
}


Item::Item(string n, string desc) {
	name = n;
	description = desc;

}

string Item::getName() const {
	return name;
}

string Item::getDescription() const {
	return description;
}

