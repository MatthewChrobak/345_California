//
//

#include "PlayerCard.h"

PlayerCard::PlayerCard(const std::string &cardName) : cardName(cardName) {}

const std::string &PlayerCard::getCardName() const {
    return cardName;
}

void PlayerCard::setCardName(const std::string &cardName) {
    PlayerCard::cardName = cardName;
}
