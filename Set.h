//
// Created by ise on 2/25/24.
//

#ifndef UNTITLED_SET_H
#define UNTITLED_SET_H
#include "Card.h"
#include <list>
using namespace std;

class Set {
private:
    list<Card*> m_Cards;
    int m_Value;
    bool m_D_effect;
    bool m_H_effect;
    bool m_C_effect;
    bool m_S_effect;

public:
    Set();
    Set(const list<Card*>& Cards);
    ~Set();
    int Get_Value() const{return m_Value;};
    int Get_Size(){return m_Cards.size();};
    bool IS_D_Exist() const{return m_D_effect;};
    bool IS_H_Exist() const{return m_H_effect;};
    bool IS_C_Exist() const{return m_C_effect;};
    bool IS_S_Exist() const{return m_S_effect;};
    void Flip_D(){m_D_effect=!m_D_effect;}
    void Flip_H(){m_H_effect=!m_H_effect;}
    void Flip_C(){m_C_effect=!m_C_effect;}
    void Flip_S(){m_S_effect=!m_S_effect;}
    const Set& operator=(const Set &other);
    friend ostream& operator<<(ostream& out,Set& D);
    status Update_Set(const list<Card*>& Cards);
    void Update_Value(int new_Value){m_Value=new_Value;}
    //Reaching the object Private from Character!!
    friend class Character;


};


#endif //UNTITLED_SET_H
