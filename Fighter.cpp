//
// Created by ise on 2/25/24.
//

#include "Fighter.h"

Fighter::Fighter(): Character(60,6){};

//status Fighter::print_personal_Deck()
//{
//    Character::Print_Personal_Hand();
//    return success;
//}

//i NEED TO understand how to distinct between subclass with the method Signature
//Send A Enemy* and 3 functions(one recieves Troll*,one Ghost* and one Dragon*)
void Fighter:: Fight(Enemy* E)
{
    E->FightAgainstFighter(*this);
}


