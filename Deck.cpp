#include "Deck.h"
#include "Memory_Error.h"

//Default Constructor
Deck ::Deck()
{
    m_List= nullptr;//=nullptr;//=new Card*[0];
    m_size=0;
}
//Copy Constructor
Deck::Deck(const Deck &source)
{
    m_List=new Card* [source.m_size];
    if (!m_List)
        throw Memory_Error();
    m_size=source.m_size;
    for (int i = 0; i < m_size; i++)
    {
        Card* temp;
        temp=new Card();
        if (!temp)
            throw Memory_Error();
        else
        {
            //using default operator= of Card(bit by bit)
            m_List[i]=temp;
        }
    }
}
//Destructor
Deck::~Deck()
{
    if (m_List!=nullptr)
    {
        for (int i = 0; i < m_size; i++)
        {
            //Free all allocation made for cards inside the Deck
            delete m_List[i];
        }
    }
    delete[] m_List;
}

//Implement of operator +=
status Deck :: operator+=(const Card &new_card)
{
    Card** temp;
    temp=new Card*[m_size+1];
    if (!temp)
        throw Memory_Error();
    //insert to the bottom of the Deck(start of Array)
    //copy the exist Deck to temp
    for (int i = 0; i < m_size; i++)
    {
        temp[i+1] = m_List[i];
    }
    //Create the new Card and set a pointer to it in temp[0]
    temp[0]=new Card(new_card);
    //Checking allocation Validate
    if (!temp[0])
        return failure;
//    if (m_List!= nullptr)
    delete [] m_List;
    //Set the new List Pointer
    m_List=temp;
    //Increase List size in 1
    m_size++;
    return success;
}
//Adding Deck into existing Deck
status Deck :: operator+=(const Deck& new_cards)
{
    //+= overloaded for Deck+=other Deck: for each Card in the Deck,add it with += receives Card.
    for (int i = 0; i < new_cards.m_size; i++)
    {
        *this+=*(new_cards.m_List[i]);
    }
    return success;
}
//Implement of operator -=
status Deck :: operator -=(int X)
{
    //Checking number validate
    if (X < 0)
    {
        cout << "Invalid number" << endl;
        return failure;
    }

    //Checking the Deck is not empty
    if (m_size==0)
        return failure;

    //Set X to be the min of both.
    if (X>m_size)
        X=m_size;
    //Set a new list in temp in the size of the m_List after remove all Cards.
    Card **temp=new Card*[m_size-X];
    if (!temp)
        throw Memory_Error();
    //Copy the Card that will Stay after remove(from bottom)
    for (int i = 0; i < m_size-X; i++)
    {
        temp[i]=m_List[i];
    }
    //free the heap Space of Cards removed
    for (int i = m_size-X; i <m_size ; i++)
    {
        delete m_List[i];
    }
    //free the heap space of pointer that the cards they are point on got removed.
    delete [] m_List;
    //set the m_List to be temp and update the new size
    m_List=temp;
    m_size-=X;

    return success;
}

//implement of operator [] : Deck[i]-returns a pointer to the index i in Deck
Card* Deck::operator[](int X)
{
    //if index is invalid
    if (X<0 || X>=m_size)
    {
        return nullptr;
    }
    //return its place-the end of the list is the end of the deck
    return m_List[X];
}
//out<< For Deck-with a friend method
ostream& operator<<(ostream& out,Deck& D)
{
    out<<'[';
    if (D.m_size==0)
    {
        out<<']'<<endl;
        return out;
    }
    for (int i =0; i < D.m_size-1; i++)
    {
        out << *D.m_List[i] << ',';
    }
    out<<*D.m_List[D.m_size-1]<<']'<<endl;
    return out;
}
//implement of look on top X Cards
void  Deck :: TakeALook(int X)const
{
    if (X<0)
        cout<<"Invalid number"<<endl;
    else
    {
        if (X>m_size)
            X=m_size;

        for (int i = 0; i < X; i++)
            cout<<*m_List[m_size-1-i]<<"\n";
    }
}
status Deck ::set_Card_in_index(Card* C , int i)
{
    if (i>=m_size || i<0) {
        cout << "Invalid index" << endl;
        return failure;
    }
    delete m_List[i];
    m_List[i]=C;
    return success;
}

status Deck::free_Deck()
{
    if (m_List!=nullptr)
    {
        for (int i = 0; i < m_size; i++)
        {
            //Free all allocation made for cards inside the Deck
            delete m_List[i];
        }
    }
    delete[] m_List;
    return success;
}

bool Deck::Deck_Contains(Card &C)
{
    for (int i = 0; i < m_size; i++)
    {
        if (*m_List[i]==C)
            return true;
    }
    return false;
}



