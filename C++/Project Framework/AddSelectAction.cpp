#include"AddSelectAction.h"
#include"GUI\Input.h"
#include"GUI\Output.h"
#include"ApplicationManager.h"
#include"Figures\CRectangle.h"


AddSelectAction::AddSelectAction(ApplicationManager * pApp) :Action(pApp)
{
	
}

void AddSelectAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select: Please click on the figure you want to select,click out the drawing area to stop selecting");
	pIn->GetPointClicked(p.x, p.y);


}
void AddSelectAction::Execute()
{
	pManager->clearselection();
	if(pManager->getzoomed()==0)pManager->UpdateInterface();
	else pManager->UpdateInterface(-1, 1);
	CFigure * selected = NULL;
	
	do
	{
		ReadActionParameters();
		int i = 0;
		if (p.y < UI.ToolBarHeight)
		{
			ActionType Act = pManager->GetUserAction(p.x,p.y);
			pManager->ExecuteAction(Act);
			return;
		}
		selected = pManager->GetFigure(p.x, p.y,i);
		if (selected != NULL)
		{
			if (selected->IsSelected())
			{
				selected->SetSelected(false);
				pManager->UpdateInterface(i);
			}
			else
			{
				selected->SetSelected(true);
				pManager->UpdateInterface(i);
			}
		}
	} while (p.y > UI.ToolBarHeight & p.y < UI.height - UI.StatusBarHeight);
	if (pManager->getzoomed() != 0)pManager->UpdateInterface(-1, 1);

	pManager->printinfo();
}