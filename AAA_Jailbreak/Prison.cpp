#include "Prison.h"

Prison::Prison() {

	dayLight = 24;
	dayCounter = 0;
	laundryAccess = false;
	wardensOfficeLocked = true;
	escaped = false;
	//possible map design(subject to change)
	// need to clean up the actual navigation of rooms
	cell = new Room("Your Cell", "Your 6x8 ft humble abode. You have a toilet, a sink, and a bunk bed you share with your cellmate, Fork. You can SLEEP in this room.", nullptr, nullptr, nullptr, nullptr);
	bathroom = new Room("Your Bathroom", "A very small room with just enough space to give you privacy while using the bathroom....A small hole is visible in the wall behind the toilet, discarded items in this room will not be found during inspection", nullptr, nullptr, nullptr, nullptr);

	hallway = new Room("The A Block Hallway", "An adequate lit hallway with security doors, exit signs, and emergency routes. Under strict supervision by prison guards.", nullptr, nullptr, nullptr, nullptr);
	commonRoom = new Room("The Common Room", "A common room fit with a television and stacks of educational books. You can STUDY in this room for increased intellect.", nullptr, nullptr, nullptr, nullptr);
	cafe = new Room("The Cafeteria", "A Large cafeteria with long tables, many other prisoners sit with their food. You see a Cookie on a table next to you.", nullptr, nullptr, nullptr, nullptr);

	westWingHallway = new Room("West Wing Hallway", "WEST WING HALLWAY DESCRIPTION HERE", nullptr, nullptr, nullptr, nullptr);
	
	entranceToPrison = new Room("Entrance To Prison", "The entrance/exit door to the prison. Guards go through here when they arrive or leave.", nullptr, nullptr, nullptr, nullptr);

	airlock = new Room("Airlock Room", "A room seperating the courtyard from the rest of the prison", nullptr, nullptr, nullptr, nullptr);
	courtYard = new Room("The Court Yard", "The courtyard is the outdoor space with a basketball court being the main attraction. The high fences and prison guards keep this area under control.", nullptr, nullptr, nullptr, nullptr);

	workshopRoom = new Room("The Workshop Room", "WORKSHOP ROOM DESCRIPTION HERE", nullptr, nullptr, nullptr, nullptr);
	gym = new Room("The Gym", "A prison gym that features exercise equipment and other jail-mates. You can EXERCISE for increased strength and health. You hear that this is the place you can trade with people for items. There are also 2 guards always on supervision.", nullptr, nullptr, nullptr, nullptr);
	showers = new Room("The Showers", "The communal showers where there are open shower heads for you to wash up.", nullptr, nullptr, nullptr, nullptr);
	laundryRoom = new Room("The Laundry Room", "Filled with your standard washers and dryers ran by other prisoners. Both gurads and prisoners get their clothes washed here.", gym, nullptr, nullptr, nullptr);

	eastWingHallway = new Room("East Wing Hallway", "EAST WING HALLWAY DESCRIPTION HERE", nullptr, nullptr, nullptr, nullptr);

	contrabandCloset = new Room("Contraband Closet", "Small storage closet, guards put the contraband they find in here.", nullptr, nullptr, nullptr, nullptr);
	WardensOffice = new Room("The Warden's Office", "The Warden's office, where a large desk and cabinets that contain sensitive files and records reside.\n It is also a communication center equipped with phones, radios, and computer systems for the Warden to stay in contact with other prison staff.", nullptr, nullptr, nullptr, nullptr);

	// Prison layout
	cell->forwardRoom = hallway;
	cell->rightRoom = bathroom;

	bathroom->leftRoom = cell;

	hallway->backRoom = cell;
	hallway->leftRoom = cafe;
	hallway->rightRoom = commonRoom;
	hallway->forwardRoom = airlock;

	airlock->backRoom = hallway;
	airlock->forwardRoom = courtYard;

	courtYard->backRoom = airlock;

	cafe->rightRoom = hallway;
	cafe->forwardRoom = workshopRoom;

	commonRoom->leftRoom = hallway;
	commonRoom->forwardRoom = westWingHallway;

	westWingHallway->backRoom = commonRoom;
	westWingHallway->forwardRoom = showers;
	westWingHallway->rightRoom = entranceToPrison;

	showers->backRoom = westWingHallway;
	showers->leftRoom = gym;

	gym->rightRoom = showers;
	gym->leftRoom = workshopRoom;
	gym->forwardRoom = laundryRoom;

	workshopRoom->rightRoom = gym;
	workshopRoom->backRoom = cafe;
	workshopRoom->forwardRoom = eastWingHallway;


	eastWingHallway->backRoom = workshopRoom;
	eastWingHallway->forwardRoom = WardensOffice;
	eastWingHallway->rightRoom = contrabandCloset;

	contrabandCloset->leftRoom = eastWingHallway;


	WardensOffice->backRoom = eastWingHallway;


	//entranceToPrison->leftRoom = westWingHallway;

	


	currentRoom = cell;

	//List of Item types
	vector<string>Item_Types = { "Consumeable","Wepons","potential_Wepons","Throwable","key_Item", "objective_item", "Valuable" };

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
	Item tuna("Tuna", "A tin can of tuna, popular with prisoners for some reason", Item_Types[0]);
	cafe->AddItemToRoom(cookie);
	cafe->AddItemToRoom(plate);
	cafe->AddItemToRoom(apple);
	cafe->AddItemToRoom(bottled_Water);
	cafe->AddItemToRoom(tuna);

	//Items in hallway
	Item toothpickspack("Toothpicks", "A small pack of toothpicks sitting in the corner, clearly someone must have dropped this here.", Item_Types[5]);
	hallway->AddItemToRoom(toothpickspack);

	//Items in gym
	Item weight("Weight", "A 5 pound curling weight resting near a bench press.", Item_Types[1]);
	gym->AddItemToRoom(weight);

	//Items in showers
	Item soap("Soap", "A small bar of soap, smells like lavender", Item_Types[3]);
	Item shampoo("Shampoo Bottle", "A small shampoo bottle, barely the size of your hand. \"Peppermint Scent\" written on the back", Item_Types[3]);
	showers->AddItemToRoom(soap);
	showers->AddItemToRoom(shampoo);

	//items in common room
	Item astronomyBook("Astronomy Book", "Hardcover book on astronomy.", Item_Types[3]);
	commonRoom->AddItemToRoom(astronomyBook);


	Item batteries("AAA Batteries", "Pack of 6 AAA batteries held in plastic", Item_Types[3]);
	Item paintbrush("Paintbrush", "Small Paintbrush, slightly stained with blue paint", Item_Types[3]);
	workshopRoom->AddItemToRoom(batteries);
	workshopRoom->AddItemToRoom(paintbrush);

	Item guardsShoes("Guards Shoes", "A pair of shoes worn by the guards in this prison, can worn to escape", Item_Types[5]);
	Item guardsShirt("Guards Shirt", "A shirt worn by the guards in this prison, can worn to escape", Item_Types[5]);
	Item prisonersShirt("Prisoners Shirt", "A newly cleaned shirt worn by everyone in the prison", Item_Types[3]);
	Item prisonersSocks("Prisoners Socks", "A newly cleaned pair of socks worn by everyone in the prison", Item_Types[3]);
	laundryRoom->AddItemToRoom(guardsShoes);
	laundryRoom->AddItemToRoom(guardsShirt);
	laundryRoom->AddItemToRoom(prisonersShirt);
	laundryRoom->AddItemToRoom(prisonersSocks);


	//Items in Courtyard
	Item basketball("Basketball", "An old, deflated basketball", Item_Types[3]);
	Item pebble("Pebble", "A small pebble lying on the ground", Item_Types[3]);
	courtYard->AddItemToRoom(basketball);
	courtYard->AddItemToRoom(pebble);

	//Items in Wardens Office
	Item roledex("Roledex", "The Warden's roledex, lots of phone numbers that you can't make out", Item_Types[5]);
	Item cellphone("Cellphone", "The Warden's cell phone, he still uses a flip phone.", Item_Types[5]);
	Item wardensMug("Warden's Holiday Mug", "The Warden's Holiday mug sitting on a coster", Item_Types[5]);
	WardensOffice->AddItemToRoom(roledex);
	WardensOffice->AddItemToRoom(cellphone);
	WardensOffice->AddItemToRoom(wardensMug);

	Item phoneCharger("Phone Charger", "Charger for a cell phone, if anyone even has one of those in here", Item_Types[5]);
	Item soda("Soda", "Can of Soda, no longer being served in the cafeteria due to food fight incidents, very popular with other inmates", Item_Types[5]);
	contrabandCloset->AddItemToRoom(phoneCharger);
	contrabandCloset->AddItemToRoom(soda);


	//adding people to rooms

	//creating fork as questgiver with 2 quests
	QuestGiver* fork = new QuestGiver("Fork", "You're cellmate", "QUESTGIVER");
	fork->greetings = { "Hey cellie", "sup, cellie?", "How's it hanging, cellie?", "What's up Cellie?", "Hey man" }; //special cell mate greetings
	//defining fork's quest
	Quest forkQuest = Quest("Hey cellie, you think you could get me a cookie from the cafeteria?", "Hey cellie, any word on my cookie?", "Oh man, thanks for the cookie cellie. Here, take this in return.");
	forkQuest.itemsToGive.push_back(Item("Pills", "Anxiety Pills, prisoners take them to feel better about themselves", Item_Types[5]));
	fork->quests.push_back(forkQuest);
	Quest forkQuest2 = Quest("Hey one more thing, could you get me an apple too, I've got my old lighter here I could give to ya in return", "could you get me apple from the cafe too, I'll give ya my old lighter in return", "Wow thanks so much, here you go");
	//giving fork's second quest and item to give to player
	forkQuest2.itemsToGive.push_back(Item("Lighter", "old zippo lighter, good for lighting up small spaces", Item_Types[5]));
	fork->quests.push_back(forkQuest2);


	QuestGiver* bob = new QuestGiver("Bob", "Line Cook, doesn't seem to like his job", "QUESTGIVER");
	Quest bobQuest = Quest("This is gonna sound weird but do you think you could get me one of those cool trinkets? It would really brighten my day", "This is gonna sound weird but do you think you could get me one of those cool trinkets? It would really brighten my day", "Wow I didn't think you'd actually do it, Thanks! Hey by the way if you ever want to do your own laundry you can give this to Alex in the laundry room.");
	bobQuest.itemsToGive.push_back(Item("Permission Slip", "A small piece of paper, written is a permission form for the laundry room", Item_Types[3]));
	bob->quests.push_back(bobQuest);

	QuestGiver* james = new QuestGiver("James", "Guard watching over the cafe, he looks pretty anxious", "QUESTGIVER");
	Quest jamesQuest = Quest("Hey prisoner, if you can get me some pills I'll give you something in return", "Hey can you get me some pills, I'll give you something in return", "Alright thanks man...here you go");
	james->quests.push_back(jamesQuest);

	NPC* seth = new NPC("Seth", "Fellow Prisoner", "FRIEND"); // NPC who gives player info about crime in showers
	seth->greetings = { "Yo Mouse. You remember that one case in the papers with the tax fraud and the wife? Yeah well, turns out the wife wasn't in the hospital at all!\n""If I was that tax guy, I'd get out of here and get my revenge...\n" };

	QuestGiver* dan = new QuestGiver("Dan", "Fellow inmate sitting in a chair by the tv, looks like he's fiddling with the remote", "QUESTGIVER");
	Quest danQuest = Quest("Hey you, could you help me out, I'm trying to find a tv station but this remote seems to need batteries, could you get me some?", "could you help me out, I'm trying to find a tv station but this remote seems to need batteries, could you get me some?", "Oh wow, thanks so much man, here take this in return");
	danQuest.itemsToGive.push_back(Item("Salt", "Simple Table Salt, prisoners often complain about the lack of seasoning in the cafeteria", "Valuable"));
	dan->quests.push_back(danQuest);
	Quest danQuest2 = Quest("Oh and if you get me a phone charger, I'll give you something valuable", "Oh and if you get me a phone charger, I'll give you something valuable", "Great, I really need to call some people, thanks");
	danQuest2.itemsToGive.push_back(Item("Radio", "Pocket-Sized Transistor Radio", "Valuable"));
	dan->quests.push_back(danQuest2);

	QuestGiver* will = new QuestGiver("Will", "Fellow inmate sitting at a table on the far side of the prison", "QUESTGIVER");
	Quest willQuest = Quest("Man this food is awful, there's barely any flavor at all, if only I had some salt or something", "This food is too bland, if only I had some salt or something", "Thanks dude, now I can at least taste my food. Here, you can have this trinket, I don't reallyve a need for it");
	willQuest.itemsToGive.push_back(Item("Trinket", "A tiny trinket hanging on a small chain, looks like it could be valuable to someone", "Valuable"));
	will->quests.push_back(willQuest);
	Quest willQuest2 = Quest("Thanks again for the salt, but now I'm thirsty and I don't really want water. Think you could get me a soda?", "Thanks again for the salt, but now I'm thirsty and I don't really want water. Think you could get me a soda?", "Thanks, now I can eat my food properly. Hey by the way, I know the passcode to the warden's office, it's 5182, but don't tell anybody!");
	will->quests.push_back(willQuest2);

	QuestGiver* alex = new QuestGiver("Alex", "Fellow inmate, in charge of the laundry staff, seems somewhat friendly", "QUESTGIVER");
	Quest alexQuest = Quest("Hey friend, how are you, if you want to do you own laundry here you'll need a permission slip", "Hey friend, if you wanna do your own laundry here you'll need a permission slip", "Oh I see you got a permission slip, you can do you're laundry in here");
	alex->quests.push_back(alexQuest);
	Quest alexQuest2 = Quest("Hmmm, you seem like you don't like being here, you probably want to escape, right?\n you know if you can steal each item of a guards uniform you could just waltz right out of the prison.\nThere's a few pieces in here already, and if you do a few things for me, I'll get you the rest.\nYou can start by getting me a radio to listen to.", "Hmmm, you seem like you don't like being here, you probably want to escape, right?\n you know if you can steal each item of a guards uniform you could just waltz right out of the prison.\nThere's a few pieces in here already, and if you do a few things for me, I'll get you the rest.\nYou can start by getting me a radio to listen to.", "Alright thanks, I really appreciate it. Here's a guard's hat.");
	alexQuest2.itemsToGive.push_back(Item("Guards Hat", "A black guards hat, can be used to wear in order to escape", Item_Types[5]));
	alex->quests.push_back(alexQuest2);
	Quest alexQuest3 = Quest("Okay, now I'll get you the guard's pants, but this time I'll need you to get me something special, the warden's Roledex, it's on his desk and it's got all his important information in it.", "Okay, now I'll get you the guard's pants, but this time I'll need you to get me something special, the warden's Roledex, it's on his desk and it's got all his important information in it.", "You got it and made it out in one piece? Impressive, Here you go, good luck with your escape!");
	alexQuest3.itemsToGive.push_back(Item("Guards Pants", "Pants worn by the guard's in this prison, can be worn in order to escape", Item_Types[5]));
	alex->quests.push_back(alexQuest3);

	Trader* greg = new Trader("Greg", "Gym Trader", "TRADER");
	Trader* bill = new Trader("Bill", "Gym Trader", "TRADER");
	Trader* john = new Trader("John", "Gym Trader", "TRADER");

	greg->TradeTable["Plate"] = Item("Lighter", "A silver zippo lighter, good for lighting up dark places", Item_Types[5]);
	greg->TradeTable["Razor"] = Item("Matches", "A small box of striking matches", Item_Types[5]);
	bill->TradeTable["Apple"] = Item("Wrench", "A silver hand wrench", Item_Types[5]);
	bill->TradeTable["Cookie"] = Item("Flashlight", "A handheld, battery powered flashling", Item_Types[5]);
	john->TradeTable["Warden's Holiday Mug"] = Item("Baton", "A large police baton, must have been stolen from a guard", Item_Types[1]);

	//enemies
	Enemy* josh = new Enemy("Josh", "Bad Guy", "ENEMY", 20, 5, Item("Knife", "A knife", Item_Types[1]));

	Trader* adam = new Trader("Adam", "Courtyard Trader", "TRADER");
	adam->TradeTable["Weight"] = Item("Shank", "A shank", Item_Types[1]);

	//creating guard
	Guard* phil = new Guard("Phil", "Prison Guard standing on the far side of the hallway, he occasionally stares at you", "GUARD");
	Guard* andrew = new Guard("Andrew", "Prison Guard, you see him look around the hallway, occasionally glancing at you", "GUARD");

	//adding everyone to their rooms
	cell->AddNPCToRoom(fork);

	cafe->AddNPCToRoom(bob);
	cafe->AddNPCToRoom(james);
	cafe->AddNPCToRoom(will);

	commonRoom->AddNPCToRoom(dan);

	gym->AddNPCToRoom(greg);
	gym->AddNPCToRoom(bill);
	gym->AddNPCToRoom(john);

	laundryRoom->AddNPCToRoom(alex);

	courtYard->AddNPCToRoom(josh);
	courtYard->AddNPCToRoom(adam);

	showers->AddNPCToRoom(seth);

	hallway->AddNPCToRoom(phil);

	westWingHallway->AddNPCToRoom(andrew);

}

