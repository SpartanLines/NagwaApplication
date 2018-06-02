#include "ZoomAction.h"

ZoomAction::ZoomAction(ApplicationManager *pApp) :Action(pApp)
{}

void ZoomAction::ReadActionParameters()
{
	return;

}
void ZoomAction::Execute()
{
	if (pManager->getzoomed() > 5)
	{
		pManager->GetOutput()->PrintMessage("Can't Zoom any more, or figures will disappear!");
		return;
	}
	pManager->GetOutput()->PrintMessage("Choose Zoooom In Or Out");
	pManager->GetOutput()->CreateZoomChoice();
	Point P;
	pManager->GetInput()->GetPointClicked(P.x,P.y);
	ReadActionParameters();
	float t;
	if (P.y > 200 & P.y < 300)
	{

		if (P.x > 904 & P.x < 1004) t = sqrt(2);
		else if (P.x > 1004 & P.x < 1104)t =( 1/sqrt(2));
		else t = 1;
	}

	else t = 1;
	pManager->zoom(t);
	pManager->UpdateInterface(-1, 1);


}
