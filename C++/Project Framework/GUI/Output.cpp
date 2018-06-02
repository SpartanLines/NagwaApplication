#include "Output.h"
#include<cmath>
#include<Windows.h>
#include<mmsystem.h>
#define PI 3.14159265
Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1300;
	UI.height = 800;
	UI.wx = 5;
	UI.wy = 5;
	
	barney = 0;
	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 200;
	UI.MenuItemWidth = 85;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames



	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
	
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);

	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
	


}
void Output::splitscreen()const
{
    pWind->SetPen(DARKTURQUOISE, 3);
	pWind->DrawLine(650, UI.ToolBarHeight / 2, 650, 750);

}

void Output::CreateBorderwidthChoice()const
{
	string factors = "images\\MenuItems\\dropmenu.jpg";
	pWind->DrawImage(factors, 904, 200,200, 100);
}

void Output::CreateResizeChoice()const
{
	string factors = "images\\MenuItems\\resizemenu.jpg";
	pWind->DrawImage(factors, 904, 200, 200, 100);
}
void Output::CreateRotateChoice()const
{
	string factors = "images\\MenuItems\\angles.jpg";
	pWind->DrawImage(factors, 904, 200, 200, 100);
}
void Output::CreateZoomedToolbar()const
{
	string newtoolbar = "images\\MenuItems\\zoomedtoolbar.jpg";
	pWind->DrawImage(newtoolbar, 0, 0, 1300, UI.ToolBarHeight);
}
void Output::CreateZoomChoice()const
{
	string factors = "images\\MenuItems\\zoommenu.jpg";
	pWind->DrawImage(factors, 904, 200, 200, 100);

}
void Output::CreatePlay2()const
{
	string factors = "images\\MenuItems\\playtoolbar.jpg";
	pWind->DrawImage(factors, 0, 0, 1300, UI.ToolBarHeight/2);
}
void Output::CreatePlay3()const
{
	string factors = "images\\MenuItems\\playtoolbar3.jpg";
	pWind->DrawImage(factors, 0, 0, 1300, UI.ToolBarHeight / 2);
}
///////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateColorsWheel() const
{
	
	
	pWind->SetBrush(DARKGRAY);
	pWind->SetPen(UI.BkGrndColor, 1);
	//pWind->DrawRectangle(160, UI.ToolBarHeight, 440, 420+UI.ToolBarHeight);

	string frame = "images\\MenuItems\\frame.jpg";
	pWind->DrawImage(frame, 160, UI.ToolBarHeight, 290,380);
	int centerx = 300;
	int centery = 200 + UI.ToolBarHeight;
	
	int radius = 100;
	color temp = color(255, 0, 0);
	
		GfxInfo gfx;
		gfx.DrawClr = temp;
		gfx.BorderWdth = 1;
		double x;
		double y;
		int z;
			int theta = 0;
			for (int i = 0; i <=360;i++)
			{
				if (i % 60 == 0)z = 0;
				float slope = tan(theta*PI/180);
				if (i<60 &i>0)
				temp = color(255,z*4 , 0);
				if (i<120 & i>=60)
					temp = color(255-z*4,255, 0);
				if (i<180 & i>=120)
					temp = color(0, 255,z*4);
				if (i<240 & i>=180)
					temp = color(0, 255-z*4, 255);
				if (i<300 & i>=240)
					temp = color(z*4, 0, 255);
				if (i<360 & i>=300)
					temp = color(255,0 ,255-z*4 );
			//	y = slope*x + 300 + UI.ToolBarHeight - slope * 300;
				//y = sqrt(pow(100, 2) - pow(x - centerx, 2)) + centery;
				x = centerx + sin(i*PI / 180)*radius;
        		y = centery - cos(i*PI / 180)*radius;
				pWind->SetBrush(temp);
				pWind->SetPen(temp,3);
				
				pWind->DrawLine(centerx, centery, x, y, FRAME);
				z++;
				
			}
			
	/*		
			for (int i = 0; i <= 360; i++)
			{
				if (i % 7 == 0)z += 5;
				temp = color(z, z, z);
				x = centerx + sin(i*PI / 180)*radius/3;
				y = centery + cos(i*PI / 180)*radius/3;
				pWind->SetBrush(temp);
				pWind->SetPen(temp, 2);

				pWind->DrawLine(centerx, centery, x, y, FRAME); pWind->DrawLine(centerx, centery, x, y, FRAME);
				z++;
			}*/


			
		}
	


