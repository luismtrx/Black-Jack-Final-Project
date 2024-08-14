#ifndef FINAL_PROJECT__DEALER_H
#define FINAL_PROJECT__DEALER_H
#include "Cards.h"
#include <string>
#include <vector>


class Dealer : public Cards {

public: Dealer();


    // function that shows the card to the user
    void showOneCard() const;

    // fucntion that deals card to the dealer
    void dealToDealer();

    // function that
    void showAllCards() const;

    // function to calculate and return the dealer's hand value
    int getHandValue() const;

    // function to check if the dealer can hit
    bool canHit() const;

    // get function for dealers hand and uses vector
    const std::vector<std::string>& getDealerHand() const;

private:
    std::vector<std::string> dealerHand;

    int calculateCardValue(const std::string& card) const;  // Helper method to calculate individual card value

};

#endif //FINAL_PROJECT__DEALER_H
