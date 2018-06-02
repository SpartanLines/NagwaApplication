#include <iostream>
using namespace std;
#include<fstream>
#include <windows.h>
#include"SaveAction.h"
SaveAction::SaveAction(ApplicationManager *pApp) : Action(pApp)
{}
void SaveAction::ReadActionParameters()
{
	
	//path =new char[ strlen(filename+1)];
	//strcpy(path, filename);
	//path[strlen(path)] = '/0';
}

void SaveAction::Execute()
{
	/*ReadActionParameters();*/
	//char filename[MAX_PATH];

	//OPENFILENAME ofn;
	//ZeroMemory(&filename, sizeof(filename));
	//ZeroMemory(&ofn, sizeof(ofn));
	//ofn.lStructSize = sizeof(ofn);
	//ofn.hwndOwner = NULL;  // If you have a window to center over, put its HANDLE here
	//ofn.lpstrFilter = "Text Files\0*.txt\0Any File\0*.*\0";
	//ofn.lpstrFile = filename;
	//ofn.nMaxFile = MAX_PATH;
	//ofn.lpstrTitle = "Select a File, yo!";
	//ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;
	//GetSaveFileNameA(&ofn);

	//if (GetSaveFileNameA(&ofn))
	//{
	//	std::cout << "You chose the file \"" << filename << "\"\n";
	//}
	//else
	//{
	//	// All this stuff below is to tell you exactly how you messed up above. 
	//	// Once you've got that fixed, you can often (not always!) reduce it to a 'user cancelled' assumption.
	//	switch (CommDlgExtendedError())
	//	{
	//	case CDERR_DIALOGFAILURE: std::cout << "CDERR_DIALOGFAILURE\n";   break;
	//	case CDERR_FINDRESFAILURE: std::cout << "CDERR_FINDRESFAILURE\n";  break;
	//	case CDERR_INITIALIZATION: std::cout << "CDERR_INITIALIZATION\n";  break;
	//	case CDERR_LOADRESFAILURE: std::cout << "CDERR_LOADRESFAILURE\n";  break;
	//	case CDERR_LOADSTRFAILURE: std::cout << "CDERR_LOADSTRFAILURE\n";  break;
	//	case CDERR_LOCKRESFAILURE: std::cout << "CDERR_LOCKRESFAILURE\n";  break;
	//	case CDERR_MEMALLOCFAILURE: std::cout << "CDERR_MEMALLOCFAILURE\n"; break;
	//	case CDERR_MEMLOCKFAILURE: std::cout << "CDERR_MEMLOCKFAILURE\n";  break;
	//	case CDERR_NOHINSTANCE: std::cout << "CDERR_NOHINSTANCE\n";     break;
	//	case CDERR_NOHOOK: std::cout << "CDERR_NOHOOK\n";          break;
	//	case CDERR_NOTEMPLATE: std::cout << "CDERR_NOTEMPLATE\n";      break;
	//	case CDERR_STRUCTSIZE: std::cout << "CDERR_STRUCTSIZE\n";      break;
	//	case FNERR_BUFFERTOOSMALL: std::cout << "FNERR_BUFFERTOOSMALL\n";  break;
	//	case FNERR_INVALIDFILENAME: std::cout << "FNERR_INVALIDFILENAME\n"; break;
	//	case FNERR_SUBCLASSFAILURE: std::cout << "FNERR_SUBCLASSFAILURE\n"; break;
	//	default: std::cout << "You cancelled.\n";
	//	}
	//}
	


		OPENFILENAME ofn;
		char fileName[MAX_PATH] = "";
		ZeroMemory(&ofn, sizeof(ofn));

		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.hwndOwner = NULL;
		ofn.lpstrFilter = "Text Files\0*.txt\0Any File\0*.*\0";
		ofn.lpstrFile = fileName;
		ofn.nMaxFile = MAX_PATH;
		ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY|OFN_NOCHANGEDIR;
		ofn.lpstrDefExt = "";

		char* fileNameStr;

		if (GetSaveFileName(&ofn))
			fileNameStr = fileName;
		/*if (MessageBox(0, "Do you want exit?", "Exit", MB_YESNO) == IDYES)return;*/
		
	
	CFigure *const*list = pManager->returnlist();
	
	std::ofstream outfile(fileName, std::ofstream::app);
	outfile << to_string(UI.FillColor.ucRed)<<"   " << to_string(UI.FillColor.ucGreen) <<"  "<< to_string(UI.FillColor.ucBlue) <<"  "<< to_string(UI.DrawColor.ucRed) << "   " << to_string(UI.DrawColor.ucGreen) << "   " << to_string(UI.DrawColor.ucBlue) << "  " << to_string(UI.BkGrndColor.ucRed) << "  " << to_string(UI.BkGrndColor.ucGreen) << "   " << to_string(UI.BkGrndColor.ucBlue) << endl;
	outfile << to_string(pManager->getfigcount()) << endl;
	for (int i = 0; i < pManager->getfigcount(); i++)
	{
		list[i]->Save(outfile);
	}
	outfile.close();
}