//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() 
{
	UI.InterfaceMode = MODE_DRAW;
	

	pWind->SetBrush(WHITE);
	pWind->SetPen(WHITE, 1);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	//string MenuItemImages[DRAW_ITM_COUNT];
	//MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	//MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.jpg";
	//MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\triangle.jpg";
	//MenuItemImages[ITM_LINE] = "images\\MenuItems\\line.jpg";
	//MenuItemImages[ITM_COPY] = "images\\MenuItems\\copy.jpg";
	//MenuItemImages[ITM_CUT] = "images\\MenuItems\\cut.jpg";
	//MenuItemImages[ITM_PASTE] = "images\\MenuItems\\paste.jpg";
	//MenuItemImages[ITM_DELETE] = "images\\MenuItems\\delete.jpg";
	//MenuItemImages[ITM_ZOOM] = "images\\MenuItems\\zoom.jpg";
	//MenuItemImages[ITM_MOVE] = "images\\MenuItems\\Move.jpg";
	//MenuItemImages[ITM_SELECT] = "images\\MenuItems\\select.jpg";
	////MenuItemImages[ITM_COLOR] = "images\\MenuItems\\color.jpg";
	//MenuItemImages[ITM_BORDER] = "images\\MenuItems\\border.jpg";
	//MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	//MenuItemImages[ITM_LOAD] = "images\\MenuItems\\load.jpg";
	//MenuItemImages[ITM_CHANGE_DRAW_CLR] = "images\\MenuItems\\changedrawingcolor.jpg";
	//MenuItemImages[ITM_CHANGE_FILL_CLR] = "images\\MenuItems\\changefillcolor.jpg";
	//MenuItemImages[ITM_CHANGE_BACKGD_CLR] = "images\\MenuItems\\changebgdcolor.jpg";


	//MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\resize.jpg";
	//MenuItemImages[ITM_ROTATE] = "images\\MenuItems\\images.jpg";
	//MenuItemImages[ITM_SEND_BACK] = "images\\MenuItems\\sendtoback.jpg";
	//MenuItemImages[ITM_BRING_FRNT] = "images\\MenuItems\\bringtofront2.jpg";

	//MenuItemImages[ITM_GO_TO_PLAY] = "images\\MenuItems\\gotoplay.jpg";
	//MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";


	if (barney ==0)
	{
		string paintzania[4];
		paintzania[0] = "images\\MenuItems\\paintzania.jpg";
		paintzania[1] = "images\\MenuItems\\paintzania3.jpg";
		paintzania[2] = "images\\MenuItems\\paintzania4.jpg";
		paintzania[3] = "images\\MenuItems\\paintzania2.jpg";
		int j = 10;
		PlaySoundA("Barney.wav", NULL, SND_ASYNC);
		while (j != 0)
		{
			for (int i = 0; i < 4; i++)
			{
				pWind->DrawImage(paintzania[i], 20, 0, UI.width / 1.3, UI.height / 1.3);
				Sleep(50);
				pWind->DrawImage(paintzania[i], 20, 0, UI.width / 1.3, UI.height / 1.3);
			}
			j--;
	
		}
	
		
		
		ClearDrawArea();
		
		barney++;
	}
	//Draw menu item one image at a time
	//for (int i = 0; i<DRAW_ITM_COUNT - 9; i++) // two for loops to draw the items on to levels
	//{
	//	pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight / 2 - 3);
	//}
	//for (int i = 0; i<9; i++)//draw_itm_count
	//{
	//	pWind->DrawImage(MenuItemImages[i + DRAW_ITM_COUNT - 9], i*UI.MenuItemWidth, 60, UI.MenuItemWidth, UI.ToolBarHeight / 2 - 3);
	//}
	string newtoolbar = "images\\MenuItems\\toolbar.jpg";
	pWind->DrawImage(newtoolbar, 0, 0,1300, UI.ToolBarHeight);
	//Draw a line under the toolbar
	/*pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight / 2, UI.width, UI.ToolBarHeight / 2);

	pWind->DrawLine(0, UI.ToolBarHeight - 3, UI.width, UI.ToolBarHeight - 3);*/

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreatePICKNHIDEToolBar() const
{
	UI.InterfaceMode = MODE_PICKNHIDE;


	pWind->SetBrush(WHITE);
	pWind->SetPen(WHITE, 1);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	string picks[5];
	picks[0] = "images\\MenuItems\\type.jpg";
	picks[1] = "images\\MenuItems\\fillcolor.jpg";
	picks[2] = "images\\MenuItems\\typenfill.jpg";
	picks[3] = "images\\MenuItems\\area.jpg";
	picks[4] = "images\\MenuItems\\return.jpg";
	for (int i = 0; i<PICKNHIDE_COUNT; i++)//draw_itm_count
	{
		pWind->DrawImage(picks[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}
	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, PICKNHIDE_COUNT*UI.MenuItemWidth, UI.ToolBarHeight);
}

/////////////////////////////////////////////////////////////////////////////////////////
void Output::CreatePlayToolBar() const
{

	string play[5];
	play[0] = "images\\MenuItems\\play1.jpg";
	play[1] = "images\\MenuItems\\play2.jpg";
	play[2] = "images\\MenuItems\\play3.jpg";
	play[3] = "images\\MenuItems\\play4.jpg";
	play[4] = "images\\MenuItems\\play5.jpg";



	for (int i = 0; i < 5; i++)
	{
		pWind->DrawImage(play[i], 20, 0, UI.width / 1.3, UI.height / 1.3);
		Sleep(75);

	}
	Sleep(50);

	//TODO: Prepare images for each menu item and add it to the list
	ClearDrawArea();




	UI.InterfaceMode = MODE_PLAY;
	
	

	string plays = "images\\MenuItems\\playtoolbar2.jpg";
	pWind->DrawImage(plays, 0, 0, 1300, UI.ToolBarHeight/2);
	
	//Draw a line under the toolbar
	pWind->SetPen(DARKSLATEBLUE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, PLAY_ITM_COUNT*UI.MenuItemWidth, UI.ToolBarHeight/2);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	if (UI.InterfaceMode == MODE_DRAW)
	{
		pWind->SetPen(UI.BkGrndColor, 1);
		pWind->SetBrush(UI.BkGrndColor);
		pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
		return;
	}
	else
	{
		pWind->SetPen(UI.BkGrndColor, 1);
		pWind->SetBrush(UI.BkGrndColor);
		pWind->DrawRectangle(0, UI.ToolBarHeight/2, UI.width, UI.height - UI.StatusBarHeight);

	}

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//
bool Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo,int k, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;       //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	if (k == 1)// used to ignore the check in case of zoom
	{
		pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
		return true;
	}
	bool check = DrawCheck(P1, P2);      // Calling the check functions to avoid drawing on toolbar, status bar or outside the UI.

	if (check == true)           // If the selected area is available, it draws the fig.
	{
		pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
		return true;
	}
	return false;


}

bool Output::DrawLine(Point P1, Point P2, GfxInfo RectGfxInfo, int k, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;

	style = FRAME;

	bool check = DrawCheck(P1, P2);        // Calling the check function to avoid drawing on toolbar, status bar or outside the UI.
	if (k == 1)// used to ignore the check in case of zoom
	{
		pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
		return true;
	}
	if (check == true)
	{
		pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
		return true;
	}

	return false;

}
bool Output::DrawCircle(Point P1, int radius, GfxInfo RectGfxInfo, int k, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	if (k == 1)// used to ignore the check in case of zoom
	{
		pWind->DrawCircle(P1.x, P1.y, radius, style);
		return true;
	}
	
	bool check = DrawCheck(P1, radius);   // Calling the check functions to avoid drawing on toolbar, status bar or outside the UI.

	if (check == true)
	{
		pWind->DrawCircle(P1.x, P1.y, radius, style);
		return true;
	}
	return false;
}
bool Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, int k, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	if (k == 1)// used to ignore the check in case of zoom
	{
		pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
		return true;
	}

	bool check = DrawCheck(P1, P2, P3);  // Calling the check functions to avoid drawing on toolbar, status bar or outside the UI.

	if (check == true)
	{
		pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
		return true;
	}

	return false;

}

bool Output::DrawCheck(Point P1, Point P2) const   // lines and rects.
{
	if (P1.y > (800 - UI.StatusBarHeight) || P2.y > (800 - UI.StatusBarHeight)) return false;   // checks for the location of all y-coord. wrt to status bar.
	if (P1.y < UI.ToolBarHeight || P2.y < UI.ToolBarHeight) return false;   // checks for the location of all y-coord. wrt to toolbar.
	if (P1.x < 0 || P2.x < 0) return false;       // checks for the location of all x-coord. wrt to left most of UI.
	if (P1.x > 1300 || P2.x > 1300) return false;  // checks for the location of all x-coord. wrt to right most of UI.
	return true;
}

bool Output::DrawCheck(Point P1, Point P2, Point P3) const     // triangles.
{
	if (P1.y >(800 - UI.StatusBarHeight) || P2.y >(800 - UI.StatusBarHeight) || P3.y > (800 - UI.StatusBarHeight)) return false;   // checks for the location of all y-coord. wrt status bar.
	if (P1.y < UI.ToolBarHeight || P2.y < UI.ToolBarHeight || P3.y < UI.ToolBarHeight) return false;   // checks for the location of all y-coord. wrt to toolbar.
	if (P1.x < 0 || P2.x < 0 || P3.x < 0) return false;        // checks for the location of all x-coord. wrt left most of UI.
	if (P1.x > 1300 || P2.x > 1300 || P3.x > 1300) return false;  // checks for the location of all x-coord. wrt to right most of UI.
	return true;
}

bool Output::DrawCheck(Point P1, int radius) const       // circles.
{
	if (P1.y - UI.ToolBarHeight < radius) return false;   // checks for the distance between center of circle and toolbar.
	if ((800-UI.StatusBarHeight) - P1.y < radius) return false;   // checks for the distance between center of circle and status bar.
	if (1300 - P1.x < radius) return false;  // checks for distance between center of circle and right most of UI.
	if (P1.x < radius) return false;         // checks for distance between center of circle and left most of UI.

	return true;
}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

