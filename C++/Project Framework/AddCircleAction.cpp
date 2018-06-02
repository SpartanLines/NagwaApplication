#include "AddCircleAction.h"
#include"GUI\Input.h"
#include"GUI\Output.h"
#include"ApplicationManager.h"
#include"CCircle.h"
#include<cmath>

AddCircleAction::AddCircleAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

CircleGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();
	CircleGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	CircleGfxInfo.myshape = CIRCLE;

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	 radius = sqrt(pow(P2.x - P1.x, 2.0) + pow(P2.y - P1.y, 2.0));    // calculating radius.
	//Create a rectangle with the parameters read from the user
	CCircle *R = new CCircle(P1, radius, CircleGfxInfo);
	
	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}

void AddCircleAction::Undo()
{
	pManager->removefromend();

}
void AddCircleAction::Redo()
{
	CCircle *R = new CCircle(P1, radius, CircleGfxInfo);
	pManager->AddFigure(R);
}