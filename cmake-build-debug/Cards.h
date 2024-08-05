#ifndef FINAL_PROJECT__CARDS_H
#define FINAL_PROJECT__CARDS_H
#include <string>
using namespace std;


class Cards {

public:
    //this is what the cards have suit face and number
    Cards(string, string, int);


// function for deck
void deck();

private:
    string suit;
    string face;
    int number;

};


#endif //FINAL_PROJECT__CARDS_H
