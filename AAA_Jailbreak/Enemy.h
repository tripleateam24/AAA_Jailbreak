#include <string>
#include <iostream>
#include "Item.h"
#include "NPC.h"
#include "Room.h"
#include <map>
#pragma once
using namespace std;
class Enemy : public NPC {
    int health;
    int strength;
    Item wp;
    vector<Item> loot;

public:
    Enemy(string n, string desc, string id, int h, int s, Item w, Item droppable);
    
    
    //Return enemy health
    
    
    int getHealth();
    
    
    //Give ability to take damage
    
    
    void takeDamage(Room* r,int damage);

    
    //function that allows computer to attack
    
    
    void attack(NPC* e,int num);
    
    
    //return the type of wepon the opp has
    
    
    string getWepon();
    
    
    //upon dying the opp would drop its items
    
    
    void dropLoot(Room* room,NPC* e);
    
    
    //return strength
  
    
    int getStrength();
};
