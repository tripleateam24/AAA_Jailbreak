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
    //Return enemy health


    int getHealth();

    

    //Give ability to take damage


    void takeDamage(int damage);

    Item dropLoot();
    //function that allows computer to attack


    void attack(NPC* e, int num);


    //return the type of wepon the opp has


    string getWeponName();


    //upon dying the opp would drop its items
    //JP3 Causes import loop + unused
    //void dropLoot(Prison* prison, NPC* e);
    //3PJ


    //return strength


    int getStrength();


};