//
// Created by ise on 2/25/24.
//

#ifndef UNTITLED_CHARACTER_H
#define UNTITLED_CHARACTER_H
#include "Deck.h"
#include "Set.h"
class Enemy;//For not Creating infinite Loop of includes
#include <list>
//Will be Pure Virtual
class Character
{
protected:
    int m_Life;
    int m_Max_Cards;//maybe const
    int m_max_Life;
    list<Card> m_personal_Hand;
    Set* m_Current_Set;
    bool m_is_Alive;
    int pulled;
public:
    //static member of Character include in it all The Game Deck
    static Deck* Game_Deck;

    //Constructors
    Character(int Life,int Max_Cards);
    Character(const Character& other);
    //Destructor
    virtual ~Character();
    static status Initialize_Game_Deck();
    //Getters to members in Class
    const int& Get_m_Life() const{return m_Life;}
    const int& Get_Max_Cards() const{return m_Max_Cards;}
    int Get_Hand_Size() const{return m_personal_Hand.size();}
    Set& Get_Cuerrent_Set() {return *m_Current_Set;}
    int get_max_Life() const{return m_max_Life;}
    void set_m_Life(int x){m_Life=x; }
    bool is_Alive(){return m_is_Alive;}
    void Died(){m_is_Alive= false;}
    //Functionality of Character
    status input_Set();
    status Set_personal_Hand();
    status Set_Current_Set(const list<Card*>& Cards);
    static void Print_Game_Deck();
    void Print_Personal_Hand();
    virtual void Fight(Enemy* E)=0;
};


#endif //UNTITLED_CHARACTER_H
