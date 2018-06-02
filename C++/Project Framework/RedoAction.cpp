#include "RedoAction.h"



RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp)
{

}

void RedoAction::ReadActionParameters()
{
	return;
}

void RedoAction::Execute()
{
	pManager->redo();
}