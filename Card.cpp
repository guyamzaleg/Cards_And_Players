#include "Card.h"

//Constructors and Destructors
Card :: Card():m_Rank('0'), m_Suit('0'), m_Value(0),m_valid(false),m_suit_value(NONE){}
Card :: Card(char Rank, char Suit)
{
    status R, S;
    R = set_Rank(Rank);
    S = set_Suit(Suit);

    //not Legal Params-set default values
    if (R == failure || S == failure)
        *this = Card();
    else
        m_valid = true;
}

Card :: Card(const Card& source):m_Rank(source.m_Rank),m_Suit(source.m_Suit),m_Value(source.m_Value),m_valid(source.m_valid),m_suit_value(source.m_suit_value){}
Card:: ~Card(){} //no memory allocation-Compiler takes care for all the stack allocations.


//Getters and Setters
status Card:: set_Rank(char Rank)
{
    //Checking Card Rank Validate
    if ((Rank != 'T' && Rank != 'J' && Rank != 'Q' && Rank != 'K' && Rank != 'A' && Rank != '1' && Rank != '2' && Rank != '3' &&
         Rank != '4' && Rank != '5' && Rank != '6' && Rank != '7' && Rank != '8' && Rank != '9'))
        return failure;

    m_Rank=Rank;
    //set the Value according to Rank

    //It`s a number
    if ((int) m_Rank <= 57)
        m_Value = m_Rank - '0';

    //It`s a char
    switch (Rank)
    {
        case 'A':
            m_Value=1;
            break;
        case 'T':
        case 'J':
            m_Value = 10;
            break;
        case 'Q':
            m_Value = 15;
            break;
        case 'K':
            m_Value = 20;
            break;
    }
    return success;
}

status Card :: set_Suit(char Suit)
{
    //Checking Card Suit Validate
    if (Suit != 'C' && Suit != 'S' && Suit != 'H' && Suit != 'D')
        return failure;

    m_Suit = Suit;
    //set the suit_value According to m_suit

    switch (m_Suit)
    {
        case 'C':
            m_suit_value=CLUB;
            break;
        case 'S':
            m_suit_value=SPADE;
            break;
        case 'H':
            m_suit_value=HEART;
            break;
        case 'D':
            m_suit_value=DIAMOND;
            break;
    }
    return success;
}
//Operators
//    Card& Card ::operator=(const Card &other)
//    {
//        set_Suit(other.m_Suit);
//        set_Rank(other.m_Rank);
//    }
bool Card :: operator==(const Card &other) const
{
    return (m_Rank == other.m_Rank && m_Suit == other.m_Suit);
}
bool Card :: operator!=(const Card &other) const
{
    return !(*this==other);
}
bool Card :: operator<(const Card &other) const
{
    if (m_Value<other.m_Value)
        return true;
    if (m_Value==other.m_Value)
    {
        if (m_Rank == 'T' && other.m_Rank == 'J')
            return true;
        if (m_Rank == 'J' && other.m_Rank == 'T')
            return false;
        if (m_suit_value < other.m_suit_value)
            return true;
        else return false;
    }
    return false;
}
bool Card :: operator<=(const Card &other) const
{
    return (*this<other || *this==other);
}
bool Card :: operator>(const Card &other) const
{
    return !(*this<=other);
}
bool Card :: operator>=(const Card &other) const
{
    return (*this>other || *this==other);
}
ostream& operator<<(ostream& out,Card& C)
{
    out<<C.m_Rank<<C.m_Suit;
    return out;
}