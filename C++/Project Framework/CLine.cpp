
#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
    Corner1 = P1;
    Corner2 = P2;
}

bool CLine:: Draw(Output *pOut,int k) const
{
	return pOut->DrawLine(Corner1,Corner2,FigGfxInfo,k,Selected);
}

Point CLine::getcorner1() const
{
    return Corner1;
}

Point CLine::getcorner2() const
{
    return Corner2;
}
bool CLine::isPointInside(int x,int y) const{

	float slope = ((float)(Corner2.y - Corner1.y) / (float)(Corner2.x - Corner1.x));
	float intsection = Corner1.y - Corner1.x*slope;
	if ((y <(slope*x + intsection + (float)FigGfxInfo.BorderWdth / 2)) & (y>(slope*x + intsection - (float)FigGfxInfo.BorderWdth / 2))&x >= min(Corner1.x, Corner2.x)&x <= max(Corner1.x, Corner2.x)&y >= min(Corner1.y, Corner2.y)&y <= max(Corner1.y, Corner2.y))
	{
		return true;
	}
	return false;
}
void CLine::Load(ifstream &infile)
{
	Point one, two;
	int x, y, t, fill;
	
	int id, border;
	infile >> id >> one.x >> one.y >> two.x >> two.y >> border >> x >> y >> t;
	
	
		Corner1 = one;
		Corner2 = two;

		FigGfxInfo.DrawClr.ucRed = x;
		FigGfxInfo.DrawClr.ucGreen = y;
		FigGfxInfo.DrawClr.ucBlue = t;
		FigGfxInfo.isFilled = false;

		SetID(id);
		FigGfxInfo.BorderWdth = border;
		
	
	

}
void CLine::Move(int x,int y)
{
	float slope = ((float)(Corner2.y - Corner1.y) / (float)(Corner2.x - Corner1.x));
   Point mid;
  
   mid.x = (Corner1.x + Corner2.x)/2;
   mid.y = (Corner1.y + Corner2.y)/2;
   Point newMid;
   newMid.x = x;   newMid.y=y;
   float midDist =  sqrt(pow(mid.x-Corner1.x,2)+pow(mid.y-Corner1.y,2));
   float theta = atan(slope);
   if (slope<0)
   {
   //    theta = 180 - theta;
     Corner1.x = newMid.x - midDist*cos(theta);
     Corner1.y = newMid.y - midDist*sin(theta);
     Corner2.x = newMid.x + midDist*cos(theta);
     Corner2.y = newMid.y + midDist*sin(theta);
   }
   else
   {
	   Corner1.x = newMid.x - midDist*cos(theta);
       Corner1.y = newMid.y - midDist*sin(theta);
       Corner2.x = newMid.x + midDist*cos(theta);
       Corner2.y = newMid.y + midDist*sin(theta);
    }
}


void CLine::Rotate(int angle)
	{
		Point COM;

		COM.x = (Corner1.x + Corner2.x) / 2;
		COM.y = (Corner1.y + Corner2.y) / 2;
		Point newCorner1, newCorner2;

		newCorner1.x = Corner1.x - COM.x;
		newCorner1.y = Corner1.y - COM.y;

		newCorner2.x = Corner2.x - COM.x;
		newCorner2.y = Corner2.y - COM.y;



		if (angle == 180)
		{
			newCorner1.x *= -1;
			newCorner1.y *= -1;
			newCorner2.x *= -1;
			newCorner2.y *= -1;

			Corner1.y = newCorner1.y + COM.x;
			Corner1.x = newCorner1.x + COM.y;

			Corner2.y = newCorner2.y + COM.x;
			Corner2.x = newCorner2.x + COM.y;

		}

		if (angle == 90)
		{
			newCorner1.y *= -1;
			newCorner2.y *= -1;

			Corner1.x = newCorner1.y + COM.x;
			Corner1.y = newCorner1.x + COM.y;

			Corner2.x = newCorner2.y + COM.x;
			Corner2.y = newCorner2.x + COM.y;


		}

		if (angle == 270)
		{
			newCorner1.x *= -1;
			newCorner2.x *= -1;

			Corner1.x = newCorner1.y + COM.x;
			Corner1.y = newCorner1.x + COM.y;

			Corner2.x = newCorner2.y + COM.x;
			Corner2.y = newCorner2.x + COM.y;


		}



	}

