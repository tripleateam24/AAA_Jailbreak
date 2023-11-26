#include "Enemy.h"
#include <iostream>
#include "NPC.h" 
using namespace std;
Enemy::Enemy(string n, string desc, string id, int h, int s, Item w) {
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

int Enemy::takeDamage(int damage)
{
    return health = -damage;
}

void Enemy::attack(NPC* e, int number)
{
   /* switch (number)
    {
        //attack with fist
    case 1:
        cout << e->getName() << " threw a left hook, think fast!\n";
            break;
        //attack with wepon
    case 2:
        cout << e->getName() << " tried to use a " << e->getWeponName() << endl;
        break;
        //attack with graple
    case 3:
        cout << e->getName() << "grabbed you, what will you do? \n";
        break;
        //headbutt
    case 4:
        cout << e->getName() << " is trying to headbutt you. \n";
        break;
        //attack with right hook
    case 5:
        cout << e->getName() << "threw a right hook\n";
        break;

    }*/
}
string Enemy::getWeponName()
{
    string weponName = wp.getName();
    return weponName; 
}

void Enemy::dropLoot(Prison* prison, NPC* e)
{
    for (int i = 0; i < loot.size(); i++)
    {
        prison->currentRoom->AddItemToRoom(loot[i]);
        cout << "Dropped: " << loot[i].getDescription() << endl;
    }
    
}

int Enemy::getStrength()
{
    return strength;
}
