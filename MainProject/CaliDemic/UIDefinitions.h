#include "GraphicsManager.h"

// Buttons
#define UI_TYPE_BUTTON "button"
#define CMD_TOGGLE_ACTIONS "cmdToggleActions"
#define CMD_TOGGLE_ACTIONS_WIDTH 100;
#define CMD_TOGGLE_ACITONS_HEIGHT 100;

#define CMD_PLAYER_ACTION_BUTTON_HEIGHT 50
#define CMD_PLAY_GAME_BUTTON "cmdPlayGameButton"

#define CMD_PLAYER_ACTION_DRIVE "cmdPlayerActionDrive"
#define CMD_PLAYER_ACTION_DIRECT_FLIGHT "cmdPlayerActionDirectFlight"
#define CMD_PLAYER_ACTION_CHARTER_FLIGHT "cmdPlayerActionCharterFlight"
#define CMD_PLAYER_ACTION_SHUTTLE_FLIGHT "cmdPlayerActionShuttleFlight"
#define CMD_PLAYER_ACTION_BUILD_RESEARCH_CENTER "cmdPlayerActionBuildResearchCenter"
#define CMD_PLAYER_ACTION_TREAT_DISEASE "cmdPlayerActionTreatDisease"
#define CMD_PLAYER_ACTION_SHARE_KNOWLEDGE "cmdPlayerActionShareKnowledge"
#define CMD_PLAYER_ACTION_DISCOVER_CURE "cmdPlayerActionDiscoverCure"
#define CMD_PLAYER_ACTION_VIEW_CARDS "cmdPlayerActionViewCards"

#define CMD_PLAYER_CARDS_CLOSE "cmdPlayerCardsClose"
#define CMD_PLAYER_CARDS_CLOSE_WIDTH 50
#define CMD_PLAYER_CARDS_CLOSE_HEIGHT 50

// Frames
#define UI_TYPE_FRAME "frame"

#define FRM_GAME_FRAME "frmGameFrame"
#define FRM_GAME_FRAME_WIDTH DRAW_WIDTH
#define FRM_GAME_FRAME_HEIGHT DRAW_HEIGHT

#define FRM_PLAYER_ACTIONS "frmPlayerActions"
#define FRM_PLAYER_ACTIONS_WIDTH 100
#define FRM_PLAYER_ACTIONS_HEIGHT PlayerActions::PlayerActions_Length * CMD_PLAYER_ACTION_BUTTON_HEIGHT
#define FRM_PLAYER_ACTIONS_LEFT DRAW_WIDTH - FRM_PLAYER_ACTIONS_WIDTH - 10
#define FRM_PLAYER_ACTIONS_TOP DRAW_HEIGHT - FRM_PLAYER_ACTIONS_HEIGHT - 100

#define FRM_MAIN_MENU "frmMainMenu"
#define FRM_MAIN_MENU_WIDTH	DRAW_WIDTH
#define FRM_MAIN_MENU_HEIGHT DRAW_HEIGHT


#define FRM_PLAYER_CARDS "frmPlayerCards"
#define FRM_PLAYER_CARDS_WIDTH DRAW_WIDTH
#define FRM_PLAYER_CARDS_HEIGHT DRAW_HEIGHT


// Textboxes
#define UI_TYPE_TEXTBOX "textbox"
#define TXT_SAVE_NAME "txtSaveName"




