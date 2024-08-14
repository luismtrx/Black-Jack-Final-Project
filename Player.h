#ifndef FINAL_PROJECT__PLAYER_H
#define FINAL_PROJECT__PLAYER_H
#include "Cards.h"
#include <vector>
#include <string>
class Player : public Cards{

public:
    Player();

    void hit();
    void stay();
    void showHand() const;
    void dealToPlayer();
// Method to calculate and return the player's hand value
    int getHandValue() const;

    // Method to check if the player can hit
    bool canHit() const;

    // get funtion users hand using vector
    const std::vector<std::string>& getHand() const;


private:
    std::vector<std::string> hand;
    // Helper method to calculate individual card value
    int calculateCardValue(const std::string& card) const;
};



#endif //FINAL_PROJECT__PLAYER_H
