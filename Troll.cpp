//
// Created by ise on 2/25/24.
//

#include "Troll.h"

Troll::Troll(): Enemy(100,5){}

void Troll::FightAgainstFighter(Character &F)
{
    if (F.Get_Cuerrent_Set().IS_H_Exist())
        F.Get_Cuerrent_Set().Flip_H();
    battle(F);
}

void Troll::FightAgainstSorcerer(Character &S)
{
    if (S.Get_Cuerrent_Set().IS_D_Exist())
        S.Get_Cuerrent_Set().Flip_D();
    battle(S);
}

void Troll::FightAgainstRanger(Character &R)
{
    if (R.Get_Cuerrent_Set().IS_C_Exist() && R.Get_Cuerrent_Set().IS_S_Exist())
        R.Get_Cuerrent_Set().Update_Value(R.Get_Cuerrent_Set().Get_Value()/2);
    battle(R);
};