#pragma once
#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "Figures\CFigure.h"

class CTriangle : public CFigure
{
private:
    Point Corner1, Corner2, Corner3;
public:
    CTriangle(Point , Point, Point, GfxInfo FigureGfxInfo);
	CTriangle();
	virtual bool Draw(Output* pOut, int k = -1) const;
    Point getcorner1() const;
    Point getcorner2() const;
    Point getcorner3() const;
    //virtual void Rotate() = 0;	//Rotate the figure
	//virtual void Resize() = 0;	//Resize the figure
	//virtual void Move() = 0;		//Move the figure
	virtual bool isPointInside(int x,int y)const;
	virtual CFigure* Copy()const;
	virtual void Move(int, int);
	virtual void Zoom(float);
	virtual void Resize(float);
	virtual void Save(ofstream &OutFile) ;
	virtual void Load(ifstream &Infile) ;	//Load the figure parameters to the file
	void virtual Rotate(int);
	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	virtual Point GetCenter();
	virtual void HalveCorners();
	virtual void MoveRight();
	
	virtual float GetArea();
	
};

#endif
