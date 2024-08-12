//
// Created by ise on 2/27/24.
//

#ifndef ASSIGNMENT3_CARD_H
#define ASSIGNMENT3_CARD_H

#include <iostream>
using namespace std;

enum suit_num{NONE,DIAMOND,HEART,SPADE,CLUB};
enum status{failure,success};
//N is Null-0;
class Card
{
private:
    char m_Rank;
    char m_Suit;
    suit_num m_suit_value;
    int m_Value;
    bool m_valid;

public:
    //Constructors and Destructor
    Card();
    Card(char Rank,char Suit);
    Card(const Card& source);
    ~Card();

    //Getters and Setters
    char get_Rank(){return m_Rank;};
    char get_Suit(){return m_Suit;};
    int get_Value(){return m_Value;};
    status set_Rank(char Rank);
    status set_Suit(char Suit);

    //Operators
//    Card& operator=(const Card &other);
    bool operator==(const Card &other) const;
    bool operator!=(const Card &other) const;
    bool operator<(const Card &other) const;
    bool operator<=(const Card &other) const;
    bool operator>(const Card &other) const;
    bool operator>=(const Card &other) const;
    friend ostream& operator<<(ostream& out,Card& C);

};


#endif //ASSIGNMENT3_CARD_H
