#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_PICKNHIDE,
	MODE_Colors
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu
	ITM_CIRC,
	//Circle item in menu
	ITM_TRIANGLE,
	ITM_LINE,
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_DELETE,
	ITM_ZOOM,
	ITM_MOVE,
	ITM_SELECT,
	//ITM_COLOR,
	ITM_BORDER,
	ITM_SAVE,
	ITM_LOAD,
	ITM_CHANGE_DRAW_CLR,
	ITM_CHANGE_FILL_CLR,
	ITM_CHANGE_BACKGD_CLR,
	ITM_RESIZE,
	ITM_ROTATE,
	ITM_SEND_BACK,
	ITM_BRING_FRNT,
	//TODO: Add more items names here
	ITM_GO_TO_PLAY,
	ITM_EXIT,		//Exit item

	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here
	ITM_PICK_HIDE,
	ITM_SCRAMBLE_FIND,
	ITM_GO_TO_DRAW,
	ITM_EXXIT,

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PicknHideMenuItem
{
	ITM_Type,
	ITM_FILLCOLOR,
	ITM_TYPENFILL,
	ITM_AREA,
	ITM_RETURN,
	PICKNHIDE_COUNT
};



__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed

}UI;	//create a global object UI

#endif