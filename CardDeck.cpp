#include "CardDeck.h"

#include <iostream>

CardDeck::CardDeck() {
    for (const auto r : rankToStringMap) {
        for (const auto s : suitToStringMap) {
            Card c(s.first, r.first);
            cards.push_back(c);
        }
    }
}

void CardDeck::swap(int a, int b) {
    Card temp = cards[a];
    cards[a] = cards[b];
    cards[b] = temp; 
}

void CardDeck::print() {
    for (auto card : cards) {
        std::cout << card.toString() << "\n";
    }
}

void CardDeck::printShort() {
    for (auto card : cards) {
        std::cout << card.toStringShort() << "\n";
    }
}

void CardDeck::shuffle() {
    for (unsigned int i = 0; i < cards.size(); i++){
        swap(i, rand() % cards.size());
    }
}

Card CardDeck::drawCard() {

    Card c = cards.back();
    cards.pop_back();

    return c;
}