//
// Created by ise on 2/27/24.
//

#ifndef ASSIGNMENT3_DECK_H
#define ASSIGNMENT3_DECK_H

#include "Card.h"

class Deck
{
private:
    Card** m_List;
    int m_size;
public:
    //Constructors and destructor
    Deck();
    Deck(const Deck& source);
    ~Deck();

    //Getters
    int get_size(){return m_size;};
    Card** get_m_List() {return m_List;};

    //operators
    status operator +=(const Card &new_card);
    status operator += (const Deck& new_cards);
    status operator -=(int X);
    Card* operator[](int X);

    //Methods
    status set_Card_in_index(Card* C , int i);
    void  TakeALook(int X)const;
    friend ostream& operator<<(ostream& out,Deck& C);
    bool Deck_Contains(Card& C);
    status free_Deck();
};


#endif //ASSIGNMENT3_DECK_H
