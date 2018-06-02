
#include"GoToPlay.h"
#include"ApplicationManager.h"




GoToPlay::GoToPlay(ApplicationManager *pApp):Action(pApp)
{

}

void GoToPlay::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select: Please click on the figure you want to select");
	//pIn->GetPointClicked(click.x,click.y);
}
void GoToPlay::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->CreatePlayToolBar();

}