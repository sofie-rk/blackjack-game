#pragma once

#include "Card.h"

#include <vector>

class CardDeck{
private:
    std::vector<Card> cards;
    void swap(int a, int b);
public:
    CardDeck();
    void print();
    void printShort();
    void shuffle();
    Card drawCard();

};