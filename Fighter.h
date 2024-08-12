//
// Created by ise on 2/25/24.
//

#ifndef UNTITLED_FIGHTER_H
#define UNTITLED_FIGHTER_H

#include "Character.h"
#include "Enemy.h"

class Fighter : public Character
{

private:

public:
Fighter();
virtual ~Fighter(){};
//virtual status Set_personal_Deck();
//status print_personal_Deck();
virtual void Fight(Enemy* E);

};


#endif //UNTITLED_FIGHTER_H