void CLine::Zoom(float x)
{
	
	if (x<1 & sqrt(pow((Corner1.x - Corner2.x), 2) + pow((Corner1.y - Corner2.y), 2)) < 20)return;
	Corner1.x -= (1300 / 2);
	Corner1.y -= (800/ 2);
	Corner2.x -= (1300 / 2);
	Corner2.y -= (800 / 2);
	Corner1.x *= x;
	Corner1.y *= x;
	Corner2.x *= x;
	Corner2.y *= x;
	Corner1.x += (1300 / 2);
	Corner1.y += (800 / 2);
	Corner2.x += (1300 / 2);
	Corner2.y += (800 / 2);
	if (x > 0)
	{
		FigGfxInfo.BorderWdth = floor(FigGfxInfo.BorderWdth*x);
		resized++;
	}
	if (x < 0)
	{
		FigGfxInfo.BorderWdth = FigGfxInfo.BorderWdth*x;
		resized--;
	}
	if (FigGfxInfo.BorderWdth < 1)FigGfxInfo.BorderWdth = 1;
}
CFigure* CLine::Copy() const
{
	CFigure* copied_figure = new CLine(Corner1, Corner2, FigGfxInfo);
	return copied_figure;


}
Point CLine::GetCenter()
{
	Point c;
	c.x = (Corner1.x + Corner2.x) / 2;
	c.y = (Corner1.y + Corner2.y) / 2;
	return c;

}
void CLine::Resize(float RF)
{
	Point Center;
	double slope = (float)(Corner1.y - Corner2.y) / (float)(Corner1.x - Corner2.x);
	double theta = atan(slope);
	double dist = ((sqrt((pow(Corner1.x - Corner1.x, 2)) + pow(Corner1.y - Corner2.y, 2))) * RF);
	double olddist = ((sqrt((pow(Corner1.x - Corner1.x, 2)) + pow(Corner1.y - Corner2.y, 2))));
	double midDist = dist / 2;


	Center.x = ((Corner1.x + Corner2.x) / 2);
	Center.y = ((Corner1.y + Corner2.y) / 2);

	/*Corner1.x = Center.x + ((dist / 2)*cos(theta));
	Corner1.y = Center.y + ((dist / 2)*sin(theta));
	Corner2.x = Center.x + ((dist / 2)*cos(theta));
	Corner2.y = Center.y + ((dist / 2)*sin(theta));*/
	Corner1.y -= Center.y;
	Corner2.y -= Center.y;
	Corner1.x -= Center.x;
	Corner2.x -= Center.x;
	Corner1.y *= RF;
	Corner2.y *= RF;
	Corner1.x *= RF;
	Corner2.x *= RF;
	Corner1.y += Center.y;
	Corner2.y += Center.y;
	Corner1.x += Center.x;
	Corner2.x += Center.x;
	resized *= RF;

	/* Corner1.x = Center.x - midDist*sin(theta);
	Corner1.y = Center.y - midDist*cos(theta);
	Corner2.x = Center.x + midDist*sin(theta);
	Corner2.y = Center.y + midDist*cos(theta);*/
}

void CLine::Save(ofstream&outfile)
{
	if (resized == 1)
	{
	
			outfile << "Line  " << ID << "   "  << Corner1.x << " " << Corner1.y << " " <<  Corner2.x << " " << Corner2.y << " " << FigGfxInfo.BorderWdth << " " << to_string(FigGfxInfo.DrawClr.ucRed) << " " << to_string(FigGfxInfo.DrawClr.ucGreen) << " " << to_string(FigGfxInfo.DrawClr.ucBlue) << endl;
	}
	else
	{
		CFigure* temp = Copy();
		for (int i = 0; i < abs(resized); i++)
		{
			if (resized > 0)
				temp->Zoom(1 / sqrt(2));
			else
				temp->Zoom(sqrt(2));
		}
		temp->SetID(ID);
		temp->Setresized(1);
		temp->Save(outfile);
		delete temp;
		return;
	}
}
CLine::CLine()
{}

void CLine::HalveCorners()
{
	Corner1.x = ceil(Corner1.x / 2);
	Corner2.x = ceil(Corner2.x / 2);
	Corner1.y = ceil(Corner1.y / 2)+200;
	Corner2.y = ceil(Corner2.y / 2)+200;
}
void CLine::MoveRight()
{

	int xgen = 2*(max(Corner1.x, Corner2.x) - GetCenter().x);
	int ygen = 2*(max(Corner1.y, Corner2.y) - GetCenter().y);

	int x = rand() % (650 - xgen);
	int y = rand() % (500 - ygen);
	Move(650 + xgen/2+x, y+200+ygen/2);

}

float CLine::GetArea()
{
	return 0.0;
}