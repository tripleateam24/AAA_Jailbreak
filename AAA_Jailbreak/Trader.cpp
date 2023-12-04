#include "Trader.h"

Trader::Trader() {}
Trader::Trader(string n, string desc, string id) {
    name = n;
    description = desc;
    ID = id;
    numTimesSpokenTo = 0;
    //default greetings for all traders
    greetings = { "Hey there, I got some nice items in store here.", "Hi, Wanna make a trade?", "I got some new items in stock", "Always nice to see a new customer", "I got some things you might like" };

}

void Trader::AddTradeableItem(Item item, string price) {
    TradeTable[price] = item;
}

//method to search for trade item
bool Trader::SearchForTradeItem(string itemName) {
    for (auto item : TradeTable) {
        if (itemName == item.second.getName()) {
            return true;
        }
    }
    return false;
}

//method to get the item player needs to complete trade
string Trader::ItemToGiveToTrader(string itemName) {
    for (auto item : TradeTable) {
        if (itemName == item.second.getName()) {
            return item.first;
        }
    }
}

//method to get the item from the trader 
Item Trader::getItemFromTrader(string itemName) {
    for (auto item : TradeTable) {
        if (itemName == item.second.getName()) {
            return item.second;
        }
    }
}

void Trader::RefreshTable() {
    TradeTable.clear();
    if ((possibleItemsToGive.size() == possibleItemsToBeGiven.size()) && (possibleItemsToGive.size() > 0)) {
        for (int i = 0; i < 5; i++) {
            int choice = rand() % possibleItemsToGive.size();
            AddTradeableItem(possibleItemsToBeGiven[choice], possibleItemsToGive[choice]);
        }
        
    }
}

//printing the trader's table
void Trader::PrintTradeTable() {
    map<string, Item>::iterator it = TradeTable.begin();

    cout << name << "'s Trading:\n";
    cout << "=====================================\n";
    cout << "I receive:\t  You receive:\n";
    cout << "------------------------------------\n";
    while (it != TradeTable.end()) {
        cout << it->first << "  \t\t" << it->second.getName() << ": " << it->second.getDescription() << "\n\n";
        ++it;
    }
    cout << "=====================================\n\n";

}

void Trader::DeleteTradeItem(string itemName) {
    TradeTable.erase(ItemToGiveToTrader(itemName));

}

string Trader::getGreeting() {
    int size = greetings.size();
    int choice = rand() % size;
    string dialogueSep = "\n============================================\n";
    cout << dialogueSep;
    return greetings[choice] + dialogueSep;

}