#pragma once
#define TRADER_H
#include "NPC.h"
#include <map>

class Trader : public NPC {
public:
    //trade table map for traders
    map<string, Item> TradeTable;
    //TODO: Add more trading items, at least 20
    vector<string> possibleItemsToGive = {"Bottled Water", "Astronomy Book", "Soap", "Shampoo Bottle", "Plate", "Razor", "Apple", "Cookie", "Shank", "Tooth Brush", "Tuna", "Matches", "Flashlight", "Paintbrush", "TV Remote"};
    vector<Item> possibleItemsToBeGiven = { Item("Candy Bar", "A small, chocolate candy bar", "Consumeable"),
                                          Item("Makeshift Knife", "A small, makeshift knife made from a a toothbrush and razor blade", "Wepons"),
                                          Item("Pills", "Anxiety Pills, prisoners often take these to help feel better about themselves", "objective_item"),
                                          Item("Salt", "Simple Table Salt, prisoners often complain about the lack of seasoning in the cafeteria", "Valuable"),
                                          Item("Lighter", "A silver zippo lighter, good for lighting up dark places", "objective_item"),
                                          Item("Matches", "A small box of striking matches", "objective_item"),
                                          Item("Wrench", "A silver hand wrench", "objective_item"),
                                          Item("Flashlight", "A handheld, battery powered flashling", "objective_item"),
                                          Item("Phone Charger", "Charger for a cell phone, if anyone even has one of those in here", "objective_item"),
                                          Item("Trinket", "A tiny trinket hanging on a small chain, looks like it could be valuable to someone", "Valuable"),
                                          Item("Pen", "A blue ballpoint pen, nothing too fancy about it", "potential_Wepons"),
                                          Item("Ramen", "A pack of instant Ramen, very popular with prisoners", "Consumeable"),
                                          Item("Radio", "Pocket-Sized Transistor Radio", "Valuable"),
                                          Item("TV Remote", "Television remote for the TV inside the common room", "Valuable"),
                                          Item("Soda", "Can of soda, no longer served in the cafeteria due to food fight incidents, very popular with prisoners", "Valuable")
    };
                                          
//"Consumeable","Wepons","potential_Wepons","Throwable","key_Item", "objective_item", "Valuable"

    Trader();
    Trader(string, string, string);

    void AddTradeableItem(Item, string);


    bool SearchForTradeItem(string);

    string ItemToGiveToTrader(string);

    Item getItemFromTrader(string);

    void RefreshTable();

    void PrintTradeTable();
    void DeleteTradeItem(string);

    string getGreeting();



};