
#include "CTriangle.h"
float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
    Corner1 = P1;
    Corner2 = P2;
    Corner3 = P3;
}

bool CTriangle:: Draw(Output *pOut,int k) const
{
    return pOut->DrawTriangle(Corner1, Corner2, Corner3, FigGfxInfo,k, Selected);
}

Point CTriangle::getcorner1() const
{
    return Corner1;
}

Point CTriangle::getcorner2() const
{
    return Corner2;
}

Point CTriangle:: getcorner3() const
{
    return Corner3;

}
bool CTriangle::isPointInside(int x,int y)const
{
	float Area = area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	float a1, a2, a3;
	a1 = area(x, y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	a2 = area(Corner1.x, Corner1.y, x, y, Corner3.x, Corner3.y);
	a3 = area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, x, y);
	if ((a1 + a2 + a3 )== Area)return true;
	else return false;
}
void CTriangle::Move(int x, int y)

{

   Point COM;
   COM.x = (Corner1.x + Corner2.x + Corner3.x)/3;
   COM.y = (Corner1.y + Corner2.y + Corner3.y)/3;
   Point dist1, dist2, dist3;
   dist1.x = COM.x - Corner1.x;
   dist1.y = COM.y - Corner1.y;
   dist2.x = COM.x - Corner2.x;
   dist2.y = COM.y - Corner2.y;
   dist3.x = COM.x - Corner3.x;
   dist3.y = COM.y - Corner3.y;

   COM.x = x;   COM.y = y;
   Corner1.x = COM.x - dist1.x;
   Corner1.y = COM.y - dist1.y;
   Corner2.x = COM.x - dist2.x;
   Corner2.y = COM.y - dist2.y;
   Corner3.x = COM.x - dist3.x ;
   Corner3.y = COM.y - dist3.y;

}
CFigure* CTriangle::Copy() const
{
	CFigure* copied_figure = new CTriangle(Corner1, Corner2, Corner3, FigGfxInfo);
	return copied_figure;
}
void CTriangle::Rotate(int angle)
{
    Point COM;

    COM.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
    COM.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
    Point newCorner1, newCorner2, newCorner3;
   
    newCorner1.x = Corner1.x - COM.x;
    newCorner1.y = Corner1.y - COM.y;

    newCorner2.x = Corner2.x - COM.x;
    newCorner2.y = Corner2.y - COM.y;

    newCorner3.x = Corner3.x - COM.x;
    newCorner3.y = Corner3.y - COM.y;

    if (angle == 180)
    {
        newCorner1.x  *=  - 1;
        newCorner1.y  *=  - 1;
        newCorner2.x  *=  - 1;
        newCorner2.y  *=  - 1;
        newCorner3.x  *=  - 1;
        newCorner3.y  *=  - 1;
		Corner1.y = newCorner1.y + COM.y;
		Corner1.x = newCorner1.x + COM.x;

		Corner2.y = newCorner2.y + COM.y;
		Corner2.x = newCorner2.x + COM.x;

		Corner3.x = newCorner3.x + COM.x;
		Corner3.y= newCorner3.y + COM.y;
    }
    
    if (angle == 90)
    {
        newCorner1.y  *=  - 1;
        newCorner2.y  *=  - 1;
        newCorner3.y  *=  - 1;
		Corner1.x = newCorner1.y + COM.x;
		Corner1.y = newCorner1.x + COM.y;

		Corner2.x = newCorner2.y + COM.x;
		Corner2.y = newCorner2.x + COM.y;

		Corner3.x = newCorner3.y + COM.x;
		Corner3.y = newCorner3.x + COM.y;
    }

	if (angle == 270)
	{
		
		newCorner1.x *= -1;
		newCorner2.x *= -1;
		newCorner3.x *= -1;
		Corner1.x = newCorner1.y + COM.x;
		Corner1.y = newCorner1.x + COM.y;

		Corner2.x = newCorner2.y + COM.x;
		Corner2.y = newCorner2.x + COM.y;

		Corner3.x = newCorner3.y + COM.x;
		Corner3.y = newCorner3.x + COM.y;
	}
	

   
}

void CTriangle::Zoom(float x)
{
	if (area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y) < 200 &x<1)return;
	Corner1.x -= (1300 / 2);
	Corner1.y -= (800 / 2);
	Corner2.x -= (1300 / 2);
	Corner2.y -= (800 / 2);
	Corner3.x -= (1300 / 2);
	Corner3.y -= (800 / 2);
	Corner1.x *= x;
	Corner1.y *= x;
	Corner2.x *= x;
	Corner2.y *= x;
	Corner3.x *= x;
	Corner3.y *= x;
	Corner1.x += (1300 / 2);
	Corner1.y += (800 / 2);
	Corner2.x += (1300 / 2);
	Corner2.y += (800 / 2);
	Corner3.x += (1300 / 2);
	Corner3.y += (800 / 2);
	
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

