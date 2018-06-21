#pragma once
#include<iostream>

using namespace std;

#include <windows.h>

//The four regions: A, B, C , and D
enum REGION
{
	A_REG,
	B_REG,
	C_REG,
	D_REG
};

//Enemy types: Paver, Fighter, Shielded Fighter, Healer and Winged Fighter.
enum Etype
{
	Paver,
	Fighter,
	Shielded,
	warlock,
	ninja,
	
};

struct Enemy
{
	int ID; //sequence
	REGION Region; //enum?
	int Distance;
	float Health;
	Etype Type; //enum?
	int Time_left_shoot;
	int Arrival_Time;
	int First_Hit_Time;
	int Death_Time;
	int Fire_Power;
	int Reload_Period;
	int speed;
	//int k; //k=1 for paver and fighter, k=2 for shielded
};

struct Tower
{
	int TW; //Tower width
	int TL; //Tower Height
	float Health;

	int Fire_Power;
	int N;
};

struct castle
{
	//starting x,y
	int Xstrt;
	int Ystrt;
	int W;	//width
	int L;  //Height
	Tower towers[4];	//Castle has 4 towers
};

struct Node
{
	Enemy Enemy;
	Node *next;
};


struct pNode
{
	Enemy Enemy;
	float priority;
	pNode *next;
};

struct PList
{
	pNode *Front;
	pNode *Rear;
	int count;
};

struct List
{
	Node *Front;
	Node *Rear;
	int count;
};

struct region
{
	Tower towers;
	List *nsoldiers;
	PList *shielded;
	region *Next;
	int Unpaved_Distance;
	REGION regionnum;
};

//constants
#define CmdWidth		150
#define CmdHeight		50
#define CastleWidth		30
#define CastleLength	20
#define CastleXStrt		(CmdWidth/2-(CastleWidth/2))
#define CastleYStrt		(CmdHeight/2-(CastleLength/2))
#define TowerWidth      7
#define TowerLength     3

#define EnemyShape		219  //ASCII code of enemy char shape 

//Functions Prototype

/*A function to set the position of cursor on the screen*/
void gotoxy(int x, int y);

/*A function to set the command window lenght and height for the game specification*/
void SetWindow();

/*A function to color the cmd text*/
void color(int thecolor);

/*A function to partition the castle into regions (A,B,C,D)*/
void DrawRegions(const castle & C);

/*A function to draw the castle and the towers*/
void DrawCastle(const castle & C, int SimulationTime);

/*A function to draw a single enemy using its distance from the castle*/
void DrawEnemy(const Enemy& E, int Ypos = 0);

/*A function to draw a list of enemies exist in all regions and ensure there is no overflow in the drawing*/
void DrawEnemies(Enemy* enemies[], int size);

/*Student use this function to print his/her message*/
void PrintMsg(char*msg);

void CreateEnemiesArray(Enemy *EnemyArray[], List *ActiveX, PList *ActiveShX, int &index);