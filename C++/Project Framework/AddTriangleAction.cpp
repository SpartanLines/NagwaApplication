#include "AddTriangleAction.h"
#include "Actions\Action.h"
#include"GUI\Input.h"
#include"GUI\Output.h"
#include"ApplicationManager.h"
#include "CTriangle.h"

AddTriangleAction::AddTriangleAction(ApplicationManager * pApp) :Action(pApp)
{
}


void AddTriangleAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at Third corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P3.x, P3.y);
	TriGfxInfo.myshape = TRIANGLE;
	TriGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();
    TriGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();


}
void AddTriangleAction :: Execute()
{
    //This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CTriangle *T=new CTriangle(P1, P2, P3, TriGfxInfo);
	
	//Add the rectangle to the list of figures
	pManager->AddFigure(T);

}

void AddTriangleAction::Undo()
{
	pManager->removefromend();

}
void AddTriangleAction::Redo()
{
	CTriangle *T = new CTriangle(P1, P2, P3, TriGfxInfo);
	pManager->AddFigure(T);

}