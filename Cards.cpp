#include "Cards.h"
#include <iostream>
#include <fstream>
using namespace std;
#define ROWS 4
#define COLUMS 14





void Cards::deck() {

    // setting up the array
    string card [ROWS][COLUMS] = {0};

    // importing the txt file
    ifstream inputFile;
    inputFile.open("Cards.txt");
    //putting the file contents into the array
    for (unsigned int i = 0; i < ROWS; i++){
        for (unsigned int j = 0; j < COLUMS; i++){
            inputFile >> card[i][j];
        }

    }


}
