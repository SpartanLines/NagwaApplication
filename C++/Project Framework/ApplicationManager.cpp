#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Figures\CRectangle.h"
#include "AddSelectAction.h"
#include"AddCircleAction.h"
#include "GoToDraw.h"
#include"AddLineAction.h"
#include"AddTriangleAction.h"
#include"MoveAction.h"
#include"GoToPlay.h"
#include "ChangeFillColorAction.h"
#include"RotateAction.h"
#include"ChangeBackGroundColor.h"
#include"ChangeDrawColorAction.h"
#include "ChangeFillColorAction.h"
#include "ZoomAction.h"
#include "ChangeBorderWidthAction.h"
#include "DeleteAction.h"
#include "PasteAction.h"
#include "CutAction.h"
#include"CopyAction.h"
#include"SaveAction.h"
#include "ResizeAction.h"
#include "ExitAction.h"
#include "ScrambleFind.h"
#include <algorithm>
#include"AddBringtoFrontAction.h"
#include"PicknHideAction.h"
#include"LoadAction.h"
#include"CCircle.h"
#include"CTriangle.h"
#include"CLine.h"
#include"Figures\CRectangle.h"
#include "SendToBackAction.h"
#include "UndoAction.h"
#include"RedoAction.h"
#include <Windows.h>
#include<mmsystem.h>
//Constructor

Point operator +(Point&p1, Point &p2)
{
	Point P;
	P.x = p1.x + p2.x;
	P.y = p1.y + p2.y;
	return P;
}
Point operator -(Point&p1, Point &p2)
{
	Point P;
	P.x = p1.x - p2.x;
	P.y = p1.y - p2.y;
	return P;
}
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	clipboardcount = 0;
	zoomed = 0;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
	Clipboard = NULL;
	state = true;
	is_fill_color_chosen = false;
	RightList = NULL;
	LeftList = NULL;
	LeftCount = 0;
	RightCount = 0;
	flag = false;
}
bool ApplicationManager::getstate() const
{
	return state;
}
void ApplicationManager::setstate(bool t) 
{
	state = t;
	return;
}
//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction(int x,int y) const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction(x,y);		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	if (zoomed == 0)
	{
		switch (ActType)
		{

		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_CIRC:
			pAct = new AddCircleAction(this);
			PlaySoundA("Circle.wav", NULL, SND_ASYNC);
			break;
		case DRAW_LINE:
			pAct = new AddLineAction(this);
			PlaySoundA("Line.wav", NULL, SND_ASYNC);
			break;
		case DRAW_TRI:
			pAct = new AddTriangleAction(this);
			
			break;
		case UNDO:
			pAct = new UndoAction(this);
			
			break;
		case SELECT:
			pAct = new AddSelectAction(this);
			break;
		case RESIZE:
			pAct = new ResizeAction(this);
			break;
		case MOVE:
			pAct = new MoveAction(this);
			break;

		case BRNG_FRNT:
			pAct = new AddBringtoFrontAction(this);
			PlaySoundA("BringToFront.wav", NULL, SND_ASYNC);
			break;
		case EXIT:
			///create ExitAction here
			pAct = new ExitAction(this);
			PlaySoundA("Applause.wav", NULL, SND_ASYNC);
			break;
		case REDO:
			pAct = new RedoAction(this);
			break;
		case ROTATE:
			pAct = new RotateAction(this);
			break;
		case SAVE:
			pAct = new SaveAction(this);
			break;
		case CHNG_FILL_CLR:
			pAct = new ChangeFillColorAction(this);
			break;
		case TO_PLAY:
			pAct = new GoToPlay(this);
			PlaySoundA("Whistle.wav", NULL, SND_ASYNC|SND_FILENAME);
			break;
			/*case ZOOM:
				pAct = new Zoom(this);*/
		case CHNG_BK_CLR:
			pAct = new ChangeBackGroundColorAction(this);
			break;
		case ZOOM:
			pAct = new ZoomAction(this);
			break;
		case BORDER:
			pAct = new ChangeBorderWidthAction(this);
			PlaySoundA("Border.wav", NULL, SND_ASYNC);
			break;
		case CUT:
			pAct = new CutAction(this);
			PlaySoundA("Cut.wav", NULL, SND_ASYNC);
			break;
			case COPY:
			pAct = new CopyAction(this);
			PlaySoundA("Copy.wav", NULL, SND_ASYNC);
			break;
		case PASTE:
			pAct = new PasteAction(this);
			break;
		case DEL:
			pAct = new DeleteAction(this);
			PlaySoundA("Delete.wav", NULL, SND_ASYNC);
			break;
		case PICK_HIDE:
			pAct = new PicknHideAction(this);
			break;
		case CHNG_DRAW_CLR:
			pAct = new ChangeDrawColorAction(this);
			break;
		case TO_DRAW:
				pAct = new GoToDraw(this);
				break;
				
		case SCRAMBLE_FIND:
			pAct = new ScrambleFind(this);
			break;
		case STATUS:	//a click on the status bar ==> no action
			return;
		case LOAD:
			pAct = new LoadAction(this);
			break;
		case SEND_BACK:
			pAct = new SendToBackAction(this);
			break;
		}
	}
	//Execute the created action
	else
	{
		if (ActType != ZOOM & ActType != SAVE & ActType != EXIT & ActType != LOAD & ActType != DEL & ActType != SELECT & ActType != CHNG_BK_CLR & ActType != CHNG_DRAW_CLR & ActType != CHNG_FILL_CLR & ActType != BORDER)
		{
			string n;
			if (zoomed > 0)  n = "zoom out "+abs(zoomed);
			else n = "zoom in " + abs(zoomed);
			
			pOut->PrintMessage("You Can't Choose Other Actions While Zoomed. To restore you need to "+n);
		}
		else
		{
			switch (ActType)
			{
			case CHNG_DRAW_CLR:
				pAct = new ChangeDrawColorAction(this);
				break;
			
			case DEL:
				pAct = new DeleteAction(this);
				break;
			case CHNG_BK_CLR:
				pAct = new ChangeBackGroundColorAction(this);
				break;
			case ZOOM:
				pAct = new ZoomAction(this);
				break;
			case BORDER:
				pAct = new ChangeBorderWidthAction(this);
				break;
			
			case SAVE:
				pAct = new SaveAction(this);
				break;

			case SELECT:
				pAct = new AddSelectAction(this);
				break;
			case EXIT:
				///create ExitAction here
				pAct = new ExitAction(this);
				break;
			case CHNG_FILL_CLR:
				pAct = new ChangeFillColorAction(this);
				break;
			}
		
		
		}
	
	}
	
	if (pAct != NULL)
	{
		if (ActType == REDO)
		{
			if (flag){
				pAct->Execute();
				delete pAct;
				pAct = NULL;
				return;
			}
			else {
				aux.clear();
			}
		}
		if (ActType == UNDO)flag = true;
		else flag = false;
		pAct->Execute();
	}
		 //Execute
			//Action is not needed any more ==> delete it
		
		if (ActType != UNDO&ActType != SELECT&ActType != SAVE&ActType != LOAD&ActType != CUT&ActType != COPY&ActType != TO_DRAW&ActType != TO_PLAY&ActType!=REDO)
		{
	              pushaction(pAct);
		}
		else
		{
			delete pAct;
			pAct = NULL;
		}
	
	}

