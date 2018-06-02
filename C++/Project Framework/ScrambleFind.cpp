#include "ScrambleFind.h"
#include"ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include"Figures\CFigure.h"
#include "Actions\Action.h"

ScrambleFind::ScrambleFind(ApplicationManager *pApp) :Action(pApp)
{

}
void ScrambleFind::ReadActionParameters()
{
	int x, y;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->CreatePlay3();
}
void ScrambleFind::Execute()
{
	ReadActionParameters();
	pManager->ScrambleAndFind();
}