void CTriangle::Resize(float RF)
{
	Point Center;
	Center.x = ((Corner1.x + Corner2.x + Corner3.x) / 3);
	Center.y = ((Corner1.y + Corner2.y + Corner3.y) / 3);
	if (area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y) < 20)return;
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

	Point Vector3;
	Vector3.x = Corner3.x - Center.x;
	Vector3.y = Corner3.y - Center.y;

	Corner3.x = Center.x + (Vector3.x*RF);
	Corner3.y = Center.y + (Vector3.y*RF);
	

}
Point CTriangle::GetCenter()
{
	Point Center;
	Center.x = ((Corner1.x + Corner2.x + Corner3.x) / 3);
	Center.y = ((Corner1.y + Corner2.y + Corner3.y) / 3);

	return Center;
}
void CTriangle::Save(ofstream&outfile)
{
	if (resized == 1)
	{
		if (FigGfxInfo.isFilled)
			outfile << "Tria   " << ID << "   " << Corner1.x << "  " << Corner1.y <<  "  " << Corner2.x << "  " << Corner2.y << "  "<< Corner3.x << "  " << Corner3.y << "   " << FigGfxInfo.BorderWdth << "  " <<to_string( FigGfxInfo.DrawClr.ucRed) << " " << to_string(FigGfxInfo.DrawClr.ucGreen) << " " <<to_string(FigGfxInfo.DrawClr.ucBlue) << "  " <<to_string( FigGfxInfo.FillClr.ucRed )<< " " <<to_string( FigGfxInfo.FillClr.ucGreen) << " " <<to_string( FigGfxInfo.FillClr.ucBlue) << endl;
		else
			outfile << "Tria   " << ID << "   " << Corner1.x << "  " << Corner1.y <<  "  " << Corner2.x << "  " << Corner2.y << "  " << Corner3.x << "  " << Corner3.y << "   " << FigGfxInfo.BorderWdth << "  " << to_string(FigGfxInfo.DrawClr.ucRed) << " " << to_string(FigGfxInfo.DrawClr.ucGreen) << " " << to_string(FigGfxInfo.DrawClr.ucBlue) << "  NO_FILL" << endl;
	}
	else
	{
		CFigure* temp = Copy();
		for (int i = 0; i < abs(resized); i++)
		{
			if (resized > 0)
				temp->Zoom(1 / sqrt(2));
			else
				temp->Zoom( sqrt(2));
		}
		temp->SetID(ID);
		temp->Setresized(1);
		temp->Save(outfile);
		delete temp;
		return;
	}
}
CTriangle::CTriangle()
{}
void CTriangle::Load(ifstream &infile)
{
	Point one, two, three;
	int x,y,t, fill;
	string z;
	int id, border;
	infile >> id >> one.x >> one.y >> two.x >> two.y >> three.x >> three.y >> border >> x >> y >> t ;
	int infi = infile.tellg();
	infile.seekg(infi+2);
	int check = infile.peek();
	;
	if (infile.peek()==78)
	{
		Corner1 = one;
		Corner2 = two;
		Corner3 = three;
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
		Corner3 = three;
		FigGfxInfo.DrawClr.ucRed = x;
		FigGfxInfo.DrawClr.ucGreen = y;
		FigGfxInfo.DrawClr.ucBlue = t;
		SetID(id);
		FigGfxInfo.BorderWdth = border;
		infile >> one.x >> one.y >> two.x;
		FigGfxInfo.FillClr.ucRed = one.x;
		FigGfxInfo.FillClr.ucGreen= one.y;
		FigGfxInfo.FillClr.ucBlue = two.x;
		
	}
}
void CTriangle::HalveCorners()
{
	Corner1.x = ceil(Corner1.x / 2);
	Corner2.x = ceil(Corner2.x / 2);
	Corner1.y = ceil(Corner1.y / 2)+200;
	Corner2.y = ceil(Corner2.y / 2)+200;
	Corner3.x = ceil(Corner3.x / 2);
	Corner3.y = ceil(Corner3.y / 2)+200;
}
void CTriangle::MoveRight()
{
	/* 	Point Center;
	Center.x=((Corner1.x+Corner2.x+Corner3.x) / 3);
	Center.y=((Corner1.y+Corner2.y+Corner3.y) / 3);


	int Vector1 = Corner1.x-Center.x;
	int Vector2 = Corner2.x-Center.x;
	int Vector3 = Corner3.x-Center.x;
	int maxx=0;
	if(Vector1>Vector2)
	maxx=Vector1;
	else
	maxx=Vector2;
	if(Vector3>maxx)
	maxx=Vector3;
	int V1 = Corner1.y-Center.x;
	int V2 = Corner2.y-Center.x;
	int V3 = Corner3.y-Center.x;
	int maxy=0;
	if(V1>V2)
	maxx=V1;
	else
	maxx=V2;
	if(V3>maxx)
	maxx=V3;

	int x=rand()%(650-maxx);
	int y=rand()%(650-maxy);
	Move(650+x+maxx,y);*/
	int xgen = (max(max(Corner1.x, Corner2.x), Corner3.x) - GetCenter().x) + (GetCenter().x - min(min(Corner1.x, Corner2.x), Corner3.x));
	int ygen = (max(Corner1.y, Corner2.y, Corner3.y) - GetCenter().y) + (GetCenter().y - min(Corner1.y, Corner2.y, Corner3.y));

	int x = rand() % (650 - 2*xgen);
	int y = rand() % (500 - 2*ygen);
	Move(x + 650+xgen/2, y+100+ygen/2);
}

float CTriangle ::GetArea()
{
	float x1 = Corner1.x;
	float x2 = Corner2.x;
	float x3 = Corner3.x;
	float y1 = Corner1.y;
	float y2 = Corner2.y;
	float y3 = Corner3.y;

	return abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}