//creates a copy of the chosen objects and checks if they are drawable after moving
bool ApplicationManager::canmove(int x,int y)
{
	CFigure* test;
	Point center = GetAverageCenter();
	Point difference;

	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{	
			test = FigList[i]->Copy();
			difference = test->GetCenter() - center;
			test->Move(x + difference.x, y + difference.y);
			if (!test->Draw(pOut))
			{
				delete test;
				return false;
			}
			delete test;
		}
	}
	return true;
}
//creates a copy of the chosen objects and checks if they are drawable after resizing
bool ApplicationManager::canrotate(int angle)
{
	CFigure* test;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			test = FigList[i]->Copy();
			test->Rotate(angle);
			if (!test->Draw(pOut)){
				delete test;
				return false;
			}
			delete test;
		}
	}
	return true;
}
CFigure* const* ApplicationManager::returnlist()const
{
		return FigList ;
}
//creates a copy of the chosen objects and checks if they are drawable after resizing
bool ApplicationManager::canresize(int factor)
{
	CFigure* test;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			test = FigList[i]->Copy();
			test->Resize(factor);
			if (!test->Draw(pOut)){
				delete test;
				return false;
			}
			delete test;
		}
	}
	return true;
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::removefromend()
{
	FigList[FigCount - 1] = NULL;// doesn't delete because the figure pointed to should remain held by the action
	FigCount--;
}
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (pFig->Draw(pOut))
	{
		if (FigCount < MaxFigCount)
			FigList[FigCount++] = pFig;
		if (is_fill_color_chosen)
			pFig->ChngFillClr(UI.FillColor);
	}
}
void ApplicationManager::redo()
{
	if (aux.size() != 0)
	{
		Action* undone;
		undone = aux.back();
		undone->Redo();
		aux.pop_back();
		myactions.push_back(undone);
	}
}
bool ApplicationManager::canpaste(int x,int y)
{
	CFigure* test;
	Point center = GetAvCClipboard();
	Point difference;

	for (int i = 0; i < clipboardcount; i++)
	{
		
			test = Clipboard[i]->Copy();
			difference = test->GetCenter() - center;
			test->Move(x + difference.x, y + difference.y);
			if (!test->Draw(pOut))
			{
				delete test;
				return false;
			}
			delete test;
		
	}
	return true;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y, int &k, int i) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	///Add your code here to search for a figure given a point x,y	
	if (i == -1)
	{
		for (int j = FigCount - 1; j > -1; j--)
		{
			k = j;
			if (FigList[j]->isPointInside(x, y))
			{

				return FigList[j];
			}
		}
		return NULL;
	}
	else if (i == -2)//for scramble and find mode
	{
		for (int j = RightCount - 1; j > -1; j--)
		{
			if (RightList[j]->isPointInside(x, y))
			{

				return RightList[j];
			}
		}

		return NULL;
	}
	else
	{
		for (int j = LeftCount - 1; j > -1; j--)// for pick and hide
		{
			if (LeftList[j]->isPointInside(x, y))
			{

				k = j;
				return LeftList[j];
			}
		}
		k = -1;
		return NULL;
	}
}



