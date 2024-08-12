//
// Created by ise on 3/1/24.
//

#include "Sorcerer.h"


Sorcerer::Sorcerer(): Character(40,8){};
void Sorcerer::Fight(Enemy* E)
{
    E->FightAgainstSorcerer(*this);
}
