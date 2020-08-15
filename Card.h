#pragma once

#include <string>
#include <map>

enum class Suit {clubs, diamonds, hearts, spades};

enum class Rank {two=2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

const std::map<Rank, std::string> rankToStringMap{
    {Rank::two, "Two"},
    {Rank::three, "Three"},
    {Rank::four, "Four"},
    {Rank::five, "Five"},
    {Rank::six, "Six"},
    {Rank::seven, "Seven"},
    {Rank::eight, "Eight"},
    {Rank::nine, "Nine"},
    {Rank::ten, "Ten"},
    {Rank::jack, "Jack"},
    {Rank::queen, "Queen"},
    {Rank::king, "King"},
    {Rank::ace, "Ace"},
};

const std::map<Suit, std::string> suitToStringMap{
    {Suit::clubs, "Clubs"},
    {Suit::diamonds, "Diamonds"},
    {Suit::hearts, "Hearts"},
    {Suit::spades, "Spades"},

};

std::string rankToString(Rank r);
std::string suitToString(Suit s);

class Card{
private:
    Suit s;
    Rank r;
public:
    Card(Suit suit, Rank rank) : s{suit}, r{rank} {}

    Suit getSuit() const {return s;}
    Rank getRank() const {return r;}

    std::string toString();
    std::string toStringShort();




};