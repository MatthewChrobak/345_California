#include "Buttons.h"
#include "GraphicsManager.h"
#include "GuiManager.h"
#include "UITextbox.h"
#include "Frames.h"
#include "PlayerActions.h"
#include "CityCard.h"

ToggleActionsButton::ToggleActionsButton() : UIButton(CMD_TOGGLE_ACTIONS)
{
    this->surfaceName = "ui\\button.png";
    this->caption = "View Actions";
    this->width = CMD_TOGGLE_ACTIONS_WIDTH;
    this->height = CMD_TOGGLE_ACITONS_HEIGHT;

    this->left = DRAW_WIDTH - this->width - 10;
    this->top = DRAW_HEIGHT - this->height - 10;
}

bool ToggleActionsButton::onMouseDown(std::string button, int x, int y)
{
    auto element = GuiManager::getUIElementByName(FRM_PLAYER_ACTIONS);
#ifdef DEBUG
    assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
    element->visible = !element->visible;
    return true;
}


PlayGameButton::PlayGameButton() : UIButton(CMD_PLAY_GAME_BUTTON)
{
    this->width = DRAW_WIDTH / 2;
    this->height = 50;
    this->caption = "play game";
    this->getOutline().setColor(0, 0, 0);
    this->getOutline().setThickness(2);
    this->left = this->width - this->width / 2;
    this->top = DRAW_HEIGHT / 2 + 150;
    this->setFontSize(48);
}

bool PlayGameButton::onMouseDown(std::string button, int x, int y)
{
    auto element = GuiManager::getUIElementByName(TXT_SAVE_NAME);
#ifdef DEBUG
    assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_TEXTBOX);
#endif
    // Get the name of the game.
    std::string text = ((UITextbox*)element)->text;

    // Make sure the name is valid.
    if (text.size() > 0)
    {
        Game::loadOrCreate(text);
    }
    return true;
}



DrivePlayerAction::DrivePlayerAction() : UIButton(CMD_PLAYER_ACTION_DRIVE)
{
    this->caption = "Drive";
    this->hoverSurfaceName = "ui\\lightbox.png";
    this->width = FRM_PLAYER_ACTIONS_WIDTH;
    this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

    this->top = FRM_PLAYER_ACTIONS_TOP;
    this->left = FRM_PLAYER_ACTIONS_LEFT;
}

bool DrivePlayerAction::onMouseDown(std::string key, int x, int y)
{
    GameFrame::PlayerAction = PlayerActions::Drive;
    GuiManager::showMsgBox("Please click on a city you wish to drive to.");
    return true;
}

DirectFlightPlayerAction::DirectFlightPlayerAction() : UIButton(CMD_PLAYER_ACTION_DIRECT_FLIGHT)
{
    this->caption = "Direct Flight";
    this->hoverSurfaceName = "ui\\lightbox.png";
    this->width = FRM_PLAYER_ACTIONS_WIDTH;
    this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

    this->top = FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::DirectFlight;
    this->left = FRM_PLAYER_ACTIONS_LEFT;
}

bool DirectFlightPlayerAction::onMouseDown(std::string key, int x, int y)
{
    auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
    assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction || GameFrame::PlayerAction == PlayerActions::Drive);
#endif
    GameFrame::PlayerAction = PlayerActions::DirectFlight;
    ((PlayerCardsFrame*)element)->show();
    return true;
}

CharterFlightAction::CharterFlightAction() : UIButton(CMD_PLAYER_ACTION_CHARTER_FLIGHT)
{
    this->caption = "Charter Flight";
    this->hoverSurfaceName = "ui\\lightbox.png";
    this->width = FRM_PLAYER_ACTIONS_WIDTH;
    this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

    this->top = FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::CharterFlight;
    this->left = FRM_PLAYER_ACTIONS_LEFT;
}

bool CharterFlightAction::onMouseDown(std::string key, int x, int y)
{
    auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
    assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction || GameFrame::PlayerAction == PlayerActions::Drive);
#endif
    GameFrame::PlayerAction = PlayerActions::CharterFlight;
    ((PlayerCardsFrame*)element)->show();
    return true;
}

