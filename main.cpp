#include "Memory_Error.h"

#include "Card.h"
#include "Deck.h"
#include "Set.h"

#include "Character.h"
#include "Fighter.h"
#include "Sorcerer.h"
#include "Ranger.h"

#include "Enemy.h"
#include "Troll.h"
#include "Ghost.h"
#include "Dragon.h"

#include <string.h>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;



//==================================================
//Main Functionality Declarations
//==================================================
bool Is_List_Valid_Set(list<Card*>& S);
//status Loading_Set(Character* C1);
//==================================================
int main()
{

   //1-Initialize Deck
   try {
       Character::Initialize_Game_Deck();
   }
   catch(exception& Mem)
   {
       Mem.what();
	 return 0;
   }
    //2-Choose Character And Enemy
    int Character_Type;
    int Enemy_Type;
    bool Character_Created= false;
    bool Enemy_Created= false;
    Character* C1 = nullptr;
    Enemy* E1 = nullptr;

        cout << "Choose player character:\n"
                "(1) Fighter (2) Sorcerer (3) Ranger" << endl;
        cin >> Character_Type;
        switch (Character_Type) {
            case 1:
            {
//                cout << "Fighter" << endl;
                C1 = new Fighter();
                Character_Created = true;
                break;
            }
            case 2:
            {
//                cout << "Sorcerer" << endl;
                C1=new Sorcerer();
                Character_Created = true;
                break;
            }
            case 3:
            {
//                cout << "Ranger" << endl;
                C1=new Ranger();
                Character_Created = true;
                break;
            }

            break;
        }
    if (!C1) {
        delete Character::Game_Deck;
        Memory_Error().what();
        return 0;
    }
        cout << "Choose enemy character:\n"
                "(1) Troll (2) Ghost (3) Dragon" << endl;
        cin >> Enemy_Type;
        switch (Enemy_Type) {
            case 1:
            {
//                cout << "Troll" << endl;
                E1 = new Troll();
                Enemy_Created = true;
                break;
            }
            case 2:
            {
//                cout << "Ghost" << endl;
                E1=new Ghost();
                Enemy_Created = true;
                break;
            }
            case 3:
            {
//                cout << "Dragon" << endl;
                E1=new Dragon();
                Enemy_Created = true;
                break;
            }
               break;
        }
    if (!E1) {
        delete Character::Game_Deck;
        Memory_Error().what();
        return 0;
    }
        if(!Enemy_Created || !Character_Created)
        {
            cout<<"invalid numbers"<<endl;
            return 0;
        }

    //
    status Deck_Available=success;
    Deck_Available=C1->Set_personal_Hand();
    if (!Deck_Available)
        cout<<"Deck ran out"<<endl;
    //Stage 3 and 4
    while(C1->is_Alive() && E1->is_Alive() && Deck_Available)
    {
        cout<<"Player health: "<<C1->Get_m_Life()<<endl;
        cout<<"Enemy health: "<<E1->Get_m_Life()<<endl;
        cout<<"Player hand"<<endl;
        C1->Print_Personal_Hand();
        if (C1->Get_Hand_Size()==0) {
            cout << "no Hand Available";
            return 0;
        }
        //=========================================================
        // Set Input
        list<Card *> new_Cards;
        bool ListIsValid = false;
        Card *C;
        string str = "";
        while (!ListIsValid) {
            str.clear();
            cout << "Insert card set to play" << endl;
            getline(cin >> ws, str);
            if (str == "exit")
            {
                //Safe Exit -delete all
                auto iter = new_Cards.begin();
                for (iter; iter != new_Cards.end(); iter++) {
                    delete *iter;
                }
                delete C1;
                delete E1;
                return 0;
            }
            stringstream ss(str);
            string Curr;
            while (ss >> Curr) {
//                cout << Curr;
                C = new Card(Curr[0], Curr[1]);    //Create Card
                if (!C)
                {
                    Memory_Error().what();
                    auto iter = new_Cards.begin();
                    for (iter; iter != new_Cards.end(); iter++) {
                        delete *iter;
                    }
                    delete C1;
                    delete E1;
                    return 0;

                }
                new_Cards.push_front(C);                  //Push it to the list
            }
            if (Is_List_Valid_Set(new_Cards))
            {
                ListIsValid = true;
                C1->Set_Current_Set(new_Cards);
//                cout << "Current Set After Update is:" << endl;
//                cout << (C1->Get_Cuerrent_Set()) << endl;
//                cout << "Personal Hand After Turn is:" << endl;
//                (C1->Print_Personal_Hand());
            }
            else
            {
                cout << "Card set is not valid" << endl;
                auto iter = new_Cards.begin();
                for (iter; iter != new_Cards.end(); iter++) {
                    delete *iter;
                }
                new_Cards.clear();
            }

        }
        //inside Fight-each unique combination affect takes part using PolyMorphism
        C1->Fight(E1);
        Deck_Available=C1->Set_personal_Hand();
        if (!Deck_Available && C1->is_Alive() && E1->is_Alive())
        {
            cout<<"Deck ran out"<<endl;
        }
        auto iter = new_Cards.begin();
        for (iter; iter != new_Cards.end(); iter++) {
            delete *iter;
        }
    }
    //========================================================
    //FREE!!!!!
    //========================================================
    delete C1;
    delete E1;
    //=========================================================
}

//==================================================
//Main Functionality Implements
//==================================================
bool Is_List_Valid_Set(list<Card*>& C)
{
    if (C.size()>5)
        return false;
    int total_value=0;
    if (C.size()==1)
        return true;
    auto iter=C.begin();
    int Aces = 0;
    int first=(*iter)->get_Value();
    int curr=0;
    //if the first is Ace-Add to Aces,and move forward iter and first.
    if (first==1)
    {
        Aces++;
        iter++;
        first = (*iter)->get_Value();
        if (C.size()==2)
            return true;
        if (first==1) {
            first = (*iter)->get_Value();
            Aces++;
            //next Ace is invalid
        }
    }
    for (iter; iter != C.end() ; iter++)
    {
        curr=(*iter)->get_Value();
        if ( curr == 1)
        {
            if (Aces == 2) {
                return false;
            }
            Aces++;
        }
        else
        {
            //Check the Card is As the last one
            total_value += curr;
            //Checking all Cards with same rank(T,J "bug"(equal rank)  will pass  outside the loop because T+J>10)
            if (curr != first)
                return false;
        }
        if(Aces==2)
        {
            total_value += curr;
            //Checking all Cards with same rank(T,J "bug"(equal rank)  will pass  outside the loop because T+J>10)
            if (curr != first)
                return false;
        }
    }
    if (total_value>10 || Aces>2||C.size()-Aces>4)
        return false;
    return true;
}


