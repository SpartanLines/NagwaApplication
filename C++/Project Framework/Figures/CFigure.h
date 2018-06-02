#ifndef CFIGURE_H
#define CFIGURE_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <time.h>
#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	static int counter;
	float resized;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual bool Draw(Output* pOut,int k=-1) const  = 0 ;		//Draw the figure
	virtual void Rotate(int) = 0;
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);
	void ChngBorderWdth(float);	//changes the figure's filling color
	color GetFillClr()const;
	color GetDrawClr()const;
	virtual void Zoom(float)=0;
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	virtual void Move(int, int) = 0;
	virtual CFigure* Copy()const=0;
	virtual bool isPointInside(int x,int y) const = 0;
	virtual Point GetCenter() = 0;
	
	
	virtual void Resize(float) = 0;	//Resize the figure
			//Move the figure
	virtual void Save(ofstream &OutFile)=0;
	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	virtual void HalveCorners() = 0;
	virtual int GetID()const;
	virtual void SetID(int);
	virtual void Setresized(int);
	virtual bool IsId(int)const;
	virtual void MoveRight() = 0;
	virtual shape gettype();
	virtual float GetArea() = 0;
};

#endif