ShuttleFlightAction::ShuttleFlightAction() : UIButton(CMD_PLAYER_ACTION_SHUTTLE_FLIGHT)
{
    this->caption = "Shuttle Flight";
    this->hoverSurfaceName = "ui\\lightbox.png";
    this->width = FRM_PLAYER_ACTIONS_WIDTH;
    this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;
    this->top = FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::ShuttleFlight;
    this->left = FRM_PLAYER_ACTIONS_LEFT;
}

bool ShuttleFlightAction::onMouseDown(std::string key, int x, int y)
{
    auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
    assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction || GameFrame::PlayerAction == PlayerActions::Drive);
#endif
    GameFrame::PlayerAction = PlayerActions::ShuttleFlight;
    ((PlayerCardsFrame*)element)->show();
    return true;
}

BuildResearchCenterAction::BuildResearchCenterAction() : UIButton(CMD_PLAYER_ACTION_BUILD_RESEARCH_CENTER)
{
    this->caption = "Build Research Center";
    this->hoverSurfaceName = "ui\\lightbox.png";
    this->width = FRM_PLAYER_ACTIONS_WIDTH;
    this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

    this->top = FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::BuildResearchCenter;
    this->left = FRM_PLAYER_ACTIONS_LEFT;
}

bool BuildResearchCenterAction::onMouseDown(std::string key, int x, int y)
{
    auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
    assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction || GameFrame::PlayerAction == PlayerActions::Drive);
#endif
    GameFrame::PlayerAction = PlayerActions::BuildResearchCenter;
    ((PlayerCardsFrame*)element)->show();
    return true;
}

TreatDiseaseAction::TreatDiseaseAction() : UIButton(CMD_PLAYER_ACTION_TREAT_DISEASE)
{
    this->caption = "Treat Disease";
    this->hoverSurfaceName = "ui\\lightbox.png";
    this->width = FRM_PLAYER_ACTIONS_WIDTH;
    this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

    this->top = FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::TreatDisease;
    this->left = FRM_PLAYER_ACTIONS_LEFT;
}
//TODO: only the city cube color can be remove(the game itself allow to remove any cubes on the city. Thus, we have to modify that in the future)
bool TreatDiseaseAction::onMouseDown(std::string key, int x, int y)
{

    Board* board = Game::getGameBoard();
    Player& player = board->getCurrentTurnPlayer();

    /*
    When the player successfully finishes an action, ensure that the action is reset by writing the line
    GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
    Failure to do so will cause assertions to fail and will cause the application to crash.
    */
    int currentPlayerIndex = player.pawn->cityIndex;
    int cityColor = Game::getGameBoard()->getCity(player.pawn->cityIndex)->color;
    // check if there's any cubes on the city
    int counter = 0;
    for (int i=0; i<5;i++){
        if (Game::getGameBoard()->getCity(player.pawn->cityIndex)->cube[i] > -1){
            counter++;
        }
    }
    if (counter ==0){

        GuiManager::showMsgBox("No infections to treat");
        GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
        return true;
    }


    if (player.getRoleCard()->getRoleCardVal() == 5)
    {

        //set it to Medic's modified treat disease
        player.setPlayerAction(player.getPlayerActionList()[2]);
        player.usePlayerAction();
        GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
    }
        //if the player is not a medic
    else
    {

        player.usePlayerAction("TreatDisease");
        GameFrame::PlayerAction = PlayerActions::NoPlayerAction;

    }


    return true;
}

ShareKnowledgeAction::ShareKnowledgeAction() : UIButton(CMD_PLAYER_ACTION_SHARE_KNOWLEDGE)
{
    this->caption = "Share Knowledge";
    this->hoverSurfaceName = "ui\\lightbox.png";
    this->width = FRM_PLAYER_ACTIONS_WIDTH;
    this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

    this->top = FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::ShareKnowledge;
    this->left = FRM_PLAYER_ACTIONS_LEFT;
}

bool ShareKnowledgeAction::onMouseDown(std::string key, int x, int y)
{
    auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
    assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction || GameFrame::PlayerAction == PlayerActions::Drive);
#endif
    GameFrame::PlayerAction = PlayerActions::ShareKnowledge;
    ((PlayerCardsFrame*)element)->show();
    return true;
}


