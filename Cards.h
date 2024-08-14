#ifndef FINAL_PROJECT__CARDS_H
#define FINAL_PROJECT__CARDS_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


class Cards {

public:
    //cunstrutor that initializes the deck by loading cards
    Cards();
    Cards(vector<string> deck);

    // function to shuffle the deck
    void shuffleDeck();

    //function to keep track of the cards
    int cardsLeft() const;

// function to deal the cards
    string dealCard();

protected:
   vector<string> deck;
    int CurrentCard;
};


#endif //FINAL_PROJECT__CARDS_H
