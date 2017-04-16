#include "MapEditingActions.h"

// Buttons
#define UI_TYPE_BUTTON "button"
#define CMD_TOGGLE_ACTIONS "cmdToggleActions"
#define CMD_TOGGLE_ACTIONS_WIDTH 100
#define CMD_TOGGLE_ACITONS_HEIGHT 100

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
#define CMD_PLAYER_CARDS_CLOSE_WIDTH 25
#define CMD_PLAYER_CARDS_CLOSE_HEIGHT 25

#define CMD_TOGGLE_MAP_EDITING_ACTIONS "cmdToggleMapEditingActions"
#define CMD_TOGGLE_INVERSE_ANGLE "cmdToggleInverseAngle"
#define CMD_SELECT_NODE "cmdSelectNode"
#define CMD_ADD_NODE "cmdAddNode"
#define CMD_MAKE_NODE_RED "cmdMakeNodeRed"
#define CMD_MAKE_NODE_BLACK "cmdMakeNodeBlack"
#define CMD_MAKE_NODE_YELLOW "cmdMakeNodeYellow"
#define CMD_MAKE_NODE_BLUE "cmdMakeNodeBlue"
#define CMD_CHANGE_NODE_NAME "cmdChangeNodeName"
#define CMD_MAKE_DIRECTED_EDGE "cmdMakeDirectedEdge"
#define CMD_MOVE_NODE "cmdMoveNode"
#define CMD_FINISHED_MAP_EDITING "cmdFinishedMapEditing"

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

#define FRM_MAP_EDITING_ACTIONS "frmMapEditingActions"
#define FRM_MAP_EDITING_ACTIONS_WIDTH 100
#define FRM_MAP_EDITING_ACTIONS_HEIGHT MapEditingActions::MapEditingActions_Length * CMD_PLAYER_ACTION_BUTTON_HEIGHT
#define FRM_MAP_EDITING_ACTIONS_LEFT DRAW_WIDTH - FRM_MAP_EDITING_ACTIONS_WIDTH - 10
#define FRM_MAP_EDITING_ACTIONS_TOP DRAW_HEIGHT - FRM_MAP_EDITING_ACTIONS_HEIGHT - 100

#define FRM_MAIN_MENU "frmMainMenu"
#define FRM_MAIN_MENU_WIDTH	DRAW_WIDTH
#define FRM_MAIN_MENU_HEIGHT DRAW_HEIGHT


#define FRM_PLAYER_CARDS "frmPlayerCards"
#define FRM_PLAYER_CARDS_WIDTH DRAW_WIDTH
#define FRM_PLAYER_CARDS_HEIGHT DRAW_HEIGHT
#define PLAYER_CARD_WIDTH 150
#define PLAYER_CARD_HEIGHT 200

// Other Buttons
#define CMD_PLAYER_CARDS_OKAY "cmdPlayerCardsOkay"
#define CMD_PLAYER_CARDS_OKAY_WIDTH 100
#define CMD_PLAYER_CARDS_OKAY_HEIGHT 50
#define CMD_PLAYER_CARDS_OKAY_LEFT FRM_PLAYER_CARDS_WIDTH - CMD_PLAYER_CARDS_OKAY_WIDTH - 10
#define CMD_PLAYER_CARDS_OKAY_TOP CMD_PLAYER_CARDS_OKAY_HEIGHT + 300


// Textboxes
#define UI_TYPE_TEXTBOX "textbox"
#define TXT_SAVE_NAME "txtSaveName"


// Messagebox
#define MSG_BOX "msgBox"
#define MSG_BOX_WIDTH DRAW_WIDTH
#define MSG_BOX_HEIGHT DRAW_HEIGHT

#define CMD_MSG_BOX_ACCEPT "cmdMsgBoxAccept"



// Checkboxes
#define UI_TYPE_CHECKBOX "checkbox"
#define CHK_DEFAULT_MAP "chkDefaultMap"