#include "Enemy.h"
#include "Room.h"
#include "NPC.h" 

Enemy::Enemy(string n, string desc, string id, int h, int s, Item w, Item droppable) {
        name = n;
        description = desc;
        ID = id;
        health = h;
        strength = s;
        wp = w;
}
int Enemy::getHealth()
{
    return health;
}

void Enemy::takeDamage(Room* r, int damage)
{
    health -= damage;
    if (health == 0)
    {
        //drop item 
        //remove NPC from the room
        r.RemoveNPCFromRoom(getName());
      
    }
}

void Enemy::attack(NPC* e,int number)
{
  
  
    switch (number)
    {
        //attack with fist
    case 1: 
        cout<< e->getName() << " threw a left hook, think fast!"
        break;
        //attack with wepon
    case 2:
        cout << e->getName() << " tried to use a " << e->getWepon() << endl;
        break;
        //attack with graple
    case 3:
        cout << e->getName() << "grabbed you, what will you do? \n";
        break;
        //headbutt
    case 4: 
        cout << e->getName() << " is trying to headbutt you. \n";
        break;
        //attack
    case 5: 
        cout << e->getName() << "threw a right hook\n";
        break;

    } 
}

string Enemy::getWepon()
{
    return wp;
}

void Enemy::dropLoot(Room* r, NPC* e)
{
    for (int i = 0; i < loot.size(); i++)
    {
        r->AddItemToRoom(i);
        cout << "Items dropped: \n";
        cout << "-" << i << endl;
    }
}

int Enemy::getStrength()
{
    return strength;
}


void Enemy::dropLoot(Enemy opp)
{
}
