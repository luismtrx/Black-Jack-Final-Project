#ifndef FINAL_PROJECT__CARDS_H
#define FINAL_PROJECT__CARDS_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


class Cards {

public:
    //this is what the cards have suit face and number
    Cards();
    Cards(string);



    // function for deck

int deck();

protected:
    string cardType;
};


#endif //FINAL_PROJECT__CARDS_H
