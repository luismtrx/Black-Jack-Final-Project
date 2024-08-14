#include "Player.h"
#include "Cards.h"
#include <iostream>

Player::Player() : Cards() {
    // Hand is initially empty, so no initialization needed
}

void Player::dealToPlayer() {
    hand.push_back(dealCard());
    hand.push_back(dealCard());
}

void Player::hit() {
    if (canHit()) {
        hand.push_back(dealCard());
        if (cardsLeft() <= 5) {
            shuffleDeck();
        }
    } else {
        std::cout << "Player cannot hit, hand value is 17 or more." << std::endl;
    }
}

void Player::stay() {
    // Player does nothing, stays with the current hand
}

void Player::showHand() const {
    std::cout << "Player's hand: ";
    for (const auto& card : hand) {
        std::cout << card << " ";
    }
    std::cout << std::endl;
}

int Player::getHandValue() const {
    int totalValue = 0;
    int aces = 0;

    for (const auto& card : hand) {
        int value = calculateCardValue(card);
        if (value == 11) aces++;
        totalValue += value;
    }

    // Adjust for aces if totalValue is greater than 21
    while (totalValue > 21 && aces > 0) {
        totalValue -= 10;
        aces--;
    }

    return totalValue;
}

bool Player::canHit() const {
    return getHandValue() < 17;
}

int Player::calculateCardValue(const std::string& card) const {
    char rank = card[1];  // The rank is the second character in the string
    if (rank >= '2' && rank <= '9') {
        return rank - '0';  // Convert char to int
    } else if (rank == '1' || rank == 'J' || rank == 'Q' || rank == 'K') {
        return 10;
    } else if (rank == 'A') {
        return 11;
    }
    return 0;
}

const std::vector<std::string>& Player::getHand() const {
    return hand;
}











