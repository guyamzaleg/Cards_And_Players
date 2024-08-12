//
// Created by ise on 3/1/24.
//

#include "Ranger.h"
Ranger::Ranger(): Character(50,7){};
void Ranger::Fight(Enemy* E)
{
    E->FightAgainstRanger(*this);
}