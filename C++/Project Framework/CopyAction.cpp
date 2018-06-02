#include "CopyAction.h"
#include"ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include"Figures\CFigure.h"

CopyAction::CopyAction(ApplicationManager *pApp) :Action(pApp)
{

}

void CopyAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Figures copied in the clipboard!");
	//pIn->GetPointClicked(click.x,click.y);
}
void CopyAction::Execute()
{
	ReadActionParameters();
	if (pManager->ReturnSelectednum() == 0)return;
	pManager->Copy();
	
}


