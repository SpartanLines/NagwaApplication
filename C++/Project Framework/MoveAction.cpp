#include"MoveAction.h"





MoveAction::MoveAction(ApplicationManager* pApp) :Action(pApp)
{
	count = 0;
	pointer_position = 0;
}


void MoveAction::ReadActionParameters()
{
	int x, y;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("click moving point");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(x, y);
	Point average_center = pManager->GetAverageCenter();
	oldaveragecenter = average_center;
	/*movingpoint.x=x-(average_center.x);
	movingpoint.y=y-(average_center.y);*/
	movingpoint.x = x;
	movingpoint.y = y;


}
void MoveAction::Execute()
{
	
	ReadActionParameters();
	std::ofstream outfile("systemfile.txt");
	pointer_position = outfile.tellp();
	count = pManager->ReturnSelectednum();
	if (!pManager->canmove(movingpoint.x, movingpoint.y))
	{
		pManager->GetOutput()->PrintMessage("Can't Move,A Figure will get out of boundries! Aborting Operation");
		succed = false;
		return;
	}
	int i = 0;
	CFigure * selected;
	while (i != pManager->getfigcount())
	{
		selected = pManager->GetSelection(i);
		if (selected != NULL)
		{
			Point difference;
			Point center = selected->GetCenter();
			difference.x = center.x - oldaveragecenter.x;
			difference.y = center.y - oldaveragecenter.y;

			selected->Move(movingpoint.x + difference.x, movingpoint.y + difference.y);
			int id = selected->GetID();
			outfile << id << "  " << center.x << "  " << center.y <<"  "<< movingpoint.x + difference.x << "  " << movingpoint.y + difference.y << endl;
		}
	}
	succed = true;
}




void MoveAction::Undo()
{
	if (succed)
	{
		std::ifstream outfile("systemfile.txt");
		outfile.seekg(pointer_position);
		int id, x, y, z, h;
		for (int i = 0; i < count; i++)
		{
			outfile >> id >> x >> y >> z >> h;
			pManager->movebyid(id, x, y);

		}
		return;
	}
}

void MoveAction::Redo()
{
	if (succed)
	{
		std::ifstream outfile("systemfile.txt");
		outfile.seekg(pointer_position);
		int id, x, y, z, h;
		for (int i = 0; i < count; i++)
		{
			outfile >> id >> x >> y >> z >> h;
			pManager->movebyid(id, z, h);

		}
		return;
	}
}