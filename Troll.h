//
// Created by ise on 2/25/24.
//

#ifndef UNTITLED_TROLL_H
#define UNTITLED_TROLL_H
#include "Enemy.h"

class Troll :public Enemy
{
private:

protected:

public:
    Troll();
    virtual void FightAgainstFighter(Character& F) ;
    virtual void FightAgainstSorcerer(Character& S) ;
    virtual void FightAgainstRanger(Character& R) ;
};


#endif //UNTITLED_TROLL_H
