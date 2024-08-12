//
// Created by ise on 3/1/24.
//

#ifndef UNTITLED_SORCERER_H
#define UNTITLED_SORCERER_H
#include "Character.h"
#include "Enemy.h"

class Sorcerer: public Character {

private:

public:
    Sorcerer();
    virtual ~Sorcerer(){};
    virtual void Fight (Enemy* E);

};


#endif //UNTITLED_SORCERER_H
