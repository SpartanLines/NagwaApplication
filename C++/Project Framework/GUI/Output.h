#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
	int barney;
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() ;	//creates Draw mode toolbar & menu , not const because it changes the int barney
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void CreatePICKNHIDEToolBar() const;
	void CreateZoomedToolbar()const;
	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void CreateColorsWheel()const;
	void CreateBorderwidthChoice()const;
	void CreateResizeChoice()const;
	void CreateRotateChoice()const;
	void CreateZoomChoice()const;
	void splitscreen()const;
	void CreatePlay2()const;
	void CreatePlay3()const;
	// -- Figures Drawing functions
	bool DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo,int k, bool selected = false) const;  //Draw a rectangle
	bool DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo,int k, bool selected = false) const;
	bool DrawCircle(Point P1, int radius, GfxInfo CircleGfxInfo,int k, bool selected = false) const;
	bool DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo,int k, bool selected = false) const;//Draw a rectangle

	bool DrawCheck(Point P1, Point P2) const; // for rectangles and lines. 
	bool DrawCheck(Point P1, Point P2, Point P3) const; // for triangles (3 pts).  
	bool DrawCheck(Point P1,  int radius) const; //  for circles.

	///Make similar functions for drawing all other figures.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width


	~Output();
};

#endif