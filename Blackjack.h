#pragma once

#include "CardDeck.h"
#include "Card.h"
 
const std::map<Rank, int> blackjackValues{
    {Rank::two, 2},
    {Rank::three, 3},
    {Rank::four, 4},
    {Rank::five, 5},
    {Rank::six, 6},
    {Rank::seven, 7},
    {Rank::eight, 8},
    {Rank::nine, 9},
    {Rank::ten, 10},
    {Rank::jack, 10},
    {Rank::queen, 10},
    {Rank::king, 10},
    {Rank::ace, 11}
};


class Blackjack{
private:
    CardDeck cardDeck;
    int playerSum;
    int dealerSum;
    std::vector<Card> playerHand;
    std::vector<Card> dealerHand;

public:
    int getCardValuePlayer(Card c);
    int getCardValueDealer(Card c);
    void playerDraw();
    void dealerDraw();
    void initialRound();

    void playBlackjack();
};

bool yn_q(char c);