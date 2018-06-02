#include "CutAction.h"
#include"ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include"Figures\CFigure.h"

CutAction::CutAction(ApplicationManager *pApp) :Action(pApp)
{

}

void CutAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select: Please click on the figure you want to Cut");
	//pIn->GetPointClicked(click.x,click.y);
}
void CutAction::Execute()
{
	if (pManager->ReturnSelectednum()==0)return;
	ReadActionParameters();
	pManager->Copy();
	pManager->Delete();
}


