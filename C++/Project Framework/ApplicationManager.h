#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include<vector>
#include "Actions\Action.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure** Clipboard;
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	int zoomed;
	int clipboardcount;
	int maxClipboardCount;
	int Selectednum;
	bool state;
	bool is_fill_color_chosen;
	CFigure** RightList;
	CFigure**LeftList;
	int LeftCount;
	int RightCount;
	std::vector<Action*> myactions;
	std::vector<Action*>aux;
	bool flag;
	
public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction(int y =-1, int x=-1) const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	CFigure** getFigurePtrPtr();
	bool getstate()const;
	void setstate(bool);
	void pushaction(Action*);
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y,int &j,int i=-1) const; //Search for a figure given a point inside the figure
	CFigure *GetSelection(int&i)const;
	CFigure*const* returnlist()const;
	void zoom(float);
	void clearselection();
	bool canrotate(int);
	bool canresize(int);
	bool canmove(int,int);
	void setfillchosen(bool);
	void clearlist(int i=1);
	void Load(ifstream &infile);
	void undo();
	void redo();
	void removefromend();
	void deletefromend(int);
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface(int i=-1,int k=-1) const;	//Redraws all the drawing window	
	void UpdatePlayInterface(int i=-1)const;
	int getfigcount(int i=1)  ;
	 CFigure* getFigurePtr(int i);
	 int getzoomed();
	 //dina's functions
	 Point GetAvCClipboard();
	 void CreateClipboard(int);
	 int ReturnSelectednum();
	 CFigure* ReturnClipboardfig(int i); // returns item of cilpboard (ptr)
	 bool AddinClipboard(CFigure * c); //adds a nw figure in clipboard
	 void Delete();
	 void Copy();
	 bool Paste(int, int);
	 Point GetAverageCenter(int i=1);
	 void BringToFront();	
	 void SendBack();
	 void CreateLeftList();
	 void CreateRightList();
	 void ScrambleAndFind();
	 void CreatePicknHideList();
	 int bubbleSort(shape);
	 int countColor(color);
	 void bubbleSortArea();
	 int bubblesortcolor(color c);
	 int bubblesortboth(color c, shape s);
	 void movebyid(int, int, int);
	 int getclipboardcount()const;
	 void printinfo()const;
	 bool canpaste(int,int);
};

#endif