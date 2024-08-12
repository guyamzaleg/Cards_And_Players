//
// Created by ise on 2/25/24.
//

#ifndef UNTITLED_ENEMY_H
#define UNTITLED_ENEMY_H
#include <iostream>
using namespace std;
#include "Fighter.h"
#include "Sorcerer.h"
#include "Ranger.h"
class Character;

class Enemy
{
protected:
    int m_Life;
    int m_max_Life;
    int m_Damage;
    bool m_is_Alive;
public:
    Enemy(int Life,int Damage);
    Enemy(const Enemy& other){};
    //Destructor
    virtual ~Enemy(){};

    inline const int& Get_m_Life() const{return m_Life;}
    inline const int& Get_Max_Cards() const{return m_Damage;}
    bool is_Alive(){return m_is_Alive;}
    void Died(){m_is_Alive= false;}
    void battle(Character& C);
    virtual  void FightAgainstFighter(Character& F)=0;
    virtual  void FightAgainstSorcerer(Character& S)=0;
    virtual  void FightAgainstRanger(Character& R)=0;

};

void Set_input(Character &C1 , Enemy &E1);

#endif //UNTITLED_ENEMY_H
