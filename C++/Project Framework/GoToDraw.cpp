
#include"GoToDraw.h"
#include"ApplicationManager.h"




GoToDraw::GoToDraw(ApplicationManager *pApp) :Action(pApp)
{

}

void GoToDraw::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select: Please click on the figure you want to select");
	//pIn->GetPointClicked(click.x,click.y);
}
void GoToDraw::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->CreateDrawToolBar();
	
	pManager->clearlist(2);
	pManager->clearlist(3);

}

