//
// Created by Nahian Pathan on 2017-03-31.
//

#ifndef BOARD_BOOST_PLAYERCARD_H
#define BOARD_BOOST_PLAYERCARD_H

#include "iostream"

class PlayerCard {


std::string cardName;

public:
    PlayerCard(const std::string &cardName);

    const std::string &getCardName() const;

    void setCardName(const std::string &cardName);


};


#endif //BOARD_BOOST_PLAYERCARD_H
