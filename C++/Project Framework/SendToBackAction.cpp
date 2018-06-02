#include"SendToBackAction.h"

SendToBackAction::SendToBackAction(ApplicationManager* pApp) : Action(pApp)
{
}
void SendToBackAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Sending the figures you chose to the back!");
}
void SendToBackAction::Execute()
{
	ReadActionParameters();
	pManager->SendBack();
}