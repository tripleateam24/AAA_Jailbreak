#include "Prison.h"

Prison::Prison() {
	dayLight = 20;
	dayCounter = 0;
	cell = new Room("Your Cell", "CELL DESCRIPTION HERE", nullptr, nullptr, nullptr, nullptr);
	cafe = new Room("The Cafeteria", "A Large cafeteria with long tables, many other prisoners sit with their food. You see a Cookie on a table next to.", cell, nullptr, nullptr, nullptr);
	hallway = new Room("The A Block Hallway", "HALLWAY DESCRIPTION HERE", cell, nullptr, nullptr, nullptr);

	gym = new Room("The Gym", "GYM DESCRIPTION HERE", cafe, nullptr, nullptr, nullptr);
	showers = new Room("The Showers", "SHOWERS DESCRIPTION HERE", cafe, nullptr, nullptr, nullptr);

	courtYard = new Room("The Court Yard", "COURTYARD DESCRIPTION HERE", hallway, nullptr, nullptr, nullptr);
	WardensOffice = new Room("The Warden's Office", "WARDEN'S OFFICE DESCRIPTION HERE", hallway, nullptr, nullptr, nullptr);

	cell->leftRoom = cafe;
	cell->rightRoom = hallway;
	cafe->leftRoom = gym;
	cafe->rightRoom = showers;
	hallway->leftRoom = courtYard;
	hallway->rightRoom = WardensOffice;

	currentRoom = cell;

	//List of Item types
	vector<string>Item_Types = {"Consumeable","Wepons","potential_Wepons","Throwable","key_Item", "objective_item", "Valuable"};

	/*
	Consumeable: Food items
	Wepons: objects that can be used to defend against attackers/attack others with
	Potential wepons: objects that can be maniplulated to become actual wepons
	Throwables: Items that can be tossed around a room.. Can be used to create distractions or double as a wepon
	key_item: keys to open doors
	valuables: items that have high trade value
	*/



	//Items in Cell
	Item toothbrush("Tooth Brush", "A blue, plastic toothbrush. You can't seem to find toothpaste anywhere. Yes, you can sharpen, but be careful.", Item_Types[2]);
	Item razor("Razor", "A red, disposable shaving razor that's made specifically for prisoners, as they can't have normal razors blades.", Item_Types[1]);
	cell->AddItemToRoom(toothbrush);
	cell->AddItemToRoom(razor);

	//Items in cafe
	Item cookie("Cookie", "A large, round cookie", Item_Types[0]);
	Item plate("Plate", "A small, paper plate", Item_Types[0]);
	Item apple("Apple", "A red apple", Item_Types[0]);
	Item bottled_Water("Bottled Water", "A bottle of room temp water.", Item_Types[0]);
	cafe->AddItemToRoom(cookie);
	cafe->AddItemToRoom(plate);
	cafe->AddItemToRoom(apple);
	cafe->AddItemToRoom(bottled_Water);

	//Items in hallway
	Item toothpickspack("Toothpicks", "A small pack of toothpicks sitting in the corner, clearly someone must have dropped this here.", Item_Types[5]);
	hallway->AddItemToRoom(toothpickspack);

	//Items in gym
	Item weight("Weight", "A 5 pound curling weight resting near a bench press.", Item_Types[1]);
	gym->AddItemToRoom(weight);

	//Items in showers
	Item soap("Soap", "A small bar of soap, smells like lavender",Item_Types[3]);
	Item shampoo("Shampoo Bottle", "A small shampoo bottle, barely the size of your hand. \"Peppermint Scent\" written on the back", Item_Types[3]);

	showers->AddItemToRoom(soap);
	showers->AddItemToRoom(shampoo);

	//Items in Courtyard
	Item basketball("Basketball", "An old, deflated basketball", Item_Types[3]);
	Item pebble("Pebble", "A small pebble lying on the ground", Item_Types[3]);
	courtYard->AddItemToRoom(basketball);
	courtYard->AddItemToRoom(pebble);

	//Items in Wardens Office
	Item roledex("Roledex", "The Warden's roledex, lots of phone numbers that you can't make out",Item_Types[5]);
	Item cellphone("Cellphone", "The Warden's cell phone, he still uses a flip phone.", Item_Types[5]);
	WardensOffice->AddItemToRoom(roledex);
	WardensOffice->AddItemToRoom(cellphone);




	//adding people to rooms
	//adding people to rooms
	NPC* fork = new NPC("Fork", "You're cellmate", "FRIEND");
	NPC* bob = new NPC("Bob", "Line Cook", "FRIEND");

	NPC* james = new NPC("James", "Second Line Cook", "FRIEND");

	//traders
	Trader* greg = new Trader("Greg", "Gym Trader", "TRADER");
	Trader* bill = new Trader("Bill", "Gym Trader", "TRADER");
	Trader* john = new Trader("John", "Gym Trader", "TRADER");

	greg->TradeTable["Plate"] = Item("Lighter", "A silver zippo lighter, good for lighting up dark places", Item_Types[4]);
	greg->TradeTable["Razor"] = Item("Matches", "A small box of striking matches", Item_Types[4]);
	bill->TradeTable["Apple"] = Item("Wrench", "A silver hand wrench", Item_Types[4]);
	bill->TradeTable["Cookie"] = Item("Flashlight", "A handheld, battery powered flashling", Item_Types[4]);

	//enemies
	Enemy* josh = new Enemy("Josh", "Bad Guy", "ENEMY", 20, 5, Item("Knife", "A knife", Item_Types[1]));

	cell->AddNPCToRoom(fork);
	cafe->AddNPCToRoom(bob);
	cafe->AddNPCToRoom(james);

	gym->AddNPCToRoom(greg);
	gym->AddNPCToRoom(bill);
	gym->AddNPCToRoom(john);

	courtYard->AddNPCToRoom(josh);



}

