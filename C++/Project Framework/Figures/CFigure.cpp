#include "CFigure.h"

int CFigure::counter = 1;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	ID = counter;
	
	counter++;
	resized = 0;
}
CFigure::CFigure(){
	resized = 1;
	Selected = false;
	ID = counter;
	counter++;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }
void CFigure::ChngBorderWdth(float t)
{
	FigGfxInfo.BorderWdth = t;

}

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
void CFigure::SetID(int z)
{
	if (z>0)
	ID = z;
}
void CFigure::Setresized(int z)
{
	if (z>0)
		resized = z;
}
color CFigure::GetFillClr() const
{
	return FigGfxInfo.FillClr;
}
color CFigure::GetDrawClr()const
{
	return FigGfxInfo.DrawClr;
}
int CFigure::GetID() const
{
	return ID;
}
shape CFigure::gettype()
{
	return FigGfxInfo.myshape;
}
bool CFigure::IsId(int sent)const
{
	if (ID == sent)return true;
	else return false;
}