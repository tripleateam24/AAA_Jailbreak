#pragma once
#define TRADER_H
#include "NPC.h"
#include <map>

class Trader : public NPC {
public:
    //trade table map for traders
    map<string, Item> TradeTable;

    Trader();
    Trader(string, string, string);

    void AddTradeableItem(Item, string);


    bool SearchForTradeItem(string);

    string ItemToGiveToTrader(string);

    Item getItemFromTrader(string);

    void PrintTradeTable();
    void DeleteTradeItem(string);

    string getGreeting();



};