//prison destructor
Prison::~Prison() {
	delete cell, cafe, hallway, commonRoom, workshopRoom, gym, showers, courtYard, WardensOffice, airlock, westWingHallway, eastWingHallway, contrabandCloset;

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
			currentRoom->numTimesInRoom++;

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
			currentRoom->numTimesInRoom++;
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
			currentRoom->numTimesInRoom++;
		}
		else {
			cout << "No Room behind you.\n";
		}
	}
	else if ((answer == "forward") || (answer == "FORWARD") || (answer == "f") || (answer == "F") || (answer == "Forward")) {
		if (currentRoom->forwardRoom != nullptr) {
			currentRoom = currentRoom->forwardRoom;
			cout << "Moving into " << currentRoom->getName() << ".....\n";
			LoseDayLight(1);
			currentRoom->numTimesInRoom++;

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
		cout << "Sorry, I don't understand what you want to do here.\n";
	}


}


void Prison::PrintRoom() {
	cout << "You are currently inside " << currentRoom->getName() << "\n\n\n";
}

void Prison::RefreshTraderTables() {
	//consider putting this in a loop of everyone in the gym and if they have trader IDs refresh their tables
	gym->getNPC("Greg")->RefreshTable();
	gym->getNPC("Bill")->RefreshTable();
	gym->getNPC("John")->RefreshTable();

	courtYard->getNPC("Adam")->RefreshTable();
}


void Prison::Inspection() {
	cout << "Two guards enter you're cell as you wake up....\n";
	cout << Guard::getInspectionGreeting();
	vector<Item> itemsToConfiscate = cell->GetContraband();
	if (itemsToConfiscate.size() > 0) {
		for (int i = 0; i < itemsToConfiscate.size(); i++) {
			cout << "The guards find your " << itemsToConfiscate[i].getName() << "...They take it to the contraband closet!\n";
			contrabandCloset->AddItemToRoom(itemsToConfiscate[i]);
			cell->RemoveItemFromRoom(itemsToConfiscate[i].getName());
		}
	}else{
		cout << "The guards did not find any contraband in your room.\n";
	}
	
	
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