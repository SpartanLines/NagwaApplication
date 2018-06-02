#pragma once
#ifndef CLINE_H
#define CLINE_H

#include "Figures\CFigure.h"

class CLine : public CFigure
{
private:
    Point Corner1, Corner2;
public:
    CLine(Point ,Point, GfxInfo FigureGfxInfo);
	CLine();
	virtual bool Draw(Output* pOut, int k = -1) const;
	virtual bool isPointInside(int x,int y)const;
    Point getcorner1() const;
    Point getcorner2() const;
    //virtual void Rotate() = 0;	//Rotate the figure
	//virtual void Resize() = 0;	//Resize the figure
	//virtual void Move() = 0;		//Move the figure
		virtual void Move(int x,int y);
		virtual void Save(ofstream &OutFile);
		virtual CFigure* Copy()const;
		virtual void Rotate(int);
		virtual void Zoom(float);
		virtual void Resize(float);
	virtual	Point GetCenter();
	virtual void Load(ifstream &Infile);
	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	virtual void HalveCorners();
	virtual void MoveRight();
	
	virtual float GetArea();
};

#endif

