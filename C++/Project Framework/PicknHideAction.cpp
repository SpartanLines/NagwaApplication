//#include "PicknHideAction.h"
//#include<algorithm>
//#include"ScrambleFind.h"
//#include"GoToDraw.h"
//#include"ExitAction.h"
//PicknHideAction::PicknHideAction(ApplicationManager *pApp) : Action(pApp)
//{
//	mode = 0;
//}
//
//void PicknHideAction::ReadActionParameters()
//{
//	int x, y;
//	Output* pOut = pManager->GetOutput();
//	Input* pIn = pManager->GetInput();
//	pManager->CreatePicknHideList();
//	pOut->CreatePlay2();
//	pOut->PrintMessage("Choose the mode by which you want to play!");
//	do{ pIn->GetPointClicked(x, y); } while (y > UI.ToolBarHeight / 2);
//	
//
//
//}
//void PicknHideAction::Execute()
//{
//	return;
//}
//void PicknHideAction::Execute()
//{
//
//	ReadActionParameters();
//	
//	
//	if (x > 219 & x < 342)mode = 1;
//	else if (x>342 & x < 472) mode = 2;
//	else if (x>472 & x < 623) mode = 3;
//	else if (x>632 & x < 770) mode = 4;
//	else if (x > 770 & x < 1041)
//	{
//		Action *scramble = new ScrambleFind(pManager);
//		scramble->Execute();
//		return;
//	}
//	else if (x > 1041 & x < 1181)
//	{
//		Action *draw = new GoToDraw(pManager);
//		draw->Execute();
//		return;
//	}
//	else if (x > 1181 & x < 1300)
//	{
//		Action *exit = new ExitAction(pManager);
//		exit->Execute();
//		return;
//	}
//	
//	
//	
//	
//	
//	int x, y, i, valid, invalid;
//	CFigure *firstpick = pManager->GetFigure(x, y, i);
//	CFigure *copied = firstpick->Copy();
//	// *******************Figs type************************
//	for (int j = 0; j < /*count*/; j++)   // ezay han-count el fig
//	{
//		pManager->GetInput()->GetPointClicked(x, y);
//		CFigure *picked = pManager->GetFigure(x, y, i);
//
//		if (picked->gettype() == copied->gettype())
//			valid++;
//		/* delete el figs*/
//		else invalid++;
//	}
//
//
//	// *******************Figs type + Fill Clr***************
//	for (int j = 0; j </*count*/; j++)
//	{
//		pManager->GetInput()->GetPointClicked(x, y);
//		CFigure *picked = pManager->GetFigure(x, y, i);
//		if (picked->gettype() == copied->gettype() && picked->GetFillClr() == copied->GetFillClr())
//			valid++;
//		/* delete el figs */
//		else invalid++;
//	}
//
//
//
//	// ********************** Fill Clr **************************
//	for (int j = 0; j </*count*/; j++)
//	{
//		pManager->GetInput()->GetPointClicked(x, y);
//		CFigure *picked = pManager->GetFigure(x, y, i);
//		if (copied->GetFillClr() == picked->GetFillClr())
//			valid++;
//		/* delete el figs */
//		else invalid++;
//	}
//	// ******************* Area **************************** 
//
//
//	for (int j = 0; j </*count*/; j++)
//	{
//		pManager->GetInput()->GetPointClicked(x, y);
//		CFigure *picked = pManager->GetFigure(x, y, i);
//		if (copied->GetArea() > picked->GetArea()) // get area dina hateb3atha delwa2ty..
//			valid++;
//		/* delete el figs */
//		else invalid++;
//	}
//
//	pManager->GetOutput()->PrintMessage("Valid picks: ");
//
//	pManager->GetOutput()->PrintMessage("Invalid picks: ");
//}



#include "PicknHideAction.h"
#include<algorithm>
#include"ScrambleFind.h"
#include"GoToDraw.h"
#include"ExitAction.h"
PicknHideAction::PicknHideAction(ApplicationManager *pApp) : Action(pApp)
{
	mode = 0;
}