CFigure * ApplicationManager::GetSelection(int&i)const
{
for (int j = i; j < FigCount; j++)
	{
		if (FigList[j]->IsSelected())
		{
			i = j+1;
			return FigList[j];
		}
	}
i = FigCount;
return NULL;
}
void ApplicationManager::setfillchosen(bool ischosen)
{
	is_fill_color_chosen = ischosen;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdatePlayInterface(int i)const
{
	if (i != -1)// to draw a specific figure
	{
		LeftList[i]->Draw(pOut);
		return;
	}
	pOut->ClearDrawArea();
	for (int j = 0; j < RightCount; j++)
	{
		RightList[j]->Draw(pOut);//Call Draw function (virtual member fn)
		
	}
	for (int j = 0; j < LeftCount; j++)
	{
		LeftList[j]->Draw(pOut);//Call Draw function (virtual member fn)

	}
}
void ApplicationManager::UpdateInterface(int i,int k) const
{	
	if (i != -1)// to draw a specific figure
	{
		FigList[i]->Draw(pOut);
		return;
	}
	pOut->ClearDrawArea();
	for (int j = 0; j < FigCount; j++)
	{
		FigList[j]->Draw(pOut, k);//Call Draw function (virtual member fn)
	}
		if (zoomed != 0)
	{
		pOut->CreateZoomedToolbar();
	}
}
void ApplicationManager::clearlist(int i)
{
	if (i == 1)
	{
		for (int i = 0; i < FigCount; i++)
		{
			delete FigList[i];
			FigList[i] = NULL;

		}
		FigCount = 0;
		return;
	}
	else if (i == 2)//for pick and hide
	{
		for (int i = 0; i < LeftCount; i++)
		{
			delete LeftList[i];
			 
		}
		delete[] LeftList;
		LeftList = NULL;
		LeftCount = 0;
		return;
	}
	else if (i == 3)//for scramble and  find
	{
		for (int i = 0; i < LeftCount; i++)
		{
			delete LeftList[i];

		}
		delete[] LeftList;
		LeftList = NULL;
		LeftCount = 0;
		for (int i = 0; i < RightCount; i++)
		{
			delete RightList[i];

		}
		delete[] RightList;
		RightList = NULL;
		RightCount = 0;
		return;
	}






}
void ApplicationManager::undo()
{
	if (myactions.size() == 0)return;
	Action* undone;
	undone = myactions[myactions.size()-1];
	undone->Undo();
	myactions.pop_back();
	aux.push_back(undone);


}

void ApplicationManager::Load(ifstream &infile)
{
	int one, two, three, four, five, six, seven, eight, nine;
	infile >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine;
	UI.DrawColor.ucRed = one;
	UI.DrawColor.ucGreen = two;
	UI.DrawColor.ucBlue = three;
	UI.FillColor.ucRed = four;
	UI.FillColor.ucGreen = five;
	UI.FillColor.ucBlue = six;
	UI.BkGrndColor.ucRed = seven;
	UI.BkGrndColor.ucGreen = eight;
	UI.BkGrndColor.ucBlue = nine;
	infile >> FigCount;
	for (int i = 0; i < FigCount; i++)
	{
		string s;
		infile >> s;
		if (s == "Tria")FigList[i] = new CTriangle();
		if (s == "Circ")FigList[i] = new CCircle();
		if (s == "Line")FigList[i] = new CLine();
		if (s == "Rect")FigList[i] = new CRectangle();
		FigList[i]->Load(infile);
	}
}
void ApplicationManager::movebyid(int id, int x, int y)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->GetID() == id)
		{
			FigList[i]->Move(x, y);
			return;
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	std::ofstream outfile("systemfile.txt");
	outfile.clear();
	
}

  int ApplicationManager::getfigcount(int i)
{
	if (i == 1)
		return FigCount;
	else
		return LeftCount;
}
  void ApplicationManager:: clearselection()
  {
	  for (int i = 0; i < FigCount;i++)
	  {
		  FigList[i]->SetSelected(false);
      }
  }
 CFigure** ApplicationManager :: getFigurePtrPtr()
  {
	  return FigList;
  }
 CFigure* ApplicationManager :: getFigurePtr(int i)
 {
	 return FigList[i];
 }
 void ApplicationManager::zoom(float factor)
 {
	 for (int i = 0; i < FigCount; i++)
	 {
		 FigList[i]->Zoom(factor);
	 }
	
	 if (factor > 1)
	 {
		 pOut->PrintMessage("Zoomed in, Actions will be disabled until you zoom out");
		 if (zoomed == -1) pOut->CreateDrawToolBar();
		 zoomed++;
	 }
	 else
	 {
		 if (zoomed == 1)pOut->CreateDrawToolBar();
		 zoomed--;
		 pOut->PrintMessage("Zoomed Out, Actions will be disabled until you return to original size,left zoom outs:"+to_string(zoomed));
	 }
 }
 int ApplicationManager::getzoomed()
 {
	 return zoomed;
 }
 void ApplicationManager::CreateClipboard(int n)
 {
	 if (Clipboard != NULL)
		 for (int i = 0; i<clipboardcount; i++)
		 {
			 delete Clipboard[i];
		 }
	 delete[]Clipboard;

	 Clipboard = new CFigure*[n];
	 maxClipboardCount = n;
	 clipboardcount = 0;
 }
 int ApplicationManager::ReturnSelectednum()
 {
	 int c = 0;
	 for (int i = 0; i<FigCount; i++)
	 {
		 if (FigList[i]->IsSelected())
			 c++;
	 }
	 Selectednum = c;
	 return Selectednum;
 }
 CFigure* ApplicationManager::ReturnClipboardfig(int i)
 {
	 return Clipboard[i];
 }
 bool ApplicationManager::AddinClipboard(CFigure* c)
 {


	 if (clipboardcount < maxClipboardCount)
	 {
		 Clipboard[clipboardcount++] = c;
		 return true;
	 }
	 return false;
 }
 void ApplicationManager::deletefromend(int x)
 {
	 for (int i = 0; i < x; i++)
	 {
		 delete FigList[FigCount-1];
		 FigList[FigCount -1] = NULL;
		 FigCount--;
	 }
 }
 void ApplicationManager::Delete()
 {
	 int c = 0;


	 if (UI.InterfaceMode == MODE_DRAW)
	 {
		 /* for (int i = 0; i < FigCount; i++)
		  {
		  if (FigList[i]->IsSelected())
		  {
		  delete FigList[i];
		  FigList[i] = NULL;
		  FigList[i] = FigList[i + 1];
		  c++;


		  }
		  }
		  FigCount -= c;*/
		 std::ofstream outfile("systemfile.txt");
		 for (int i = 0; i < FigCount-1; i++)
		 {
			 if (FigList[i]->IsSelected())
			 {
				 do{
					 FigList[i]->Save(outfile);
				 delete FigList[i];
				 FigList[i] = NULL;
				 int j = i + 1;
				 
					 while (!(j > FigCount - 1))
					 {
						 FigList[j - 1] = FigList[j];
						 j++;
					 }
					 
					 FigList[j - 1] = NULL;
					 FigCount--;
					 if (FigCount == 0)break;
				 } while (FigList[i]->IsSelected());
			 }
			 
			 }
		 if (FigCount != 0)
		 {
			 if (FigList[FigCount - 1]->IsSelected()){
				 FigList[FigCount - 1]->Save(outfile);
				 delete FigList[FigCount - 1];
				 FigList[FigCount - 1] = NULL;
				 FigCount--;
			 }
		 }
	 }
	 else
	 {
		 
			 /*for (int i = 0; i < LeftCount - 1; i++)
			 {
			 if (LeftList[i]->IsSelected())
			 {
			 delete LeftList[i];
			 LeftList[i] = NULL;
			 LeftList[i] = LeftList[i + 1];
			 c++;

			 }
			 }
			 if (LeftList[LeftCount - 1]->IsSelected())
			 {
			 delete LeftList[LeftCount - 1];
			 LeftList[LeftCount - 1] = NULL;
			 c++;
			 }

			 LeftCount -= c;*/
			 for (int i = 0; i < LeftCount - 1; i++)
			 {
				 if (LeftList[i]->IsSelected())
				 {
					 do{
						 delete LeftList[i];
						 LeftList[i] = NULL;
						 int j = i + 1;

						 while (!(j > LeftCount - 1))
						 {
							 LeftList[j - 1] = LeftList[j];
							 j++;
						 }

						 LeftList[j - 1] = NULL;
						 LeftCount--;
					 } while (LeftList[i]->IsSelected());
				 }

			 }
			 if (LeftCount != 0)
			 {
				 if (LeftList[LeftCount - 1]->IsSelected()){
					 delete LeftList[LeftCount - 1];
					 LeftList[LeftCount - 1] = NULL;
					 LeftCount--;
				 }
			 }
			 /* c = 0;
			  for (int i = 0; i < RightCount - 1; i++)
			  {
			  if (RightList[i]->IsSelected())
			  {
			  delete RightList[i];
			  RightList[i] = NULL;
			  RightList[i] = RightList[i + 1];
			  c++;

			  }
			  }
			  if (RightList[RightCount - 1]->IsSelected())
			  {
			  delete RightList[RightCount - 1];
			  RightList[RightCount - 1] = NULL;
			  c++;
			  }
			  RightCount -= c;*/
			 for (int i = 0; i < RightCount - 1; i++)
			 {
				 if (RightList[i]->IsSelected())
				 {
					 do{
						 delete RightList[i];
						 RightList[i] = NULL;
						 int j = i + 1;

						 while (!(j > RightCount - 1))
						 {
							 RightList[j - 1] = RightList[j];
							 j++;
						 }

						 RightList[j - 1] = NULL;
						 RightCount--;
					 } while (RightList[i]->IsSelected());
				 }

			 }
			 if (RightCount != 0)
			 {
				 if (RightList[RightCount - 1]->IsSelected()){
					 delete RightList[RightCount - 1];
					 RightList[RightCount - 1] = NULL;
					 RightCount--;
				 }
			 }
		 }
	 }
 
 bool ApplicationManager::Paste(int x, int y)
 {
	 Point Averagecenter = GetAverageCenter(-1);
	 if (canpaste(x,y))
	 {
		 for (int i = 0; i < clipboardcount; i++)
		 {
			 Point center = Clipboard[i]->GetCenter();


			 Point difference = center - Averagecenter;

			 Clipboard[i]->Move(x + difference.x, y + difference.y);
			 CFigure* copied = Clipboard[i]->Copy();
			 //FigCount++;
			 copied->SetSelected(false);
			 AddFigure(copied);
			 std::ofstream outfile("systemfile.txt", std::ofstream::app);
			 copied->Save(outfile);
			 /*FigList[FigCount - 1]->SetSelected(false);*/

		 }
		 return true;
	 }
	 else return false;

 }
 Point ApplicationManager::GetAverageCenter(int i)
 {
	 int s = 0;
	 Point p;
	 p.x = 0; p.y = 0;
	 if (i == 1)
	 {
		/* for (int i = 0; i < FigCount; i++) // to make it move or paste by the average center
		 {
			 if (FigList[i]->IsSelected())
			 {
				 s++;
				 p.x += FigList[i]->GetCenter().x;
				 p.y += FigList[i]->GetCenter().y;
			 }
		 }
		 if (s != 0)
		 {
			 p.x = p.x / s;
			 p.y = p.y / s;
		 }*/
		 for (int i = 0; i < FigCount; i++)
		 {
			 if (FigList[i]->IsSelected())
			 {
				 return FigList[i]->GetCenter();// to make it paste or move by the center of the first chosen figure in the list
			 }
		 }
	 }
	 if (i == -1)
	 {
		 for (int i = 0; i < clipboardcount; i++)
		 {

			 s++;
			 p.x += Clipboard[i]->GetCenter().x;
			 p.y += Clipboard[i]->GetCenter().y;

		 }
		 if (s != 0)
		 {
			 p.x = p.x / s;
			 p.y = p.y / s;
		 }
	 }
	 return p;
 }
 Point ApplicationManager::GetAvCClipboard()
 {
	 int s = 0;
	 Point p;
	 p.x = 0; p.y = 0;
	 for (int i = 0; i<clipboardcount; i++)
	 {
		 p.x += Clipboard[i]->GetCenter().x;
		 p.y += Clipboard[i]->GetCenter().y;
		 s++;
	 }
	 //p.x=p.x/clipboardcount;
	 //p.y=p.y/clipboardcount;
	 if (s != 0)
	 {
		 p.x = p.x / s;
		 p.y = p.y / s;
	 }
	 return p;
 }

 void ApplicationManager::Copy()
 {
	 CreateClipboard(ReturnSelectednum());
	 for (int i = 0; i<FigCount; i++)
	 {
		 if (FigList[i]->IsSelected())
			 AddinClipboard(FigList[i]->Copy());
	 }
 }
 void ApplicationManager::BringToFront()
 {
	 CFigure* temp = NULL;
	 for (int i = 0; i <= FigCount - 1; i++)
	 {
		 for (int j = 0; j < FigCount - 1; j++)
		 {
			 if (FigList[j]->IsSelected() && !FigList[j + 1]->IsSelected())
			 {
				 temp = FigList[j];
				 FigList[j] = FigList[j + 1];
				 FigList[j + 1] = temp;

			 }
		 }
	 }
 
 }
 void ApplicationManager::SendBack()
 {
	 CFigure* temp = NULL;
	 for (int i = 0; i <= FigCount - 1; i++)
	 {
		 for (int j = 0; j < FigCount - 1; j++)
		 {
			 if (!FigList[j]->IsSelected() && FigList[j + 1]->IsSelected())
			 {
				 temp = FigList[j];
				 FigList[j] = FigList[j + 1];
				 FigList[j + 1] = temp;

			 }
		 }
	 }
 }
 void ApplicationManager::CreatePicknHideList()
 {
	 LeftCount = FigCount;
	 if (LeftCount == 0)return;

	 LeftList = new CFigure*[LeftCount];
	 for (int i = 0; i<FigCount; i++)
	 {
		 LeftList[i] = FigList[i]->Copy();
		 LeftList[i]->SetSelected(false);
	 }
 }
 void ApplicationManager::pushaction(Action* act)
 {
	 if (myactions.size() < 100)
		 myactions.push_back(act);
	 else
	 {
		 myactions.erase(myactions.begin());
		 myactions.push_back(act);
	 }
 }
 void ApplicationManager::CreateLeftList()
 {
	 
	 LeftCount=FigCount;
	 if (LeftCount == 0)return;
	 LeftList = new CFigure*[LeftCount];
	 for (int i = 0; i<FigCount; i++)
	 {
		 LeftList[i] = FigList[i]->Copy();
		 LeftList[i]->SetSelected(false);
		 LeftList[i]->HalveCorners();
	 }
 }
 void ApplicationManager::CreateRightList()
 {
	 RightCount=FigCount ;
	 if (RightCount == 0)return;
	 
	 RightList = new CFigure*[RightCount];
	 for (int i = 0; i<RightCount; i++)
	 {
		 RightList[i] = LeftList[i]->Copy();
		 RightList[i]->SetSelected(false);
		 RightList[i]->MoveRight();
	 }
if(RightCount!=0)	 random_shuffle(&RightList[0], &RightList[FigCount - 1]);

 }
 void ApplicationManager::ScrambleAndFind()
 {
	 Point P;
	 //CTriangle* T;CRectangle*R;CLine* L;CCircle*C;
	 CreateLeftList();
	 CreateRightList();
	 UpdatePlayInterface();
	 pOut->splitscreen();

	
	 int score = 0;
	 int attempt = 0;
	 while (RightCount != 0)
	 {
		 int x = RightCount - 1;
		 LeftList[x]->SetSelected(true);
		 UpdatePlayInterface(x);
		 pOut->splitscreen();
		 pIn->GetPointClicked(P.x, P.y);
		 if (P.y < 100)
		 {
			 if (P.x > 770 & P.x < 1041)
			 {
				 Action *scramble = new ScrambleFind(this);
				 scramble->Execute();
				 return;
			 }
			 if (P.x > 1041 & P.x < 1181)
			 {
				 Action *draw = new GoToDraw(this);
				 draw->Execute();
				 return;
			 }
			 else if (P.x > 1181 & P.x < 1300)
			 {
				 Action *exit = new ExitAction(this);
				 exit->Execute();
				 return;
			 }
		 }
		 int dummy;
		 CFigure* M = GetFigure(P.x, P.y, dummy, -2);
		 if (M == NULL){
			 attempt++;
			 continue;
		 }
		 color one=M->GetDrawClr();
		 color two = M->GetFillClr();
		 color three = LeftList[x]->GetDrawClr();
		 color four = LeftList[x]->GetFillClr();
		 if (M->gettype() == LeftList[x]->gettype() &one==three&two==four & M->GetArea() == LeftList[x]->GetArea())
		 {
			 score++;
			 attempt++;
			 pOut->PrintMessage("Right Attempt!Your score is  " + to_string(score)+"  out of  "+to_string(attempt));
			 M->SetSelected(true);
			 Delete();
			 UpdatePlayInterface();
		 }
		 else
		 {
			 pOut->PrintMessage("Wrong Attempt!");
			 attempt++;
		 }
	 }
	 pOut->PrintMessage(" your final score is" + to_string(score) + " out of " + to_string(attempt));
	 Sleep(1000);

	 
 }
 int ApplicationManager::bubbleSort(shape myshape)
 {
	 CFigure* temp;
	 int Rect = 0; int Line = 0; int Circle = 0; int Tri = 0;

	 if (myshape == RECTANGLE)
	 {
		 for (int i = 0; i <= LeftCount - 1; i++)
		 {
			 for (int j = 0; j < LeftCount - 1; j++)
			 {
				 if (LeftList[j]->gettype() == RECTANGLE && LeftList[j + 1]->gettype() != RECTANGLE)
				 {
					 temp = LeftList[j];
					 LeftList[j] = LeftList[j + 1];
					 LeftList[j + 1] = temp;
					 
				 }
			 }
		 }
		 for (int i = 0; i < LeftCount; i++)
		 {
			 if (LeftList[i]->gettype() == RECTANGLE)Rect++;
		 }
		 return Rect;
	 }
	 
	 if (myshape == CIRCLE)
	 {
		 for (int i = 0; i <= LeftCount-1; i++)
		 {
			 for (int j = 0; j < LeftCount-1; j++)
			 {
				 if (LeftList[j]->gettype() == CIRCLE && LeftList[j + 1]->gettype() != CIRCLE)
				 {
					 temp = LeftList[j];
					 LeftList[j] = LeftList[j + 1];
					 LeftList[j + 1] = temp;
					
				 }
			 }
		 }
		 for (int i = 0; i < LeftCount; i++)
		 {
			 if (LeftList[i]->gettype() == CIRCLE)Circle++;
		 }
		 return Circle;
	 }
	
	 if (myshape == LINE)
	 {
		 for (int i = 0; i <= LeftCount-1; i++)
		 {
			 for (int j = 0; j < LeftCount-1; j++)
			 {
				 if (LeftList[j]->gettype() == LINE && LeftList[j + 1]->gettype() != LINE)
				 {
					 temp = LeftList[j];
					 LeftList[j] = LeftList[j + 1];
					 LeftList[j + 1] = temp;
				 }
			 }
		 }
		 for (int i = 0; i < LeftCount; i++)
		 {
			 if (LeftList[i]->gettype() == LINE)Line++;
		 }
		 return Line;
	 }
	 
	
	 if (myshape == TRIANGLE)
	 {
		 for (int i = 0; i <= LeftCount-1; i++)
		 {
			 for (int j = 0; j < LeftCount-1; j++)
			 {
				 if (LeftList[j]->gettype() == TRIANGLE && LeftList[j + 1]->gettype() != TRIANGLE)
				 {
					 temp = LeftList[j];
					 LeftList[j] = LeftList[j + 1];
					 LeftList[j + 1] = temp;
					
				 }
			 }
		 }
		 for (int i = 0; i < LeftCount; i++)
		 {
			 if (LeftList[i]->gettype() == TRIANGLE)Tri++;
		 }
		 return Tri;
	 }
	
 }



 int ApplicationManager::countColor(color mycolor)
 {
	 int count = 0;
	 for (int i = 0; i < FigCount; i++)
	 {
		 if (FigList[i]->GetFillClr() == mycolor)
			 count++;
	 }
	 return count;
 }

 void ApplicationManager::bubbleSortArea()
 {
	 CFigure *temp;
	 for (int i = 0; i <= LeftCount - 1; i++)
	 {
		 for (int j = 0; j < LeftCount - 1; j++)
		 {
			 if (LeftList[j]->GetArea() > LeftList[j + 1]->GetArea())
			 {
				 temp = LeftList[j + 1];
				 LeftList[j + 1] = LeftList[j];
				 LeftList[j] = temp;

			 }
		 }
	 }
 }
 int ApplicationManager::bubblesortcolor(color c)
 {
	 CFigure* temp;
	 int count = 0;
	 for (int i = 0; i <= LeftCount - 1; i++)
	 {
		 for (int j = 0; j < LeftCount - 1; j++)
		 {
			 if (LeftList[j]->GetFillClr() == c && LeftList[j + 1]->GetFillClr() != c)
			 {
				 temp = LeftList[j];
				 LeftList[j] = LeftList[j + 1];
				 LeftList[j + 1] = temp;

			 }
		 }
	 }
	 for (int i = 0; i < LeftCount; i++)
	 {
		 if (LeftList[i]->GetFillClr() == c)count++;
	 }
	 return count;
 }
 int ApplicationManager::bubblesortboth(color c, shape s)
 {
	 CFigure* temp;
	 int Rect = 0; int Line = 0; int Circle = 0; int Tri = 0;
	 if (s == RECTANGLE)
	 {
		 for (int i = 0; i <= LeftCount - 1; i++)
		 {
			 for (int j = 0; j < LeftCount - 1; j++)
			 {
				 if (LeftList[j]->gettype() == RECTANGLE && LeftList[j]->GetFillClr() == c && LeftList[j + 1]->gettype() != RECTANGLE || LeftList[j + 1]->GetFillClr() != c)
				 {
					 temp = LeftList[j];
					 LeftList[j] = LeftList[j + 1];
					 LeftList[j + 1] = temp;

				 }
			 }
		 }
		 for (int i = 0; i < LeftCount; i++)
		 {
			 if (LeftList[i]->gettype() == RECTANGLE && LeftList[i]->GetFillClr() == c)Rect++;
		 }
		 return Rect;
	 }

	 if (s == CIRCLE)
	 {
		 for (int i = 0; i <= LeftCount - 1; i++)
		 {
			 for (int j = 0; j < LeftCount - 1; j++)
			 {
				 if (LeftList[j]->gettype() == CIRCLE && LeftList[j]->GetFillClr() == c && LeftList[j + 1]->gettype() != CIRCLE || LeftList[j + 1]->GetFillClr() != c)
				 {
					 temp = LeftList[j];
					 LeftList[j] = LeftList[j + 1];
					 LeftList[j + 1] = temp;

				 }
			 }
		 }
		 for (int i = 0; i < LeftCount; i++)
		 {
			 if (LeftList[i]->gettype() == CIRCLE && LeftList[i]->GetFillClr() == c)Circle++;
		 }
		 return Circle;
	 }

	 if (s == LINE)
	 {
		 for (int i = 0; i <= LeftCount - 1; i++)
		 {
			 for (int j = 0; j < LeftCount - 1; j++)
			 {
				 if (LeftList[j]->gettype() == LINE && LeftList[j]->GetFillClr() == c && LeftList[j + 1]->gettype() != LINE || LeftList[j + 1]->GetFillClr() != c)
				 {
					 temp = LeftList[j];
					 LeftList[j] = LeftList[j + 1];
					 LeftList[j + 1] = temp;
				 }
			 }
		 }
		 for (int i = 0; i < LeftCount; i++)
		 {
			 if (LeftList[i]->gettype() == LINE && LeftList[i]->GetFillClr() == c)Line++;
		 }
		 return Line;
	 }


	 if (s == TRIANGLE)
	 {
		 for (int i = 0; i <= LeftCount - 1; i++)
		 {
			 for (int j = 0; j < LeftCount - 1; j++)
			 {
				 if (LeftList[j]->gettype() == TRIANGLE && LeftList[j]->GetFillClr() == c && LeftList[j + 1]->gettype() != TRIANGLE || LeftList[j + 1]->GetFillClr() != c)
				 {
					 temp = LeftList[j];
					 LeftList[j] = LeftList[j + 1];
					 LeftList[j + 1] = temp;

				 }
			 }
		 }
		 for (int i = 0; i < LeftCount; i++)
		 {
			 if (LeftList[i]->gettype() == TRIANGLE && LeftList[i]->GetFillClr() == c)Tri++;
		 }
		 return Tri;
	 }


	

 }
int ApplicationManager::getclipboardcount()const
 {
	 return clipboardcount;
 }
void ApplicationManager::printinfo()const
{
	int rect, circle, triangle, line,select,unselect;
	rect = 0;
	circle = 0;
	triangle = 0;
	line = 0;
	select = 0;
	unselect = 0;

	
	for (int i = 0; FigCount; i++)
	{
		shape myshape = FigList[i]->gettype();
		if (myshape == TRIANGLE)triangle++;
		else if (myshape == RECTANGLE)rect++;
		else if (myshape == LINE)line++;
		else if (myshape == CIRCLE)circle++;
		if (FigList[i]->IsSelected())select++;
		else unselect++;
	}
	pOut->PrintMessage("There Are  " + to_string(rect) + " Rectangles and  " + to_string(triangle) + " Triangles and" + to_string(line) + " lines and " + to_string(circle) + " circles and " + to_string(select) + " Selected figures out of " + to_string(FigCount));
}
