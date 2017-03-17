#include "Game.h"
#include "FileSystem.h"
#include "GuiManager.h"

#ifdef DEBUG
#include <assert.h>
#endif

//This is to initiate all the cubes for each disease color

int Game::numOfYellowCube = NUM_OF_STARTING_CUBE;
int Game::numOfBlackCube = NUM_OF_STARTING_CUBE;
int Game::numOfRedCube = NUM_OF_STARTING_CUBE;
int Game::numOfBlueCube = NUM_OF_STARTING_CUBE;
int Game::numOfResearchCenter = NUM_OF_STARTING_RESEARCH_FACILITY;
int Game::actionCounter = NUM_OF_MAX_ACTION;

void Game::numOfCubeDecrementor(int cityColor)
{
	switch (cityColor)
	{
	case 0:
		if (cityColor == InfectionColor::Red)
			Game::numOfRedCube--;
		//if the number of cube is equal or below 0, its game over
		if (Game::numOfRedCube <= 0)
		{
			std::cout << "Game Over! no more red cube." << std::endl;
			exit(0);
		}
		break;

	case 1:
		if (cityColor == InfectionColor::Blue)
			Game::numOfBlueCube--;
		//if the number of cube is equal or below 0, its game over
		if (Game::numOfBlueCube <= 0)
		{
			std::cout << "Game Over! no more blue cube." << std::endl;
			exit(0);
		}
		break;

	case 2:
		if (cityColor == InfectionColor::Black)
			Game::numOfBlackCube--;
		//if the number of cube is equal or below 0, its game over
		if (Game::numOfBlackCube <= 0)
		{
			std::cout << "Game Over! no more Black cube." << std::endl;
			exit(0);
		}
		break;

	case 3:
		if (cityColor == InfectionColor::Yellow)
			Game::numOfYellowCube--;
		//if the number of cube is equal or below 0, its game over
		if (Game::numOfYellowCube <= 0)
		{
			std::cout << "Game Over! no more Yellow cube." << std::endl;
			exit(0);
		}
		break;

	default:
		break;
	}
}

void Game::numOfCubeIncrementor(int cityColor)
{
	switch (cityColor)
	{
	case 0:
		if (cityColor == InfectionColor::Red)
			Game::numOfRedCube++;
		break;

	case 1:
		if (cityColor == InfectionColor::Blue)
			Game::numOfBlueCube++;
		break;

	case 2:
		if (cityColor == InfectionColor::Black)
			Game::numOfBlackCube++;
		break;

	case 3:
		if (cityColor == InfectionColor::Yellow)
			Game::numOfYellowCube++;
		break;

	default:
		break;
	}
}

Board* Game::_gameBoard = nullptr;
GameState Game::_state = GameState::MainMenu;
std::string Game::_saveFolder = "";

void Game::loadOrCreate(std::string savename)
{
#ifdef DEBUG
	// We should only load a game when we're at the main menu.
	assert(Game::getState() == GameState::MainMenu);

	// There should not be a game already loaded or uncleared.
	assert(Game::_gameBoard == nullptr);
#endif

	// Assign the new name to the game.
	Game::_saveFolder = FileSystem::getStartupPath() + GAME_SAVES_FOLDER + savename + "/";

	// Ensure the savegame folder exists.
	if (!FileSystem::directoryExists(Game::_saveFolder)) {
		FileSystem::createDirectory(Game::_saveFolder);
	}

	// Load the game board, and change the game state.
	Game::_gameBoard = new Board(Game::_saveFolder);
	Game::changeState(GameState::InGame);

	// Toggle the admin tools if they should be used.
	if (Game::_gameBoard->isEditingMap()) {
		GuiManager::getUIElementByName(CMD_TOGGLE_MAP_EDITING_ACTIONS)->visible = true;
		GuiManager::getUIElementByName(FRM_PLAYER_ACTIONS)->visible = false;
		GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;
	}
}

void Game::save()
{
#ifdef DEBUG
	// We should have some kind of valid path.
	assert(Game::_saveFolder.size() > 0);
#endif
	Game::_gameBoard->save(Game::_saveFolder);
}

void Game::destroy()
{
#ifdef DEBUG
	// Only destroy the game if we're in game.
	assert(Game::getState() == GameState::InGame);
	assert(Game::_gameBoard != nullptr);
#endif

	// Save the game.
	Game::save();

	// Clean up its resources.
	delete Game::_gameBoard;
	Game::_gameBoard = nullptr;
}

Board* Game::getGameBoard()
{
#ifdef DEBUG
	// There is no benefit to returning a null game board.
	assert(Game::_gameBoard != nullptr);
#endif
	return Game::_gameBoard;
}

GameState Game::getState()
{
	return Game::_state;
}

void Game::changeState(GameState state)
{
#ifdef DEBUG
	assert(state != GameState::GameState_Length);
#endif
	// Blindly accept state changes for now.
	Game::_state = state;
}

void Game::numOfCubeLeft()
{
	std::cout << "Number of yellow cube left: " << numOfYellowCube << std::endl;
	std::cout << "Number of black cube left: " << numOfBlackCube << std::endl;
	std::cout << "Number of blue cube left: " << numOfBlueCube << std::endl;
	std::cout << "Number of red cube left: " << numOfRedCube << std::endl;
}

void Game::decrementActionCounter()
{
	//actionCounter = 1;
	actionCounter--;
}

//Resets the number of actions
void Game::resetActionCounter() {
	actionCounter = 4;
}