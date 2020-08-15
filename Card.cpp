#include "Card.h"

std::string rankToString(Rank r) {
    return rankToStringMap.at(r);
}

std::string suitToString(Suit s) {
    return suitToStringMap.at(s);
}

std::string Card::toString() {
    return rankToString(r) + " of " + suitToString(s);
}

std::string Card::toStringShort() {
    return suitToString(s).at(0) + std::to_string(static_cast<int>(r));

}