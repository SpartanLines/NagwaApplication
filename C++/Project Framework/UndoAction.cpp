#include "UndoAction.h"


UndoAction::UndoAction(ApplicationManager* pApp) : Action(pApp)
{
}
void UndoAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Undoing your last action!");
}
void UndoAction::Execute()
{
	ReadActionParameters();
	pManager->undo();
}