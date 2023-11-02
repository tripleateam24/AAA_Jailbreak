#pragma once
#include <string>
#include <iostream>
#include "Item.h"
#include "NPC.h"
#include <map>

class Trader : public NPC {
public:
    map<string, Item> TradeTable;

    Trader();
    Trader(string n, string desc, string id);

    void AddTradeableItem(Item item, string price);


    bool SearchForTradeItem(string itemName);

    string ItemToGiveToTrader(string itemName);
    Item getItemFromTrader(string itemName);

    void PrintTradeTable();

    void DeleteTradeItem(string itemName);

};