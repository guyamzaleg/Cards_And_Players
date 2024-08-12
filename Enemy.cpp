//
// Created by ise on 2/25/24.
//
#include "Enemy.h"
Enemy::Enemy(int Life,int Damage):m_Life(Life),m_is_Alive(true),m_Damage(Damage),m_max_Life(Life){}

////////////////////////////////////=================================================
////////////////////////////////////=================================================
void Enemy::battle(Character &C)
{
        int dealt_to_enemy = C.Get_Cuerrent_Set().Get_Value();
        int healed = 0;
        int took = m_Damage;
        //Using Diamonds Effect
        if (C.Get_Cuerrent_Set().IS_D_Exist())
            took = max(0, m_Damage - C.Get_Cuerrent_Set().Get_Value());
        //Using Hearts Effect
        if (C.Get_Cuerrent_Set().IS_H_Exist())
            healed = C.Get_Cuerrent_Set().Get_Value();
        //Using Clubs Spades doubling Set Value effect in the Set Value and
        //change it according to combination enemy-character
        //inside each enemy FightCharacter method

        //Stage 1 : Hurt Enemy
        m_Life = max(0, m_Life - dealt_to_enemy);
//        if (dealt_to_enemy != 0)
        cout << "Player dealt " << dealt_to_enemy << " points of damage" << endl;
        if (m_Life == 0) {
            this->Died();
            cout << "Player won" << endl;
            return;
        }

        //Stage 2 : Healing
        C.set_m_Life(min(C.Get_m_Life() + healed, C.get_max_Life()));
        if (healed != 0)
            cout << "Player healed " << healed << " points of damage" << endl;
        //Stage 3 : Take Damage
        C.set_m_Life(max(C.Get_m_Life() - took, 0));
    //        if (took != 0)
        cout << "Player took " << took << " points of damage" << endl;

    if (C.Get_m_Life() == 0) {
            C.Died();
            cout << "Player lost" << endl;
            return;
        }
};

////////////////////////////////////=================================================
////////////////////////////////////=================================================

