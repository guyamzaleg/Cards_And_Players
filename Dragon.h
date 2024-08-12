//
// Created by ise on 3/1/24.
//

#ifndef UNTITLED_DRAGON_H
#define UNTITLED_DRAGON_H
#include "Enemy.h"

class Dragon : public Enemy{
private:

protected:

public:
    Dragon();
    virtual void FightAgainstFighter(Character& F) ;
    virtual void FightAgainstSorcerer(Character& S) ;
    virtual void FightAgainstRanger(Character& R) ;

};


#endif //UNTITLED_DRAGON_H
