
#ifndef CCIRCLE_H
#define CCIRCLE_H
#include"Figures\CFigure.h"

class CCircle :public CFigure
{
private:
	Point center;
	int radius;
public:

	CCircle(Point, int, GfxInfo FigureGfxInfo);
	CCircle();
	virtual bool Draw(Output* pOut, int k = -1) const;
	virtual CFigure* Copy()const;
	virtual void Move(int, int);
	virtual void Rotate(int);
	virtual void Zoom(float);
	virtual bool isPointInside(int x, int y) const;
	virtual void Resize(float R_factor);
	virtual Point GetCenter();
	virtual void Save(ofstream &OutFile);
	virtual void HalveCorners();
	virtual void MoveRight();
	virtual void Load(ifstream &Infile);
	virtual float GetArea();

};















#endif