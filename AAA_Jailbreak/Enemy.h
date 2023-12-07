#pragma once
#define ENEMY_H
#include "NPC.h"

class Enemy : public NPC {
    int health;
    int strength;

    Item wp;
    vector<Item> loot;

public:
    Enemy(string, string, string, int, int, Item);

    string FightDialogue();




};

