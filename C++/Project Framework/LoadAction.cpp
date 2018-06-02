#include"LoadAction.h"
#include <Windows.h>
#include"SaveAction.h"
LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{
}


void LoadAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Load new figures into the file");

}

void LoadAction::Execute()
{
	if (pManager->getfigcount() != 0)// if there are figures, we prompt the user to save them first
	{
		if (MessageBox(0, "Do you want to save first?", "Exit", MB_YESNO) == IDYES){
			Action *save = new SaveAction(pManager);
			save->Execute();
		}
	}
	pManager->clearlist();//clears the list to load the new list
	OPENFILENAME ofn;
	char fileName[MAX_PATH] = "";
	ZeroMemory(&ofn, sizeof(ofn));

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = "Text Files\0*.txt\0Any File\0*.*\0";
	ofn.lpstrFile = fileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR;
	ofn.lpstrDefExt = "";



	if (GetOpenFileName(&ofn))
	{
	}
	std::ifstream infile (fileName, std::ifstream::in);
	
	pManager->Load(infile);
	


}