DiscoverCureAction::DiscoverCureAction() : UIButton(CMD_PLAYER_ACTION_DISCOVER_CURE)
{
    this->caption = "Discover Cure";
    this->hoverSurfaceName = "ui\\lightbox.png";
    this->width = FRM_PLAYER_ACTIONS_WIDTH;
    this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

    this->top = FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::DiscoverCure;
    this->left = FRM_PLAYER_ACTIONS_LEFT;
}

bool DiscoverCureAction::onMouseDown(std::string key, int x, int y)
{
    auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
    assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction || GameFrame::PlayerAction == PlayerActions::Drive);
#endif
    GameFrame::PlayerAction = PlayerActions::DiscoverCure;
    ((PlayerCardsFrame*)element)->show();
    return true;
}


ViewCardsAction::ViewCardsAction() : UIButton(CMD_PLAYER_ACTION_VIEW_CARDS)
{
    this->caption = "View Cards";
    this->hoverSurfaceName = "ui\\lightbox.png";
    this->width = FRM_PLAYER_ACTIONS_WIDTH;
    this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

    this->top = FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::ViewCards;
    this->left = FRM_PLAYER_ACTIONS_LEFT;
}

bool ViewCardsAction::onMouseDown(std::string key, int x, int y)
{
    auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
    assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction || GameFrame::PlayerAction == PlayerActions::Drive);
#endif
    GameFrame::PlayerAction = PlayerActions::ViewCards;
    ((PlayerCardsFrame*)element)->show();
    return true;
}

PlayerCardsClose::PlayerCardsClose() : UIButton(CMD_PLAYER_CARDS_CLOSE)
{
    this->surfaceName = "ui\\close.png";
    this->width = CMD_PLAYER_CARDS_CLOSE_WIDTH;
    this->height = CMD_PLAYER_CARDS_CLOSE_HEIGHT;

    this->left = FRM_PLAYER_CARDS_WIDTH - CMD_PLAYER_CARDS_CLOSE_WIDTH - 10;
    this->top = 10;
}

bool PlayerCardsClose::onMouseDown(std::string button, int x, int y)
{
    auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
    assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
    element->visible = false;
    GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
    return true;
}


PlayerCardsOkay::PlayerCardsOkay(std::vector<int>* cardData) : UIButton(CMD_PLAYER_CARDS_OKAY)
{
    this->_cardData = cardData;

    this->surfaceName = "ui\\button.png";
    this->caption = "Okay";
    this->getOutline().setThickness(2);
    this->getOutline().setColor(0, 0, 0);
    this->setHorizontalCenter(true);

    this->left = CMD_PLAYER_CARDS_OKAY_LEFT;
    this->top = CMD_PLAYER_CARDS_OKAY_TOP;
    this->width = CMD_PLAYER_CARDS_OKAY_WIDTH;
    this->height = CMD_PLAYER_CARDS_OKAY_HEIGHT;
}





