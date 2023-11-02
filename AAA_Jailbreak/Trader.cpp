#include "Trader.h"


Trader::Trader() {}
Trader::Trader(string n, string desc, string id) {
    name = n;
    description = desc;
    ID = id;
}

void Trader::AddTradeableItem(Item item, string price) {

}


bool Trader::SearchForTradeItem(string itemName) {
    for (auto item : TradeTable) {
        if (itemName == item.second.getName()) {
            return true;
        }
    }
    return false;
}

string Trader::ItemToGiveToTrader(string itemName) {
    for (auto item : TradeTable) {
        if (itemName == item.second.getName()) {
            return item.first;
        }
    }
}

Item Trader::getItemFromTrader(string itemName) {
    for (auto item : TradeTable) {
        if (itemName == item.second.getName()) {
            return item.second;
        }
    }
}

void Trader::PrintTradeTable() {
    map<string, Item>::iterator it = TradeTable.begin();

    cout << name << "'s Trading:\n";
    cout << "===============================\n";
    cout << "I receive:\t  You receive:\n";
    cout << "------------------------------\n";
    while (it != TradeTable.end()) {
        cout << it->first << "\t\t   " << it->second.getName() << ": " << it->second.getDescription() << "\n\n";
        ++it;
    }
    cout << "===============================\n\n";

}

void Trader::DeleteTradeItem(string itemName) {
    TradeTable.erase(ItemToGiveToTrader(itemName));
}