Prison::~Prison() {
	delete cell, cafe, hallway, gym, showers, courtYard, WardensOffice;
}

void Prison::MoveRooms() {
	string answer;
	cout << "Move: ";
	getline(cin, answer);
	cout << "\n";
	if ((answer == "left") || (answer == "LEFT") || (answer == "l") || (answer == "L") || (answer == "Left")) {
		if (currentRoom->leftRoom != nullptr) {
			currentRoom = currentRoom->leftRoom;
			cout << "Moving into " << currentRoom->getName() << ".....\n";
			LoseDayLight(1);
		}
		else {
			cout << "No Room to the Left.\n";
		}
	}
	else if ((answer == "right") || (answer == "RIGHT") || (answer == "r") || (answer == "R") || (answer == "Right")) {
		if (currentRoom->rightRoom != nullptr) {
			currentRoom = currentRoom->rightRoom;
			cout << "Moving into " << currentRoom->getName() << ".....\n";
			LoseDayLight(1);
		}
		else {
			cout << "No Room to the Right.\n";
		}
	}
	else if ((answer == "back") || (answer == "BACK") || (answer == "b") || (answer == "B") || (answer == "Back")) {
		if (currentRoom->backRoom != nullptr) {
			currentRoom = currentRoom->backRoom;
			cout << "Moving into " << currentRoom->getName() << ".....\n";
			LoseDayLight(1);
		}
		else {
			cout << "You are in you're cell, there is no back room here.\n";
		}
	}
	else if ((answer == "forward") || (answer == "FORWARD") || (answer == "f") || (answer == "F") || (answer == "Forward")) {
		if (currentRoom->forwardRoom != nullptr) {
			currentRoom = currentRoom->forwardRoom;
			cout << "Moving into " << currentRoom->getName() << ".....\n";
			LoseDayLight(1);
		}
		else {
			cout << "No Room in Front of you.\n";
		}
	}
	else if (answer == "EXIT") {
		cout << "Exiting Game...\n";
		exit(0);
	}
	else {
		"Sorry, I don't understand what you want to do here.\n";
	}



}

void Prison::PrintRoom() {
	cout << "You are currently inside " << currentRoom->getName() << "\n\n\n";
}

void Prison::LoseDayLight(int x) {
	dayLight -= x;
}

void Prison::SetDayLight(int x) {
	dayLight = x;
}

int Prison::getDaylight() const {
	return dayLight;

}

void Prison::newDay() {
	dayCounter++;
}

int Prison::getDay() const {
	return dayCounter;
}