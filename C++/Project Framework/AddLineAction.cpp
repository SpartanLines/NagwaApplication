#include "AddLineAction.h"
#include "AddLineAction.h"
#include "CLine.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

AddLineAction::AddLineAction(ApplicationManager *pApp) : Action (pApp)
{}

void AddLineAction:: ReadActionParameters()
{
    Output *pOut = pManager->GetOutput();
    Input *pIn = pManager->GetInput();

    pOut->PrintMessage("New Line: Click on first point");
    pIn->GetPointClicked(P1.x,P1.y);

    pOut->PrintMessage("New Line: Click on second point");
    pIn->GetPointClicked(P2.x,P2.y);

    LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
    LineGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	LineGfxInfo.myshape = LINE;
    pOut->ClearStatusBar();
}

void AddLineAction:: Execute()
{
    ReadActionParameters();

    CLine *L = new CLine(P1,P2,LineGfxInfo);
	
    pManager->AddFigure(L);
}


void AddLineAction::Undo()
{
	pManager->removefromend();

}
void AddLineAction::Redo()
{
	CLine *L = new CLine(P1, P2, LineGfxInfo);
	pManager->AddFigure(L);
}