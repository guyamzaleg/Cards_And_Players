//
// Created by ise on 3/1/24.
//

#include "Ghost.h"

Ghost::Ghost(): Enemy(50,15){};
void Ghost::FightAgainstFighter(Character &F)
{
    if (F.Get_Cuerrent_Set().IS_C_Exist() && F.Get_Cuerrent_Set().IS_S_Exist())
        F.Get_Cuerrent_Set().Update_Value(F.Get_Cuerrent_Set().Get_Value()/2);
    battle(F);
}

void Ghost::FightAgainstSorcerer(Character &S)
{
    if (S.Get_Cuerrent_Set().IS_H_Exist())
        S.Get_Cuerrent_Set().Flip_H();
    battle(S);
}

void Ghost::FightAgainstRanger(Character &R)
{
    if (R.Get_Cuerrent_Set().IS_D_Exist())
        R.Get_Cuerrent_Set().Flip_D();
    battle(R);
};