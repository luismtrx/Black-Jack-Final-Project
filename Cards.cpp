#include "Cards.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

Cards::Cards() : CurrentCard(0) {

    deck = {
            "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10", "sJ", "sQ", "sK", "sA",
            "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c9", "c10", "cJ", "cQ", "cK", "cA",
            "d2", "d3", "d4", "d5", "d6", "d7", "d8", "d9", "d10", "dJ", "dQ", "dK", "dA",
            "h2", "h3", "h4", "h5", "h6", "h7", "h8", "h9", "h10", "hJ", "hQ", "hK", "hA",

    };
    // a standard deck of 52 cards
    if (deck.size() != 52) {
        cerr << "Incorrect number of cards loaded!" << endl;
    }
    // Shfuffle the deck after loading cards
    shuffleDeck();
}


Cards::Cards(vector<string> deck) : deck(deck), CurrentCard(0) {
    // Ensure the deck has 52 cards
    if (deck.size() != 52) {
        cerr << "Incorrect number of cards provided!" << endl;
    }
// Shuffle the provided deck
    shuffleDeck();
}


void Cards::shuffleDeck() {

    if (deck.size() != 52) {
        cerr << "Not enough cards to start the game." << endl;
        return;
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);

// Reset the current card index after shuffling
    CurrentCard = 0;
}


string Cards::dealCard() {
    if (CurrentCard >= deck.size()) {
        cerr << "All cards have been dealt. Reshuffleing the deck" << endl;\

        // Reshuffle if all cards are dealt
        Cards::shuffleDeck();

    }
    return deck[CurrentCard++];
}

int Cards::cardsLeft() const {
    return deck.size() - CurrentCard;
}





