#include "DeleteAction.h"
#include"ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include"Figures\CFigure.h"
#include"CCircle.h"
#include"CTriangle.h"
#include"CLine.h"
#include"Figures\CRectangle.h"

DeleteAction::DeleteAction(ApplicationManager *pApp) :Action(pApp)
{
	count = 0;
	pointer_position = 0;
}

void DeleteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select: Please click on the figure you want to delete");
	//pIn->GetPointClicked(click.x,click.y);

}
void DeleteAction::Execute()
{
	ReadActionParameters();
	std::ofstream outfile("systemfile.txt");
	pointer_position = outfile.tellp();
	count = pManager->ReturnSelectednum();
	pManager->Delete();
	/*if(pManager->getzoomed()!=0)pManager->UpdateInterface(-1, 1);*/
}

void DeleteAction::Redo()
{
	pManager->deletefromend(count);
}
void DeleteAction::Undo()
{
	std::ifstream infile("systemfile.txt");
	infile.seekg(pointer_position);
	CFigure* ptr;
	for (int i = 0; i < count; i++)
	{
		string s;
		infile >> s;
		if (s == "Tria") ptr = new CTriangle();
		if (s == "Circ") ptr = new CCircle();
		if (s == "Line") ptr = new CLine();
		if (s == "Rect") ptr = new CRectangle();
		ptr->Load(infile);
		pManager->AddFigure(ptr);
	}
}