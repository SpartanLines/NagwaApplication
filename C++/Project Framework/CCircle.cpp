#include"CCircle.h"

#define PI 3.14159265
CCircle::CCircle(Point P1,int r, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;
	radius = r;

}

bool CCircle::Draw(Output* pOut,int k) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	return pOut->DrawCircle(center,radius, FigGfxInfo,k, Selected);
}


void CCircle::Move(int x,int y)
{
	/*if((y-120<radius)||(650-y<radius)||(1300-x<radius)||(x<radius))return;*/
	center.x=x;
	center.y=y;
}
CFigure* CCircle::Copy() const
{
	CFigure* copied_figure = new CCircle(center, radius, FigGfxInfo);
	return copied_figure;
}
void CCircle::Rotate(int x)
{
	return;
}
void CCircle::Load(ifstream &infile)
{
	Point one;
	int x, y,two, t, fill;
	string z;
	int id, border;
	infile >> id >> one.x >> one.y >> two >> border >> x >> y >> t;
	int infi = infile.tellg();
	infile.seekg(infi + 2);
	int check = infile.peek();
	;
	if (infile.peek() == 78)
	{
		center = one;
		radius = two;

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
		center = one;
		radius = two;

		FigGfxInfo.DrawClr.ucRed = x;
		FigGfxInfo.DrawClr.ucGreen = y;
		FigGfxInfo.DrawClr.ucBlue = t;
		SetID(id);
		FigGfxInfo.BorderWdth = border;
		infile >> one.x >> one.y >> two;
		FigGfxInfo.FillClr.ucRed = one.x;
		FigGfxInfo.FillClr.ucGreen = one.y;
		FigGfxInfo.FillClr.ucBlue = two;

	}
}
void CCircle::Zoom(float x)
{
	if (GetArea() < 50 & x < 1)return;
	center.x -= (1300 / 2);
	center.y -= (800/ 2);
	
	center.x *=x;
	center.y *= x;
	if (pow(radius*x,2)>20)
	radius *= x;
	center.x += (1300 / 2);
	center.y += (800 / 2);
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
	if (FigGfxInfo.BorderWdth < 1) FigGfxInfo.BorderWdth = 1;
} 
void CCircle::Resize(float R_factor)
{
	double Area;
	Area =PI*(pow(radius, 2));
	radius = sqrt((Area / 3.14)*R_factor);
	resized *= R_factor;
}
Point CCircle::GetCenter()
{
	return center;
}
bool CCircle::isPointInside(int x, int y)const
{
	if ((abs(center.x - x) < radius + FigGfxInfo.BorderWdth / 2)&(abs(center.y - y) < radius + FigGfxInfo.BorderWdth / 2)&pow(center.x,2)+pow(center.y,2)>pow(radius,2))return true;
	else return false;
}
void CCircle::Save(ofstream&outfile)
{
	
	
	if (resized == 1)
	{
		if (FigGfxInfo.isFilled)
			outfile << "Circ " << ID << "   " << center.x << " " << center.y << " " << radius << "  "<< FigGfxInfo.BorderWdth << " " << to_string(FigGfxInfo.DrawClr.ucRed) << " " << to_string(FigGfxInfo.DrawClr.ucGreen) << " " << to_string(FigGfxInfo.DrawClr.ucBlue) << "  " << to_string(FigGfxInfo.FillClr.ucRed) << " " << to_string(FigGfxInfo.FillClr.ucGreen) << " " << to_string(FigGfxInfo.FillClr.ucBlue) << endl;
		else
			outfile << "Circ  " << ID << "   " << center.x << " " << center.y << " "<<radius << "  "<< FigGfxInfo.BorderWdth << " " << to_string(FigGfxInfo.DrawClr.ucRed) << " " << to_string(FigGfxInfo.DrawClr.ucGreen) << " " << to_string(FigGfxInfo.DrawClr.ucBlue) << "  NO_FILL" << endl;
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
CCircle::CCircle(){}
void CCircle::HalveCorners()
{
	center.x = ceil(center.x /= 2);
	center.y = ceil(center.y /= 2)+200;
	radius = ceil(radius /= 2);
}
void CCircle::MoveRight()
{
	int x = rand() % (650 - 3*radius);

	int y = rand() % (500 - 3*radius);

	Move(650 + x + radius, y + radius+200);

}

float CCircle::GetArea()
{
	return (22 / 7)*(radius*radius);
}