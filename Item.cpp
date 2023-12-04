#include "Item.h"
#include "Player.h"


//items are not showing up when the user types "INSPECT" 

Item::Item() {
	name = "UNDEFINED ITEM";
	description = "UNDEFINED ITEM DESCRIPTION";
	Type = "UNKNOWN";
}


Item::Item(string n, string desc, string t) {
	name = n;
	Type = t;
	description = desc;

}

string Item::getName() const {
	return name;
}


string Item::getDescription() const {
	return description;
}

string Item::getType() const
{
	return Type;
}

void Item::updateName(string un)
{
	name = un;
}

void Item::updateType(string updty)
{
	Type = updty;
}

void Item::updatedesc(string upddesc)
{
	description = upddesc;
}



