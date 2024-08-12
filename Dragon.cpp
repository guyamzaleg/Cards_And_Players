//
// Created by ise on 3/1/24.
//

#include "Dragon.h"

Dragon::Dragon(): Enemy(75,10){};
void Dragon::FightAgainstFighter(Character &F)
{
    if (F.Get_Cuerrent_Set().IS_D_Exist())
        F.Get_Cuerrent_Set().Flip_D();
    battle(F);
}

void Dragon::FightAgainstSorcerer(Character &S)
{
    if (S.Get_Cuerrent_Set().IS_C_Exist() && S.Get_Cuerrent_Set().IS_S_Exist())
        S.Get_Cuerrent_Set().Update_Value(S.Get_Cuerrent_Set().Get_Value()/2);
    battle(S);
}

void Dragon::FightAgainstRanger(Character &R)
{
    if (R.Get_Cuerrent_Set().IS_H_Exist())
        R.Get_Cuerrent_Set().Flip_H();
    battle(R);
};