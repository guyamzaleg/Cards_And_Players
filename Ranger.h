//
// Created by ise on 3/1/24.
//

#ifndef UNTITLED_RANGER_H
#define UNTITLED_RANGER_H
#include "Character.h"
#include "Enemy.h"

class Ranger : public Character{

private:

public:
    Ranger();
    virtual ~Ranger(){};
    virtual void Fight (Enemy* E);

};



#endif //UNTITLED_RANGER_H
