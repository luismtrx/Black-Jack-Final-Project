#include "Cards.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
#define ROWS 4
#define COLUMS 13



int Cards::deck() {

    // setting up the array
    vector<vector<std::string>> card(ROWS, vector<std::string> (COLUMS));

    // importing the txt file
    ifstream inputFile;
    inputFile.open("Cards.txt");

    //putting the file contents into the array
    for (unsigned int i = 0; i < ROWS; i++){
        for (unsigned int j = 0; j < COLUMS; i++){
            inputFile >> card[i][j];
        }

    }
    random_device rd;
    mt19937 g(rd());

    shuffle(card.begin(), card.end(), rd);






}
