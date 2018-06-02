#include "ResizeAction.h"
ResizeAction::ResizeAction(ApplicationManager *pApp) :Action(pApp)
{
	id = new int[pManager->ReturnSelectednum()];
	num = pManager->ReturnSelectednum();
}

void ResizeAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select: Please click on the figure you want to Resize");
	pIn->GetPointClicked(P.x,P.y);
}
void ResizeAction::Execute()
{
	//ReadActionParameters();
	//Output* pOut = pManager->GetOutput();
	//Input* pIn = pManager->GetInput();
	//pOut->CreateResizeToolBar();
	pManager->GetOutput()->CreateResizeChoice();
	ReadActionParameters();

	float t;//float to store the resize factor
	if (P.y > 200 & P.y < 250)
	{

		if (P.x > 904 & P.x < 1004) t = 0.25;
		else if (P.x > 1004 & P.x < 1104)t = 0.5;
		else t = 1;
	}
	else if (P.y > 250 & P.y < 300)
	{

		if (P.x > 904 & P.x < 1004) t = 2;
		else if (P.x > 1004 & P.x < 1104)t = 4;
		else t = 1;
	}
	else t = 1;
	
	// we check where the user has pressed, if he chose one of the 4 options we resize by that factor, else we resize by 1 i.e leave it as it is
	if (t == 1)
	{
		succed = false;
		return;
	}
	if (!pManager->canresize(t))
	{
		pManager->GetOutput()->PrintMessage("Can't rotate,A Figure will get out of boundries! Aborting Operation");
		succed = false;
		return;
	}
	int i = 0;
	int j = 0;
	CFigure * selected;
	factor = t;
	while (i != pManager->getfigcount())
	{
		selected = pManager->GetSelection(i);
		if (selected != NULL)
		{
			selected->Resize(t);
			id[j] = selected->GetID();
			j++;
		}
	}
}

void ResizeAction::Undo()
{
	if (succed)
	{
		
		CFigure *const*list = pManager->returnlist();
		for (int i = 0; i < pManager->getfigcount(); i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (list[i]->GetID() == id[j])
				{
					list[i]->Resize(1/factor);
				}
			}
		}
	}
	else return;
}
void ResizeAction::Redo()
{
	if (succed)
	{

		CFigure *const*list = pManager->returnlist();
		for (int i = 0; i < pManager->getfigcount(); i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (list[i]->GetID() == id[j])
				{
					list[i]->Resize( factor);
				}
			}
		}
	}
	else return;
}
