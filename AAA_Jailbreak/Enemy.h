#pragma once
#include <string>
#include <iostream>
#include "Item.h"
#include "NPC.h"
#include <map>

class Enemy : public NPC {
    int health;
    int strength;

    Item wp;
    vector<Item> loot;

public:
    Enemy(string n, string desc, string id, int h, int s, Item w);


};