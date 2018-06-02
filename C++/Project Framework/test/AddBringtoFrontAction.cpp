#include "AddBringtoFrontAction.h"
#include"GUI\Input.h"
#include"GUI\Output.h"

//#include "AddSelectAction.h"

AddBringtoFrontAction::AddBringtoFrontAction(ApplicationManager * pApp) :Action(pApp)
{
}
void AddBringtoFrontAction :: ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Bring to front, select a figure");

}
void AddBringtoFrontAction :: Execute()
{
	ReadActionParameters();
	CFigure *temp;
	int m=pManager->getfigcount();
	temp=pManager->getFigurePtr(0);
	CFigure*x;
	CFigure*y;
	CFigure*z;
	for(int i=0;i<m-1;i++)
	{
	x=pManager->getFigurePtr(i);
	y=pManager->getFigurePtr(i+1);
	x=y;
	}
	z=pManager->getFigurePtr(m-1);
	z=temp;
	//pManager->BringToFront();
}