bool PlayerCardsOkay::onMouseDown(std::string button, int x, int y)
{
    Board* board = Game::getGameBoard();
    Player& player = board->getCurrentTurnPlayer();

    RoleCard* rc1 = new RoleCard("OperationsExpert");
    player.setRoleCard(rc1);

    int roleCardIndex = player.getRoleCard()->getRoleCardVal();
    int playerCityIndex = player.pawn->cityIndex;

    int numCities = board->getNumCities();


    // new temp player to test new implementation
    Player* player1 = board->getCurrentPlayer();
    int newIndex = player1->getRoleCard()->getRoleCardVal();

    switch (GameFrame::PlayerAction) {
        case PlayerActions::DirectFlight:

            // We should only have one card selected here.
            if (this->_cardData->size() == 1) {

                // Get the card index.
                int cardIndex = this->_cardData->at(0);

                PlayerCard *card = player.getCard(cardIndex);

                // Make sure the card is not null.

                // Make sure it's a city card.
                if (card->getType() == PlayerCardType::City_Card) {
                    //get the card value selected to used in the playerAction
                    player.getCardsSelected().push_back(cardIndex);
                    //moves to the player.cpp then to playerAction.cpp here
                    player.usePlayerAction("DirectFlight");
                    GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
                    GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;

                    break;
                } else {
                    GuiManager::showMsgBox("Please select a city card.");
                }

            } else {
                GuiManager::showMsgBox("Please select only one card.");
            }
            return true;


        case PlayerActions::CharterFlight:
            // We should only have one card selected here.
            if (this->_cardData->size() == 1) {

                // Get the card index.
                int cardIndex = this->_cardData->at(0);
                PlayerCard *card = player.getCard(cardIndex);

                // Make sure the card is not null.

                // Make sure it's a city card.
                if (card->getType() == PlayerCardType::City_Card) {
                    GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;

                    ///TODO
                    int clickedCityIndex = City::getCityIndexFromXY(GuiManager::getMouseX(), GuiManager::getMouseY());

                    if (playerCityIndex >= 0 && playerCityIndex < numCities) {
                        City *playerCity = board->getCity(playerCityIndex);
                        int clickedCityIndex = City::getCityIndexFromXY(x, y);
                    }

                    // done checking
                    player.getCardsSelected().push_back(cardIndex);
                    player.getCardsSelected().push_back(clickedCityIndex);
                    player.usePlayerAction("CharterFlight");

                    break;
                } else {
                    GuiManager::showMsgBox("Please select a city card.");
                }

            } else {
                GuiManager::showMsgBox("Please select only one card.");
            }
            return true;
        case PlayerActions::ShuttleFlight:

            /*
            When the player successfully finishes an action, ensure that the action is reset by writing the line
            GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
            Failure to do so will cause assertions to fail and will cause the application to crash.
            */
            GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;
            GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
            return true;
        case PlayerActions::BuildResearchCenter:
            //first check if the RC are still there...otherwise there's no point in using this method
            if (Game::numOfResearchCenter > 0) {

                //int x = player.getRoleCard()->getRoleCardVal();
                    //select only one card
                 if (this->_cardData->size() != 1)
                    GuiManager::showMsgBox("Please select only one card.");

                    //correct selection
                else {
                    // Get the card index.
                    int cardIndex = this->_cardData->at(0);
                    PlayerCard *card = player.getCard(cardIndex);
                    if (roleCardIndex == 4) {

                            player.getCardsSelected().push_back(cardIndex);
                            player.setPlayerAction(player.getPlayerActionList()[1]);
                            player.usePlayerAction();


                    }
                    //check if the card is null or if the card is not city card type
                    else if (card != nullptr && card->getType() == PlayerCardType::City_Card) {

                        player.usePlayerAction("BuildResearchStation");

                    } else
                        GuiManager::showMsgBox("The card is either null or you did not select a city");


                }
            }
            else {
                GuiManager::showMsgBox("All research centers have been used.");
            }
            //clear player card seleted vector
            player.getCardsSelected().clear();
            //reset player actions
            GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
            return true;

        case PlayerActions::ShareKnowledge:
            /*
            When the player successfully finishes an action, ensure that the action is reset by writing the line
            GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
            Failure to do so will cause assertions to fail and will cause the application to crash.
            */
            GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
            break;


        case PlayerActions::DiscoverCure:
        {
            int requiredCardCount = 5;
            bool medic = false;

            // Figure out if we're a medic or not.
            if (roleCardIndex == 5) {
                requiredCardCount = 4;
                medic = true;
            }
            //vector of cities to be used later
            std:: vector<CityCard*> tempCityVector;

            // Did we select enough cards?
            if (this->_cardData->size() == requiredCardCount) {

                // Are they all city cards?
                for (int i = 0; i < requiredCardCount; i++) {
                    if (player.getCard(this->_cardData->at(i))->getType() != PlayerCardType::City_Card) {
                        GuiManager::showMsgBox("You must select city cards only.");
                        //clear out the vector of cards selected in case invalid selections
                        player.getCardsSelected().clear();
                        tempCityVector.clear();
                        return true;
                    }
                    else
                    {
                        //add all the cards selected by the player
                        int temp = this->_cardData->at(i);
                        player.getCardsSelected().push_back(temp);
                        //populate cityCard vector to check colors later
                        CityCard* tempCityCard = (CityCard*)player.getCard(this->_cardData->at(i));
                        tempCityVector.push_back(tempCityCard);

                    }

                }



                // Ensure they're the same color.
                for (int i = 0; i < requiredCardCount; i++) {
                    for (int j=0; j< requiredCardCount; j++) {
                        City *cityi = board->getCity(tempCityVector[i]->cityIndex);
                        City *cityj = board->getCity(tempCityVector[j]->cityIndex);

                        if (cityi->color != cityj->color) {
                            GuiManager::showMsgBox("You must select the same color cards.");
                            player.getCardsSelected().clear();
                            return true;
                        }
                    }
                }

                // if all checks cleared call player actions

                if (medic){

                    player.setPlayerAction(player.getPlayerActionList()[6]);
                    player.usePlayerAction();

                }
                else
                    player.usePlayerAction("DiscoverCure");

            }
            else
            {
                GuiManager::showMsgBox("You need to select " + std::to_string(roleCardIndex) + " cards.");
            }


            player.getCardsSelected().clear();
            //reset player actions
            GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
            return true;

        }

            /*
            When the player successfully finishes an action, ensure that the action is reset by writing the line
            GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
            Failure to do so will cause assertions to fail and will cause the application to crash.
            */

        case PlayerActions::ViewCards:
            GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;
            GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
            return true;


        case PlayerActions::DiscardCards:
            int numberOfCards = player.getNumberOfCards();
            int numberOfDiscards = (numberOfCards + 2) % 7;

            if (this->_cardData->size() == numberOfDiscards) {

                for (int i = 0; i < numberOfDiscards; i++)
                {
                    int cardIndex1 = this->_cardData->at(0);
                    player.removeCard(cardIndex1);
                }
            }
            else {
                GuiManager::showMsgBox("You must select " + std::to_string(numberOfCards) + " cards.");
            }
            break;
    }


    //If turn is changed, show this message
    //if (Game::getGameBoard()->playerTurnChange() == true)
    //{
    //	Game::getGameBoard()->drawCards();
    //	GuiManager::showMsgBox("Your current hand after picking two cards.");
    //	GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = true;

    //	int numberOfCards = player.getNumberOfCards();

    //	if (numberOfCards >= 6) //You only excess cards only when you draw while you have 6 or more cards
    //	{
    //		GuiManager::showMsgBox("Please discard " + std::to_string((numberOfCards + 2) % 7) + " cards.");
    //		GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = true;// show message that we have to discard.
    //		GameFrame::PlayerAction = PlayerActions::DiscardCards;

    //	}
    //	//draw infection card and the game will do the infection automatically
    //	Game::getGameBoard()->drawInfectionCard();
    //	GuiManager::showMsgBox("End of your turn.");
    //}

    return true;
}

