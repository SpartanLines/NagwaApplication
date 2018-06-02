#include "CRectangle.h"



CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

bool CRectangle::Draw(Output* pOut,int k) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	return pOut->DrawRect(Corner1, Corner2, FigGfxInfo,k, Selected);
}

bool CRectangle:: isPointInside(int x,int y) const
{
	if ((Corner1.y>y&Corner2.y<y&Corner1.x>x&Corner2.x<x) | (Corner2.y>y&Corner1.y<y&Corner1.x>x&Corner2.x<x) | (Corner1.y<y&Corner2.y>y&Corner1.x<x&Corner2.x>x) | (Corner1.y>y&Corner2.y<y&Corner1.x<x&Corner2.x>x))
	{
		return true;
	}
	else return false;
}
 CFigure* CRectangle::Copy()const
 {
	 CFigure* copied_figure=new CRectangle(Corner1,Corner2,FigGfxInfo);
	 return copied_figure;


 }
 
 void CRectangle::Move(int x, int y)
 {
   
	
	//int length = abs(Corner2.x - Corner1.x);
	//int width = abs(Corner2.y - Corner1.y);
	//if (y > 650 || y+width > 650||x>1300||x+length>1300)
	//{
	//return;
	//}
	//        // checks for the location of all x-coord. wrt to left most of UI.
	//this->Corner1.x = x;
	//this->Corner1.y = y;
	//this->Corner2.x = x + length;
	//this->Corner2.y = y + width;
	 int centerx = (Corner1.x + Corner2.x) / 2;
	 int centery = (Corner1.y + Corner2.y) / 2;
	 Corner1.x = (Corner1.x - centerx )+ x;
	 Corner2.x = (Corner2.x - centerx )+ x;
	 Corner1.y = (Corner1.y- centery )+ y;
	 Corner2.y = (Corner2.y - centery) + y;

 }
	
 
 
 
 void CRectangle::Rotate(int angle)
 {
	 Point COM;

	 COM.x = (Corner1.x + Corner2.x ) / 2;
	 COM.y = (Corner1.y + Corner2.y ) / 2;
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
		 
		 Corner1.y = newCorner1.y + COM.y;
		 Corner1.x = newCorner1.x + COM.x;

		 Corner2.y = newCorner2.y + COM.y;
		 Corner2.x = newCorner2.x + COM.x;

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
 CRectangle::CRectangle()
 {

 }
 void CRectangle::Zoom(float x)
 {
	 if (GetArea() < 50 & x < 1)return;
	 Corner1.x -= (1300 / 2);
	 Corner1.y -= (800 / 2);
	 Corner2.x -= (1300 / 2);
	 Corner2.y -= (800/ 2);
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
 void CRectangle::Resize(float RF)
 {
	 int L = abs(Corner1.x - Corner2.x);
	 int W = abs(Corner1.y - Corner2.y);
	 Point Center;
	 Center.x = ((Corner1.x + Corner2.x) / 2);
	 Center.y = ((Corner1.y + Corner2.y) / 2);
	/* double ratio = L / W;
	 double Ar = L*W*RF;
	 L = sqrt(Ar / ratio);
	 W = ratio*L;
	 Corner1.x = (Center.x + (0.5*L));
	 Corner1.y = (Center.y - (0.5*W));
	 Corner2.x = (Center.x - (0.5*L));
	 Corner2.y = (Center.y + (0.5*W));*/
	 Point Vector1;
	 Vector1.x = Corner1.x - Center.x;
	 Vector1.y = Corner1.y - Center.y;

	 Corner1.x = Center.x + (Vector1.x*RF);
	 Corner1.y = Center.y + (Vector1.y*RF);

	 Point Vector2;
	 Vector2.x = Corner2.x - Center.x;
	 Vector2.y = Corner2.y - Center.y;

	 Corner2.x = Center.x + (Vector2.x*RF);
	 Corner2.y = Center.y + (Vector2.y*RF);

	

 }
 Point CRectangle::GetCenter()
 {
	 Point Center;
	 Center.x = ((Corner1.x + Corner2.x) / 2);
	 Center.y = ((Corner1.y + Corner2.y) / 2);
	 return Center;
 }
 void CRectangle::Save(ofstream&outfile)
 {
	 if (resized == 1)
	 {
		 if (FigGfxInfo.isFilled)
			 outfile << "Rect  " << ID << "   " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << FigGfxInfo.BorderWdth << " " << to_string(FigGfxInfo.DrawClr.ucRed) << " " << to_string(FigGfxInfo.DrawClr.ucGreen) << " " << to_string(FigGfxInfo.DrawClr.ucBlue) << "  " << to_string(FigGfxInfo.FillClr.ucRed) << " " << to_string(FigGfxInfo.FillClr.ucGreen) << " " << to_string(FigGfxInfo.FillClr.ucBlue) << endl;
		 else
			 outfile << "Rect  " << ID << "   " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << FigGfxInfo.BorderWdth << " " << to_string(FigGfxInfo.DrawClr.ucRed) << " " << to_string(FigGfxInfo.DrawClr.ucGreen) << " " << to_string(FigGfxInfo.DrawClr.ucBlue) << "  NO_FILL" << endl;
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
 void CRectangle::Load(ifstream &infile)
 {
	 Point one, two ;
 int x, y, t, fill;
 string z;
 int id, border;
 infile >> id >> one.x >> one.y >> two.x >> two.y >> border >> x >> y >> t;
 int infi = infile.tellg();
 infile.seekg(infi + 2);
 int check = infile.peek();
 ;
 if (infile.peek() == 78)
 {
	 Corner1 = one;
	 Corner2 = two;
	 
	 FigGfxInfo.DrawClr.ucRed = x;
	 FigGfxInfo.DrawClr.ucGreen = y;
	 FigGfxInfo.DrawClr.ucBlue = t;
	 FigGfxInfo.isFilled = false;

	 SetID(id);
	 FigGfxInfo.BorderWdth = border;
	 infile >> z;
 }
 else
 {
	 Corner1 = one;
	 Corner2 = two;
	 
	 FigGfxInfo.DrawClr.ucRed = x;
	 FigGfxInfo.DrawClr.ucGreen = y;
	 FigGfxInfo.DrawClr.ucBlue = t;
	 SetID(id);
	 FigGfxInfo.BorderWdth = border;
	 infile >> one.x >> one.y >> two.x;
	 FigGfxInfo.FillClr.ucRed = one.x;
	 FigGfxInfo.FillClr.ucGreen = one.y;
	 FigGfxInfo.FillClr.ucBlue = two.x;

 }
}
 void CRectangle::HalveCorners()
 {
	 Corner1.x = ceil(Corner1.x / 2);
	 Corner2.x = ceil(Corner2.x / 2);
	 Corner1.y = ceil(Corner1.y / 2)+200;
	 Corner2.y = ceil(Corner2.y / 2)+200;
 }
 void CRectangle::MoveRight()
 {
	 /* float L=abs(Corner1.x-Corner2.x);
	 float W=abs(Corner1.y-Corner2.y);
	 L=L/2;
	 W=W/2;
	 float x=rand()%(650-L);
	 float y=rand()%(650-W);
	 Move(650+x+L,y);*/
	 int xgen = 2 * (max(Corner1.x, Corner2.x) - GetCenter().x);/* + (GetCenter().x - min(Corner1.x, Corner2.x));*/
	 int ygen =2* (max(Corner1.y, Corner2.y) - GetCenter().y);/* + (GetCenter().y - min(Corner1.y, Corner2.y));*/
	 int x = rand() % (650 - xgen);
	 int y = rand() % (550 - ygen);
	 Move((650 +(xgen/2)+ x), (y+200+(ygen/2)));
 }
 
 float CRectangle::GetArea()
 {
	 float L = abs(Corner1.x - Corner2.x);
	 float W = abs(Corner1.y - Corner2.y);
	 return L*W;
 }