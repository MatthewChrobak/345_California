#pragma once
#include "Pawn.h"
#include "PlayerCard.h"
#include "RoleCard.h"
#include "PlayerAction.h"
#include "Buttons.h"

#define MAX_PLAYER_CARDS 7
class PlayerAction;


class Player
{
public:
	Pawn* pawn;
	Player();
	~Player();

	void addCard(PlayerCard* card);
	PlayerCard* getCard(int index);
	void removeCard(int index);
	int getNumberOfCards();
	RoleCard *getRoleCard() const;
	void setRoleCard(RoleCard* rc);

    //Player streategy implentation starts here-----------

    void usePlayerAction();

    //overriddenAction
    void usePlayerAction(std:: string actionChoice);

    //for using single player actions (not important..refer to playerAction list)
    PlayerAction *getPlayerAction() const;
    void setPlayerAction(PlayerAction *playerAction);

    //Getters and setters for cardsSelected
     vector<int, std::allocator<int>> &getCardsSelected() ;

    void setCardsSelected( vector<int, std::allocator<int>> &cardsSelected);

    //vector of possible player actions created at run time
    vector<PlayerAction *, std::allocator<PlayerAction *>> &getPlayerActionList() ;
    void setPlayerActionList( vector<PlayerAction *, std::allocator<PlayerAction *>> &playerActionList);

	int getCitySelected() const;

	void setCitySelected(int citySelected);

private:
  	RoleCard* rc;
	PlayerCard* _playerCards [MAX_PLAYER_CARDS];


    //Streategy starts here
    PlayerAction* playerAction;
    //this is more important
    //no getters and setters for increased security
    std::vector <PlayerAction*> playerActionList;
    //Carries the playercard selected from the GUI
    std :: vector <int> cardsSelected;
	int citySelected;


};