ToggleMapEditingActions::ToggleMapEditingActions() : UIButton(CMD_TOGGLE_MAP_EDITING_ACTIONS)
{
    this->surfaceName = "ui\\button.png";
    this->caption = "Show Tools";
    this->width = CMD_TOGGLE_ACTIONS_WIDTH;
    this->height = CMD_TOGGLE_ACITONS_HEIGHT;
    this->visible = false;

    this->left = DRAW_WIDTH - this->width - 10;
    this->top = DRAW_HEIGHT - this->height - 10;
}

bool ToggleMapEditingActions::onMouseDown(std::string button, int x, int y)
{
    auto element = GuiManager::getUIElementByName(FRM_MAP_EDITING_ACTIONS);
#ifdef DEBUG
    assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
    element->visible = !element->visible;
    return true;
}

SelectNodeAction::SelectNodeAction() : UIButton(CMD_SELECT_NODE)
{
    this->caption = "Select Node";
    this->hoverSurfaceName = "ui\\lightbox.png";
    this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
    this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

    this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::SelectNode;
    this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
bool SelectNodeAction::onMouseDown(std::string button, int x, int y)
{
    GameFrame::EditingAction = MapEditingActions::SelectNode;
    return true;
}

RotateNodeAngleAction::RotateNodeAngleAction() : UIButton(CMD_SELECT_NODE)
{
    this->caption = "Rotate Angle";
    this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
    this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

    this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::RotateAngle;
    this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
bool RotateNodeAngleAction::onMouseDown(std::string button, int x, int y)
{
    GameFrame::EditingAction = MapEditingActions::RotateAngle;
    return true;
}

AddNodeAction::AddNodeAction() : UIButton(CMD_ADD_NODE)
{
    this->caption = "Add Node";
    this->hoverSurfaceName = "ui\\lightbox.png";
    this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
    this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

    this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::AddNode;
    this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
bool AddNodeAction::onMouseDown(std::string button, int x, int y)
{
    GameFrame::EditingAction = MapEditingActions::AddNode;
    return true;
}



MakeNodeBlackAction::MakeNodeBlackAction() : UIButton(CMD_MAKE_NODE_BLACK)
{
    this->caption = "Make Black";
    this->hoverSurfaceName = "ui\\lightbox.png";
    this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
    this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

    this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::MakeNodeBlack;
    this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
bool MakeNodeBlackAction::onMouseDown(std::string button, int x, int y)
{
    GameFrame::EditingAction = MapEditingActions::MakeNodeBlack;
    return true;
}



MakeNodeRedAction::MakeNodeRedAction() : UIButton(CMD_MAKE_NODE_RED)
{
    this->caption = "Make Red";
    this->hoverSurfaceName = "ui\\lightbox.png";
    this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
    this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

    this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::MakeNodeRed;
    this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
bool MakeNodeRedAction::onMouseDown(std::string button, int x, int y)
{
    GameFrame::EditingAction = MapEditingActions::MakeNodeRed;
    return true;
}


MakeNodeYellowAction::MakeNodeYellowAction() : UIButton(CMD_MAKE_NODE_YELLOW)
{
    this->caption = "Make Yellow";
    this->hoverSurfaceName = "ui\\lightbox.png";
    this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
    this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

    this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::MakeNodeYellow;
    this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
bool MakeNodeYellowAction::onMouseDown(std::string button, int x, int y)
{
    GameFrame::EditingAction = MapEditingActions::MakeNodeYellow;
    return true;
}


MakeNodeBlueAction::MakeNodeBlueAction() : UIButton(CMD_MAKE_NODE_BLUE)
{
    this->caption = "Make Blue";
    this->hoverSurfaceName = "ui/lightbox.png";
    this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
    this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

    this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::MakeNodeBlue;
    this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
bool MakeNodeBlueAction::onMouseDown(std::string button, int x, int y)
{
    GameFrame::EditingAction = MapEditingActions::MakeNodeBlue;
    return true;
}


ChangeNodeNameAction::ChangeNodeNameAction() : UIButton(CMD_CHANGE_NODE_NAME)
{
    this->caption = "Rename Node";
    this->hoverSurfaceName = "ui\\lightbox.png";
    this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
    this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

    this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::ChangeNodeName;
    this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
bool ChangeNodeNameAction::onMouseDown(std::string button, int x, int y)
{
    GameFrame::EditingAction = MapEditingActions::ChangeNodeName;
    return true;
}


MakeDirectedEdgeAction::MakeDirectedEdgeAction() : UIButton(CMD_MAKE_DIRECTED_EDGE)
{
    this->caption = "Make Edge";
    this->hoverSurfaceName = "ui\\lightbox.png";
    this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
    this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

    this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::MakeDirectedEdge;
    this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
bool MakeDirectedEdgeAction::onMouseDown(std::string button, int x, int y)
{
    GameFrame::EditingAction = MapEditingActions::MakeDirectedEdge;
    return true;
}



MoveNodeAction::MoveNodeAction() : UIButton(CMD_MOVE_NODE)
{
    this->caption = "MoveNode";
    this->hoverSurfaceName = "ui\\lightbox.png";
    this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
    this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

    this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::MoveNode;
    this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
bool MoveNodeAction::onMouseDown(std::string button, int x, int y)
{
    GameFrame::EditingAction = MapEditingActions::MoveNode;
    return true;
}


FinishedEditingMapAction::FinishedEditingMapAction() : UIButton(CMD_FINISHED_MAP_EDITING)
{
    this->caption = "Done Editing";
    this->hoverSurfaceName = "ui\\lightbox.png";
    this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
    this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

    this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::FinishedEditingMap;
    this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
bool FinishedEditingMapAction::onMouseDown(std::string button, int x, int y)
{
    auto element = GuiManager::getUIElementByName(FRM_GAME_FRAME);
#ifdef DEBUG
    assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
    ((GameFrame*)element)->finishedEditing();
    return true;
}
