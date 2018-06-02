#include "ChangeBorderWidthAction.h"

ChangeBorderWidthAction::ChangeBorderWidthAction(ApplicationManager * pApp) :Action(pApp)
{

}

void ChangeBorderWidthAction::ReadActionParameters()
{
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select A Factor To Enlarge the border width with:");
	pIn->GetPointClicked(P.x, P.y);
	
	

}
void ChangeBorderWidthAction::Execute()
{
	pManager->GetOutput()->CreateBorderwidthChoice();
	ReadActionParameters();
	float t;
	if (P.y > 200 & P.y < 250)
	{
		
		if (P.x > 904 & P.x < 1004) t =1;
		else if (P.x > 1004 & P.x < 1104)t =2;
		else t = 1;
	}
	else if (P.y > 250 & P.y < 300)
	{

		if (P.x > 904 & P.x < 1004) t = 3;
		else if (P.x > 1004& P.x < 1104)t = 6;
		else t = 1;
	}
	else t = 1;
	int i = 0;
	CFigure * selected;
	while (i != pManager->getfigcount())
	{
		selected = pManager->GetSelection(i);
		if (selected != NULL) selected->ChngBorderWdth(t);
	}
}