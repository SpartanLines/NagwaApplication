#include "pasteAction.h"
#include"ApplicationManager.h"
#include"ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include"Figures\CFigure.h"
#include"CCircle.h"
#include"CTriangle.h"
#include"CLine.h"
#include"Figures\CRectangle.h"

PasteAction::PasteAction(ApplicationManager *pApp) :Action(pApp)
{
	count = pManager->getclipboardcount();
}

void PasteAction::ReadActionParameters()
{
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select: Please click on the location you want to Paste");
	pIn->GetPointClicked(PastePnt.x, PastePnt.y);
	/*PastePnt.x = x - (pManager->GetAvCClipboard().x);
	PastePnt.y = y - (pManager->GetAvCClipboard().y);*/
}
void PasteAction::Execute()
{
	ReadActionParameters();
	std::ofstream outfile("systemfile.txt");
	pointer_position = outfile.tellp();
succed=	pManager->Paste(PastePnt.x, PastePnt.y);
if (succed == false)pManager->GetOutput()->PrintMessage("Can't Paste Figures Out Of Border!");
	/*pManager->UpdateInterface();
	pManager->Paste(PastePnt.x,PastePnt.y);*/

}


void PasteAction::Undo()
{
	if (succed)
	pManager->deletefromend(count);

}
void PasteAction::Redo()
{
	if (succed)
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
}
