#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
	pWind->FlushMouseQueue();
}

string Input::GetSrting(Output *pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction(int x, int y) const
{
	if (x==-1&y==-1)
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight / 2)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			//switch (ClickedItemOrder)
			//{
			//case ITM_RECT: return DRAW_RECT;
			//case ITM_CIRC: return DRAW_CIRC;
			//case ITM_TRIANGLE:return DRAW_TRI;
			//case ITM_LINE: return DRAW_LINE;
			//case ITM_COPY:return COPY;
			//case ITM_CUT: return CUT;
			//case ITM_PASTE: return PASTE;
			//case ITM_DELETE: return DEL;
			//case ITM_ZOOM: return ZOOM;
			//case ITM_MOVE: return MOVE;
			//case ITM_SELECT: return SELECT;
			//case ITM_BORDER:return BORDER;
			//case ITM_SAVE: return SAVE;
			//case ITM_LOAD: return LOAD;

			//	//case ITM_GO_TO_PLAY:return TO_PLAY;
			//	//case 10:return TO_PLAY;
			//	//A click on empty place in desgin toolbar
			//}
			if (x > 0 & x < 113)return DRAW_RECT;
			if (x > 113 & x < 226)return DRAW_CIRC;
			if (x > 226 & x < 332)return CUT;
			if (x > 332 & x < 452)return COPY;
			if (x > 452 & x < 565)return SELECT;
			if (x > 565 & x < 684)return ROTATE;
			if (x > 684 & x < 791)return MOVE;
			if (x > 791 & x < 904)return ZOOM;
			if (x > 904 & x < 990)return BORDER;
			if (x > 990 & x < 1096)return CHNG_FILL_CLR;
			if (x > 1096 & x < 1195)return SAVE;
			if (x > 1195 & x < 1300)return EXIT;
			else return EMPTY;
			
		}



		if (y >= UI.ToolBarHeight / 2 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth) + 14;


			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			//switch (ClickedItemOrder)
			//{

			//	//	case ITM_:return DRAW_TRI;
			//case ITM_CHANGE_DRAW_CLR: return CHNG_DRAW_CLR;
			//case ITM_CHANGE_FILL_CLR:return CHNG_FILL_CLR;
			//case ITM_CHANGE_BACKGD_CLR: return CHNG_BK_CLR;
			//case ITM_RESIZE: return RESIZE;
			//case ITM_ROTATE: return ROTATE;
			//case ITM_SEND_BACK: return SEND_BACK;
			//case ITM_BRING_FRNT: return BRNG_FRNT;
			//case ITM_GO_TO_PLAY:return TO_PLAY;
			//case ITM_EXIT:return EXIT;
			//default: return EMPTY;	//A click on empty place in desgin toolbar
			//}
			if (x > 0 & x < 113)return DRAW_LINE;
			if (x > 113 & x < 226)return DRAW_TRI;
			if (x > 226 & x < 332)return PASTE;
			if (x > 332 & x < 452)return DEL;
			if (x > 452 & x < 507)return REDO;
			if (x > 507 & x < 565)return UNDO;
			if (x > 565 & x < 684)return SEND_BACK;
			if (x > 684 & x < 791)return BRNG_FRNT;
			if (x > 791 & x < 904)return RESIZE;
			if (x > 904 & x < 990)return CHNG_BK_CLR;
			if (x > 990 & x < 1096)return CHNG_DRAW_CLR;
			if (x > 1096 & x < 1195)return LOAD;
			if (x > 1195 & x < 1300)return TO_PLAY;
			else return EMPTY;
		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_PICKNHIDE)
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{





			case ITM_Type: return 	PICK_TYPE;
			case ITM_FILLCOLOR: return PICK_FILL;
			case ITM_TYPENFILL:return PICK_TYPENFILL;
			case ITM_AREA:return	PICK_AREA;
			case ITM_RETURN: return RETURN;
			default: return EMPTY;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;


	}

	else	//GUI is in PLAY mode
	{
		
		if (y >= 0 && y < UI.ToolBarHeight/2)
		{
		
			if (x > 0 & x < 219)return PICK_HIDE;
			else if (x > 770 & x < 1041)return SCRAMBLE_FIND;
			else if (x > 1041 & x < 1181)return TO_DRAW;
			else if (x > 1181 & x < 1300)return EXIT;
			else return EMPTY;
		}

		if (y >= UI.ToolBarHeight/2 && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		
		return STATUS;


	}

}
/////////////////////////////////

Input::~Input()
{
}