void PicknHideAction::ReadActionParameters()
{
	
	x = y = 0;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pManager->CreatePicknHideList();
	pOut->CreatePlay2();
	pOut->PrintMessage("Choose the mode by which you want to play!");
	do{ pIn->GetPointClicked(x, y);
	pManager->GetOutput()->PrintMessage("Choose A suitable Action!");
	} while (y > UI.ToolBarHeight / 2);
}



void PicknHideAction::Execute()
{

	ReadActionParameters();
	pManager->UpdatePlayInterface();
	int i, k;
	int count;
	int valid = 0, invalid = 0;


	if (x > 219 & x < 342)mode = 1;
	else if (x>342 & x < 472) mode = 2;
	else if (x>472 & x < 623) mode = 3;
	else if (x>632 & x < 770) mode = 4;
	else if (x > 770 & x < 1041)
	{
	CASE :	Action *scramble = new ScrambleFind(pManager);
		scramble->Execute();
		return;
	}
	else if (x > 1041 & x < 1181)
	{
	WASE:	Action *draw = new GoToDraw(pManager);
		draw->Execute();
		return;
	}
	else if (x > 1181 & x < 1300)
	{
	FASE:	Action *exit = new ExitAction(pManager);
		exit->Execute();
		return;
	}

	/*pManager->GetInput()->GetPointClicked(x, y);
	CFigure *picked = pManager->GetFigure(x, y, k, -3);
	
	if (picked != NULL){
		CFigure *copied = picked->Copy();
	}*/
	if (mode == 1)
	{
		// Bubble sorting the list according to shape.
		
		while (pManager->getfigcount(2) != 0)
		{
			pManager->GetInput()->GetPointClicked(x, y);
			pManager->GetOutput()->PrintMessage("Pick By Figure Type! choose a figure to pick by its type");
			if (y < UI.ToolBarHeight / 2)// if he chose an aciton whilst playing
			{
				if (x > 1041 & x < 1181) goto WASE;// wase is line 167
				else if (x > 770 & x < 1041) goto CASE;//case is line 161
				else if (x > 1181 & x < 1300)goto FASE;//fase is line 173
				else if (x > 0 % x < 219)
				{
					Action *pick = new PicknHideAction(pManager);
					pick->Execute();
					return;
				}
			}
			CFigure *picked = pManager->GetFigure(x, y, k, -3);

			if (picked != NULL)
			{
				CFigure *copied = picked->Copy();
				picked->SetSelected(true);
				
				if (picked->gettype() == RECTANGLE)
				{
					count = pManager->bubbleSort(RECTANGLE);
					pManager->GetOutput()->PrintMessage("Choose All Rectangles!");
				
				}
					if (picked->gettype() == LINE)
					{
						count = pManager->bubbleSort(LINE);
						pManager->GetOutput()->PrintMessage("Choose All Lines!");

					}
				if (picked->gettype() == CIRCLE)
				{
					count = pManager->bubbleSort(CIRCLE);
					pManager->GetOutput()->PrintMessage("Choose All Circles!");

				}
				if (picked->gettype() == TRIANGLE)
				{
					count = pManager->bubbleSort(TRIANGLE);
					pManager->GetOutput()->PrintMessage("Choose All Triangles!");

				}
				pManager->Delete();
				pManager->UpdatePlayInterface();
				count--;
				
				while (count>0)
				{
					pManager->GetInput()->GetPointClicked(x, y);
					if (y < UI.ToolBarHeight / 2)
					{
						if (x > 1041 & x < 1181) goto WASE;
						else if (x > 770 & x < 1041) goto CASE;
						else if (x > 1181 & x < 1300)goto FASE;
						else if (x > 0 % x < 219)
						{
							Action *pick = new PicknHideAction(pManager);
							pick->Execute();
							return;
						}
					}

					CFigure* picked2 = pManager->GetFigure(x, y, k, -3);
					if (k <= pManager->getfigcount(2) - 1 && k >= pManager->getfigcount(2) - count) // get fig count takes 2 as parameter to return The left list count insteaf of FigCount
					{
						valid++;
						picked2->SetSelected(true);
						pManager->Delete();
						pManager->UpdatePlayInterface();
						count--;
						
					}
					else invalid++;
				}
				
			}
			else
			{
				pManager->GetOutput()->PrintMessage("Failed to choose a figure! choose again");
			}
		}
	}

	else if (mode == 2)
	{
		// Bubble sorting the list according to color.

		while (pManager->getfigcount(2) != 0)
		{
			pManager->GetInput()->GetPointClicked(x, y);
			pManager->GetOutput()->PrintMessage("Pick By Color! choose a figure to pick by its color");
			if (y < UI.ToolBarHeight / 2)// if he chose an aciton whilst playing
			{
				if (x > 1041 & x < 1181) goto WASE;// wase is line 167
				else if (x > 770 & x < 1041) goto CASE;//case is line 161
				else if (x > 1181 & x < 1300)goto FASE;//fase is line 173
				else if (x > 0 % x < 219)
				{
					Action *pick = new PicknHideAction(pManager);
					pick->Execute();
					return;
				}
			}
			CFigure *picked = pManager->GetFigure(x, y, k, -3);
			color C = picked->GetFillClr();

			if (picked != NULL)
			{
				CFigure *copied = picked->Copy();
				picked->SetSelected(true);

				//if (picked->GetFillClr() == C)
				{
					count = pManager->bubblesortcolor(C);
					pManager->GetOutput()->PrintMessage("Choose All Figures with color");

				}
				/*if (picked->gettype() == LINE)
				{
				count = pManager->bubbleSort(LINE);
				pManager->GetOutput()->PrintMessage("Choose All Lines!");

				}
				if (picked->gettype() == CIRCLE)
				{
				count = pManager->bubbleSort(CIRCLE);
				pManager->GetOutput()->PrintMessage("Choose All Circles!");

				}
				if (picked->gettype() == TRIANGLE)
				{
				count = pManager->bubbleSort(TRIANGLE);
				pManager->GetOutput()->PrintMessage("Choose All Triangles!");

				}
				*/
				pManager->Delete();
				pManager->UpdatePlayInterface();
				count--;

				while (count > 0)
				{
					pManager->GetInput()->GetPointClicked(x, y);
					if (y < UI.ToolBarHeight / 2)
					{
						if (x > 1041 & x < 1181) goto WASE;
						else if (x > 770 & x < 1041) goto CASE;
						else if (x > 1181 & x < 1300)goto FASE;
						else if (x > 0 % x < 219)
						{
							Action *pick = new PicknHideAction(pManager);
							pick->Execute();
							return;
						}
					}

					CFigure* picked2 = pManager->GetFigure(x, y, k, -3);
					if (k <= pManager->getfigcount(2) - 1 && k >= pManager->getfigcount(2) - count) // get fig count takes 2 as parameter to return The left list count insteaf of FigCount
					{
						valid++;
						picked2->SetSelected(true);
						pManager->Delete();
						pManager->UpdatePlayInterface();
						count--;

					}
					else invalid++;
				}

			}
			else
			{
				pManager->GetOutput()->PrintMessage("Failed to choose a figure! choose again");
			}
		}
	}
	else if (mode == 3)
	{
		// Bubble sorting the list according to shape.
		int count1 = 0;
		int count2 = 0;
		int count = 0;
		while (pManager->getfigcount(2) != 0)
		{
			pManager->GetInput()->GetPointClicked(x, y);
			pManager->GetOutput()->PrintMessage("Pick By Figure Type, and by color! choose a figure ");
			if (y < UI.ToolBarHeight / 2)// if he chose an aciton whilst playing
			{
				if (x > 1041 & x < 1181) goto WASE;// wase is line 167
				else if (x > 770 & x < 1041) goto CASE;//case is line 161
				else if (x > 1181 & x < 1300)goto FASE;//fase is line 173
				else if (x > 0 % x < 219)
				{
					Action *pick = new PicknHideAction(pManager);
					pick->Execute();
					return;
				}
			}
			CFigure *picked = pManager->GetFigure(x, y, k, -3);
			color C = picked->GetFillClr();
			if (picked != NULL)
			{
				CFigure *copied = picked->Copy();
				picked->SetSelected(true);


				if (picked->gettype() == RECTANGLE)
				{
					count2 = pManager->bubblesortcolor(C);
					//count = pManager->bubblesortboth(C , RECTANGLE);
					count1 = pManager->bubbleSort(RECTANGLE);

					pManager->GetOutput()->PrintMessage("Choose All Rectangles of same color!");

				}
				if (picked->gettype() == LINE)
				{
					//count2 = pManager->bubblesortcolor(C);
					count = pManager->bubblesortboth(C, LINE);
					//count1 = pManager->bubbleSort(LINE);
					pManager->GetOutput()->PrintMessage("Choose All Lines eith same color!");

				}
				if (picked->gettype() == CIRCLE)
				{
					//count2 = pManager->bubblesortcolor(C);
					count = pManager->bubblesortboth(C, CIRCLE);
					//count1 = pManager->bubbleSort(CIRCLE);
					pManager->GetOutput()->PrintMessage("Choose All Circles with same color!");

				}
				if (picked->gettype() == TRIANGLE)
				{
					count = pManager->bubblesortboth(C, TRIANGLE);
					//count2 = pManager->bubblesortcolor(C);
					//count1 = pManager->bubbleSort(TRIANGLE);


					pManager->GetOutput()->PrintMessage("Choose All Triangles with same color!");

				}
				/*if (count1 < count2)
				count = count1;
				else
				count = count2;
				*/

				pManager->Delete();
				pManager->UpdatePlayInterface();
				count--;

				while (count > 0)
				{
					pManager->GetInput()->GetPointClicked(x, y);
					if (y < UI.ToolBarHeight / 2)
					{
						if (x > 1041 & x < 1181) goto WASE;
						else if (x > 770 & x < 1041) goto CASE;
						else if (x > 1181 & x < 1300)goto FASE;
						else if (x > 0 % x < 219)
						{
							Action *pick = new PicknHideAction(pManager);
							pick->Execute();
							return;
						}
					}

					CFigure* picked2 = pManager->GetFigure(x, y, k, -3);
					if (k <= pManager->getfigcount(2) - 1 && k >= pManager->getfigcount(2) - count) // get fig count takes 2 as parameter to return The left list count insteaf of FigCount
					{
						valid++;
						picked2->SetSelected(true);
						pManager->Delete();
						pManager->UpdatePlayInterface();
						count--;

					}
					else invalid++;
				}

			}
			else
			{
				pManager->GetOutput()->PrintMessage("Failed to choose a figure! choose again");
			}
		}
	}
	if (mode == 4)
	{
		// Bubble sorting the list according to shape.
		 pManager->bubbleSortArea();
		while (pManager->getfigcount(2) != 0)
		{
			pManager->GetInput()->GetPointClicked(x, y);
			//pManager->GetOutput()->PrintMessage("Pick By Figure Type! choose a figure to pick by its type");
			if (y < UI.ToolBarHeight / 2)// if he chose an aciton whilst playing
			{
				if (x > 1041 & x < 1181) goto WASE;// wase is line 167
				else if (x > 770 & x < 1041) goto CASE;//case is line 161
				else if (x > 1181 & x < 1300)goto FASE;//fase is line 173
				else if (x > 0 % x < 219)
				{
					Action *pick = new PicknHideAction(pManager);
					pick->Execute();
					return;
				}
			}


			int c = pManager->getfigcount(2);
			CFigure* picked2 = pManager->GetFigure(x, y, k, -3);
			if (k == c - 1) // get fig count takes 2 as parameter to return The left list count instead of FigCount
			{
				valid++;
				picked2->SetSelected(true);
				pManager->Delete();
				pManager->UpdatePlayInterface();
				
				


			}
			else invalid++;
		}

	}





	pManager->GetOutput()->PrintMessage("Valid picks:" + to_string(valid) + "and Invalid picks: " + to_string(invalid));
	Sleep(100);

	}







