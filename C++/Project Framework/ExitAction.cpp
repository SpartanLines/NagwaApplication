#include"ExitAction.h"
#include<Windows.h>
#include"SaveAction.h"
ExitAction::ExitAction(ApplicationManager *pApp):Action(pApp)
{

}
void ExitAction::ReadActionParameters()
{
	if (MessageBox(0, "Do you want to save first?", "Exit", MB_YESNO) == IDYES){
		Action *save = new SaveAction(pManager);
		save->Execute();
	}
	if (MessageBox(0, "Are you sure you want to exit?", "Exit", MB_YESNO) == IDYES)exit = true;
	else exit = false;
}
void ExitAction::Execute()
{
	ReadActionParameters();
	if (exit)
	{
		pManager->setstate(false);
		pManager->clearlist(2);
		pManager->clearlist(3);
	}
	else return;
}