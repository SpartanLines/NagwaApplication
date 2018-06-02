#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	CRectangle();
	virtual bool Draw(Output* pOut, int k = -1) const;
	virtual bool isPointInside(int x,int y) const;
	virtual CFigure* Copy()const;
	virtual void Move(int, int);
	virtual void Rotate(int);
	virtual void Zoom(float);
	virtual void Save(ofstream &OutFile);
	virtual void Resize(float);
	virtual Point GetCenter();
	virtual void HalveCorners();
	virtual void MoveRight();
	virtual void Load(ifstream &Infile);
	virtual float GetArea();
};

#endif