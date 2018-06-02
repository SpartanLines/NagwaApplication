
#include"GUI\Input.h"
#include"GUI\Output.h"
#include"ApplicationManager.h"
#include"Figures\CFigure.h"
#include"ChangeBackGroundColor.h"
#define PI 3.14159265

ChangeBackGroundColorAction::ChangeBackGroundColorAction(ApplicationManager * pApp) :Action(pApp)
{

}


void ChangeBackGroundColorAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please choose a color from the wheel");
	pIn->GetPointClicked(click.x, click.y);
}

void ChangeBackGroundColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateColorsWheel();
	ReadActionParameters();
	float i=0;
	int z=0;
	if ((abs(300 - click.x) < 100)&(abs(200 + UI.ToolBarHeight - click.y) < 100))
	{
		float k = asin((float)(click.x - 300) / (float)100);
		//float i = (180 /PI)*k;
		///*if (i % 60 == 0)z = 0;
		//float slope = tan(theta*PI / 180);*/
		//int z = (int)i % 60;

		int x, y;
		x = click.x - 300;
		y = click.y - (200 + UI.ToolBarHeight);
		i = atan((float)abs(x) / (float)abs(y));
		i = (180 / PI)*i;
		if (x < 0)
		{
			if (y < 0)
			{
				i = 360 - i;
			}
			else
			{
				i = 180 + i;;
			}
		}
		else
		{
			if (y > 0) i = 180 - i;
		}
		z = (int)i % 60;
		//if (click.y>300 + UI.ToolBarHeight)i += 180;
		if (i<60 & i>0)
			newcolor = color(255, z * 4, 0);
		if (i<120 & i >= 60)
			newcolor = color(255 - z * 4, 255, 0);
		if (i<180 & i >= 120)
			newcolor = color(0, 255, z * 4);
		if (i<240 & i >= 180)
			newcolor = color(0, 255 - z * 4, 255);
		if (i<300 & i >= 240)
			newcolor = color(z * 4, 0, 255);
		if (i<360 & i >= 300)
			newcolor = color(255, 0, 255 - z * 4);
		k = i;
	}


	 wrongcolor = false;
	if (i < 300 & i >= 240)
	{
		if (z > 57 & z <= 60)
		{
			pOut->PrintMessage("You attempted to choose a wrong color for fill, please choose another color");
			wrongcolor = true;
		}
	}

		if (i< 360 & i >= 300)
		{
			if (z > 0 & z <= 4)
			{
				pOut->PrintMessage("You attempted to choose a wrong color for fill, please choose another color");
				wrongcolor = true;
			}
		}
		if (!wrongcolor)
		{
			old_color = UI.BkGrndColor;
			UI.BkGrndColor = newcolor;
			
		}

}
void ChangeBackGroundColorAction::Undo()
{
	if (!wrongcolor)
		UI.BkGrndColor = old_color;
}
void ChangeBackGroundColorAction::Redo()
{
	if (!wrongcolor)
		UI.BkGrndColor = newcolor;
}