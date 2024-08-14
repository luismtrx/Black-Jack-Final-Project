#include "Dealer.h"
#include "Cards.h"
#include <vector>
#include <iostream>

Dealer::Dealer() : Cards() {}

void Dealer::dealToDealer() {
    dealerHand.push_back(dealCard());
    dealerHand.push_back(dealCard());
}

void Dealer::showOneCard() const {
    if (!dealerHand.empty()) {
        std::cout << "Dealer shows: " << dealerHand[0] << std::endl;
    } else {
        std::cerr << "No cards to show." << std::endl;
    }
}

void Dealer::showAllCards() const {
    std::cout << "Dealer's hand: ";
    for (const auto& card : dealerHand) {
        std::cout << card << " ";
    }
    std::cout << std::endl;
}

int Dealer::getHandValue() const {
    int totalValue = 0;
    int aces = 0;

    for (const auto& card : dealerHand) {
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

bool Dealer::canHit() const {
    return getHandValue() < 17;
}

int Dealer::calculateCardValue(const std::string& card) const {
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

const std::vector<std::string>& Dealer::getDealerHand() const {
    return dealerHand;
}
