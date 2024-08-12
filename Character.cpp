
#include "Character.h"
#include <string.h>
#include "Memory_Error.h"
//static members and functions
//never deleted because the compiler is responsible for allocating and delete static members
//and when deleting a deck used ~deck which takes care of all the new cards inserted
Deck* Character::Game_Deck= nullptr;
void Character::Print_Game_Deck()
{
    cout<<*Game_Deck;
}

//methods implement
Character::Character(int Life,int Max_Cards):m_Life(Life),m_Max_Cards(Max_Cards),m_is_Alive(true),m_max_Life(Life), m_Current_Set(),pulled(0)
{
    Set* new_set=new Set();
    if (!new_set)
        throw Memory_Error();
    m_Current_Set=new_set;
    Set_personal_Hand();
}
Character::~Character()
{
    delete Game_Deck;
    delete m_Current_Set;
}
status Character::Initialize_Game_Deck()
{

    cout << "Initialize deck" << endl;
    char buffer[10];
    char OO[3] = "00";
    Deck *D =new Deck();
    if (!D)
        throw Memory_Error();
    status insert_status;
    cin >> buffer;
    while (strcmp(buffer, OO) != 0)
    {
        Card C(buffer[0],buffer[1]);
        insert_status=(*D+=C);

        if (!insert_status)
        {
            delete D;
            return failure;
        }
        cin >> buffer;
    }
    Game_Deck=D;
//    cout<<*Game_Deck;
    return success;
}
status Character::Set_personal_Hand()
{
    int how_many=0;
    int curr_size=m_personal_Hand.size();
    if (pulled==0)
        how_many=m_Max_Cards;
    if (pulled>0)
        how_many=min(2,(m_Max_Cards-curr_size));
    if (how_many > Game_Deck->get_size())
    {
        return failure;
    }
    Card* C;
        for (int i = 0; i <how_many ; i++)
        {
            C=Game_Deck->operator[](Game_Deck->get_size()-1);
            m_personal_Hand.push_front(*C);
            *Game_Deck-=1;
        }
        pulled++;

    return success;
}

void Character::Print_Personal_Hand() {
    auto iter=m_personal_Hand.begin();
    for(iter; iter != m_personal_Hand.end(); iter++)
    {
        cout<<(*iter)<<" ";
    }
    cout<<'\n';
}

Character::Character(const Character &other)
{

}

status Character::Set_Current_Set(const list<Card *> &Cards)
{
    m_Current_Set->m_D_effect= false;
    m_Current_Set->m_H_effect= false;
    m_Current_Set->m_C_effect= false;
    m_Current_Set->m_S_effect= false;
    //REMOVE the Cards that Used -from the Hand
    auto iter=Cards.begin();
    for(iter; iter != Cards.end(); iter++)
    {
       //remove **iter(Value) from m_personal_Hand
        m_personal_Hand.remove(**iter);
    }
    m_Current_Set->Update_Set(Cards);
    return success;
}

status Character::input_Set() {

    return success;
}
