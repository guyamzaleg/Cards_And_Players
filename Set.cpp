//
// Created by ise on 2/25/24.
//
#include "Set.h"

//Constructors
Set::Set() : m_D_effect(false),m_H_effect(false),m_S_effect(false),m_C_effect(false),m_Value(0){}


Set::Set(const list<Card*>& Cards)
{
    auto iter=Cards.begin();
    m_Value=0;
    m_D_effect= false;
    m_H_effect= false;
    m_C_effect= false;
    m_S_effect= false;
    for(iter; iter != Cards.end(); iter++)
    {
//        cout<<(*iter)->get_Rank()<<endl;
        m_Value+=(*iter)->get_Value();
        if((*iter)->get_Suit()=='D')
           m_D_effect=true;
        if((*iter)->get_Suit()=='H')
            m_H_effect=true;
        if((*iter)->get_Suit()=='C')
            m_C_effect=true;
        if((*iter)->get_Suit()=='S')
            m_S_effect=true;
        m_Cards.push_front(*iter);
    }
    if (m_S_effect && m_C_effect)
        m_Value*=2;
}

ostream &operator<<(ostream &out, Set &S)
{
    auto iter=S.m_Cards.begin();
    for(iter; iter != S.m_Cards.end(); iter++)
    {
        cout<<(**iter)<<endl;
    }
    return out;
}

status Set::Update_Set(const list<Card *> &new_Cards) {
    this->m_Cards.clear();
    Set new_Set(new_Cards);
    *this=new_Set;
    return success;
}

const Set &Set::operator=(const Set &other) {
    m_Cards=other.m_Cards;
    m_Value=other.m_Value;
    m_D_effect=other.m_D_effect;
    m_H_effect=other.m_H_effect;
    m_C_effect=other.m_C_effect;
    m_S_effect=other.m_S_effect;

    return *this;
}

Set::~Set() {
//    auto iter=m_Cards.begin();
//    for(iter; iter != m_Cards.end(); iter++)
//    {
//        delete *iter;
//    }

}


