#include "Blackjack.h"

#include <iostream>

bool yn_q(std::string question) {

    std::cout << question << " (y/n) \n";

    char c;
    std::cin >> c;

    if (c == 'y') {
        return true;
    } else {
        return false;
    }
}

int Blackjack::getCardValuePlayer(Card c) {
        
    if (c.getRank() == Rank::ace) {
        if (playerSum+11 <= 21){
            return 11;
        } else {
            return 1;
        }
    } 
    return blackjackValues.at(c.getRank());
}

int Blackjack::getCardValueDealer(Card c) {
        
    if (c.getRank() == Rank::ace) {
        if (dealerSum+11 <= 21){
            return 11;
        } else {
            return 1;
        }
    } 
    return blackjackValues.at(c.getRank());
}

void Blackjack::playerDraw() {
    // Draw card and adds card-value to playerSum
    Card cardDrew = cardDeck.drawCard();
    std::cout << "You got: " << cardDrew.toString() << "\n";
    playerHand.push_back(cardDrew);
    playerSum += getCardValuePlayer(cardDrew);
}

void Blackjack::dealerDraw() {
    // Draw card and adds card-value to dealerSum
    Card cardDrew = cardDeck.drawCard();
    dealerHand.push_back(cardDeck.drawCard());
    dealerSum += getCardValueDealer(cardDrew);
}

void Blackjack::initialRound() {

    playerSum = 0;
    dealerSum = 0;
    playerHand.clear();
    dealerHand.clear() ;
     
    playerDraw();
    playerDraw();
    dealerDraw();
    dealerDraw();
}


void Blackjack::playBlackjack() {
    
    do{
    bool win = true;

    cardDeck.shuffle();

    initialRound();

    std::cout << "Your hand: " <<  playerSum << "\n";
    std::cout << "Dealer's open card: " << dealerHand.at(0).toString() << "\n";

    while (playerSum < 21 && yn_q("Do you want to draw another card?")) {
        playerDraw();
        std::cout << "Your hand: " << playerSum << "\n";
    }

    while (dealerSum < 17) {
        dealerDraw();
    }

    std::cout << "Dealer's cards: \n";
    for (auto& c: dealerHand) {
        std::cout << c.toString() << "\n";
    }

    std::cout << "Dealer's hand: " << dealerSum << "\n";

    if (playerSum > 21) {
        std::cout << "Player's hand is over 21.\n";
        win = false;
    } else if (dealerSum > 21) {
        std::cout << "Dealer's hand is over 21.\n";
    } else if (dealerSum == 21 && dealerHand.size() == 2) {
        std::cout << "Dealer got blackjack.\n";
        win = false;
    } else if (playerSum == 21 && playerHand.size() == 2) {
        std::cout << "Player god blackjack. \n";
    } else if (dealerSum <= 21 && dealerSum > playerSum) {
        std::cout << "Dealer beat the player. \n";
        win = false;
    } else if (playerSum <= 21 && playerSum > dealerSum) {
        std::cout << "Player beat the dealer. \n";
    } else {
        std::cout << "Draw.";
        win = false;
    }



    if (win) {
        std::cout << "You won! \n";
    } else {
        std::cout << "You lost! \n";
    }

    }while(yn_q("Do you want to play again? \n"));

}