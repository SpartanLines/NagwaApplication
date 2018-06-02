#include "RotateAction.h"

RotateAction::RotateAction(ApplicationManager *pApp) :Action(pApp)
{
	rot = new int[pManager->ReturnSelectednum()];
	no_of_rotated = pManager->ReturnSelectednum();
}

void RotateAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->CreateRotateChoice();
	pOut->PrintMessage("Choose a Rotation Angle");
	pIn->GetPointClicked(p.x, p.y);
	if (p.y > 200 & p.y < 300)
	{
		if (p.x > 904 & p.x < 970)angle_of_rotation = 90;
		else if(p.x > 970 & p.x < 1036)angle_of_rotation = 180;
		else if (p.x > 1036 & p.x < 1104)angle_of_rotation = 270;
		else angle_of_rotation = -1;
	}
	else angle_of_rotation = -1; //flaged for wrong angle
}

void RotateAction::Execute()
{
	
	ReadActionParameters();
	if (angle_of_rotation == -1||pManager->ReturnSelectednum()==0)

	{
		succed = false;
		return;
	}
	if (!pManager->canrotate(angle_of_rotation))
	{
		pManager->GetOutput()->PrintMessage("Can't rotate,A Figure will get out of boundries! Aborting Operation");
		succed = false;
		return;
	}
	int i = 0;
	int j=0;
	CFigure * selected;
	while (i != pManager->getfigcount())
	{
		selected = pManager->GetSelection(i);
		if (selected != NULL)
		{
			selected->Rotate(angle_of_rotation);
			rot[j] = selected->GetID();
		}
	}
	succed = true;
}
void RotateAction::Undo()
{
	if (succed)
	{
		CFigure *const*list = pManager->returnlist();
		for (int i = 0; i < pManager->getfigcount(); i++)
		{
			for (int j = 0; j < no_of_rotated;j++)
			{
				if (list[i]->GetID() == rot[j])
				{
					list[i]->Rotate(360 - angle_of_rotation);
				}
			}
		}
	}
	else return;
}
void RotateAction::Redo()
{
	if (succed)
	{
		CFigure *const*list = pManager->returnlist();
		for (int i = 0; i < pManager->getfigcount(); i++)
		{
			for (int j = 0; j < no_of_rotated; j++)
			{
				if (list[i]->GetID() == rot[j])
				{
					list[i]->Rotate( angle_of_rotation);
				}
			}
		}
	}
	else return;
}
