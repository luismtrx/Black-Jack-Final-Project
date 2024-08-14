#include <iostream>
#include <string>
#include "Cards.h"
#include "Dealer.h"
#include "Player.h"




int main() {
    int userIn;

    cout << "Welcome to black jack press 1 to start: " << endl;
    cin >> userIn;
    while (userIn == 1) {
        Dealer dealer;
        Player player;

        // Deal initial cards
        dealer.dealToDealer();
        player.dealToPlayer();

        // Show the dealer's first card
        dealer.showOneCard();

        // Show the player's full hand
        player.showHand();

        char Input;
        while (true) {
            std::cout << "Do you want to (h)it or (s)tay? ";
            std::cin >> Input;
            if (Input == 'h') {
                if (player.canHit()) {
                    player.hit();
                    player.showHand();
                } else {
                    std::cout << "Player cannot hit, hand value is 17 or more." << std::endl;
                }
            } else if (Input == 's') {
                player.stay();
                break;
            }
        }

        // Dealer's turn: Dealer will keep hitting until reaching 17 or more
        while (dealer.canHit()) {
            std::cout << "Dealer hits." << std::endl;
            dealer.dealToDealer();
            dealer.showAllCards();
        }

        // Show dealer's full hand after player stays
        std::cout << "Dealer stays with hand value: " << dealer.getHandValue() << std::endl;
        dealer.showAllCards();

        int playerHand = player.getHandValue();
        int DealerHand =  dealer.getHandValue();



        // this finds out who the winner
        if (playerHand > 21) {
            std::cout << "Player busts! Dealer wins." << std::endl;
        } else if (DealerHand > 21) {
            std::cout << "Dealer busts! Player wins." << std::endl;
        } else if (playerHand > DealerHand) {
            std::cout << "Player wins!" << std::endl;
        } else if (DealerHand > playerHand) {
            std::cout << "Dealer wins!" << std::endl;
        } else if (DealerHand == playerHand){
            std::cout << "Stand!!" << std::endl;
        }
        else {
            std::cout << "It's a tie (push)." << std::endl;
        }
        std::cout << "Do you want to play another round? Press 1 for yes, any other key to quit: " << std::endl;
        std::cin >> userIn;


    }
    std::cout << "Thank you for playing!" << std::endl;

    return 0;
}

