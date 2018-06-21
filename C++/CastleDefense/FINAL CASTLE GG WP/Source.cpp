#include <iostream>
using namespace std;

#include "Structs_Utility.h"
#include "LoadFile_Lists.h"
#include "KillingFunctions_Priority.h"
#include "Region.h"
#include "Active_DeadEnemies.h"



int main()
{
	SetWindow();	//adjust game window settings

	castle ct; // define a castle 
	ct.Xstrt = CastleXStrt;
	ct.Ystrt = CastleYStrt;
	ct.W = CastleWidth;
	ct.L = CastleLength;

	List *inactive;
	List *ActiveA, *ActiveB, *ActiveC, *ActiveD;
	List *Dead;
	PList *ActiveShA, *ActiveShB, *ActiveShC, *ActiveShD;

	ifstream Input_File;
	Dead = InitializeList();
	inactive = InitializeList();
	InitializeAll(ActiveA, ActiveShA);
	InitializeAll(ActiveB, ActiveShB);
	InitializeAll(ActiveC, ActiveShC);
	InitializeAll(ActiveD, ActiveShD);
	ofstream ofile("outputfile.txt");
	float c1, c2, c3;

	LoadData(Input_File, inactive, c1, c2, c3, ct);


	region RegionA, RegionB, RegionC, RegionD;
	initializeregions(RegionA, RegionB, RegionC, RegionD, ct);
	holdq(RegionA, ActiveA, ActiveShA);
	holdq(RegionB, ActiveB, ActiveShB);
	holdq(RegionC, ActiveC, ActiveShC);
	holdq(RegionD, ActiveD, ActiveShD);
	int time = 0;
	int TotalDeadA = 0; int TotalDeadB = 0; int TotalDeadC = 0; int TotalDeadD = 0;
	int DeadAtTimeStepA = 0; int DeadAtTimeStepB = 0; int DeadAtTimeStepC = 0; int  DeadAtTimeStepD = 0;
	int TimeStepKillA = 0; int TimeStepKillB = 0; int TimeStepKillC = 0; int TimeStepKillD = 0;

	DrawCastle(ct, time);

	cout << "Total current eneimes  A = " << ActiveA->count + ActiveShA->count << "\t B= " << ActiveB->count + ActiveShB->count;
	cout << "\t C= " << ActiveC->count + ActiveShC->count << "\t D= " << ActiveD->count + ActiveShD->count << endl;

	cout << "Last time step kill    A = " << TimeStepKillA << "\t B= " << TimeStepKillB;
	cout << "\t C= " << TimeStepKillC << "\t D= " << TimeStepKillD << endl;

	cout << "Total killed by        A = " << TotalDeadA << "\t B= " << TotalDeadB;
	cout << "\t C= " << TotalDeadC << "\t D= " << TotalDeadD << endl;

	cout << "Unpaved distance      A = " << RegionA.Unpaved_Distance << "\t B= " << RegionB.Unpaved_Distance;
	cout << "\t C= " << RegionC.Unpaved_Distance << "\t D= " << RegionD.Unpaved_Distance << endl;

	cout << "1: Interactive Mode, 2:Step by Step Mode, 3: Silent Mode. " << endl << "Select the Mode: ";
	int Mode;
	cin >> Mode;

	int sumOfTowersHealth = ct.towers[0].Health + ct.towers[1].Health + ct.towers[2].Health + ct.towers[3].Health;
	int totalNumberOfEnemies = inactive->count;


	while (Mode != 3 && sumOfTowersHealth > 0 && totalNumberOfEnemies > 0)
	{
		time++;
		InsertActiveEnemiesInRegionX(inactive, ActiveA, ActiveShA, time, A_REG, c1, c2, c3);
		InsertActiveEnemiesInRegionX(inactive, ActiveB, ActiveShB, time, B_REG, c1, c2, c3);
		InsertActiveEnemiesInRegionX(inactive, ActiveC, ActiveShC, time, C_REG, c1, c2, c3);
		InsertActiveEnemiesInRegionX(inactive, ActiveD, ActiveShD, time, D_REG, c1, c2, c3);

		int TotalActiveA = ActiveA->count + ActiveShA->count;
		int TotalActiveB = ActiveB->count + ActiveShB->count;
		int TotalActiveC = ActiveC->count + ActiveShC->count;
		int TotalActiveD = ActiveD->count + ActiveShD->count;

		int Ecnt;	//enemy count
		Ecnt = TotalActiveA + TotalActiveB + TotalActiveC + TotalActiveD;

		Enemy **EnemyArray = new Enemy*[Ecnt]; /*= new Enemy[Ecnt];*///??
		int index = 0;

		CreateEnemiesArray(EnemyArray, ActiveA, ActiveShA, index);
		CreateEnemiesArray(EnemyArray, ActiveB, ActiveShB, index);
		CreateEnemiesArray(EnemyArray, ActiveC, ActiveShC, index);
		CreateEnemiesArray(EnemyArray, ActiveD, ActiveShD, index);

		//Now time to Draw
		//[1],[2],[3] Clear the screen, Draw the castle, Draw the regions
		DrawCastle(ct, time);

		//[4] Draw enemies
		DrawEnemies(EnemyArray, Ecnt);
		/*DrawEnemies(enemies, Ecnt);*/

		//fight
		if (RegionA.towers.Health != 0)
			SimulateEachRegion(ActiveA, ActiveShA, 'A', time, RegionA, inactive);
		if (RegionB.towers.Health != 0)
			SimulateEachRegion(ActiveB, ActiveShB, 'B', time, RegionB, inactive);
		if (RegionC.towers.Health != 0)
			SimulateEachRegion(ActiveC, ActiveShC, 'C', time, RegionC, inactive);
		if (RegionD.towers.Health != 0)
			SimulateEachRegion(ActiveD, ActiveShD, 'D', time, RegionD, inactive);


		ct.towers[0] = RegionA.towers;
		ct.towers[1] = RegionB.towers;
		ct.towers[2] = RegionC.towers;
		ct.towers[3] = RegionD.towers;

		if (DeadAtTimeStepA != 0) TimeStepKillA = time;
		if (DeadAtTimeStepB != 0) TimeStepKillB = time;
		if (DeadAtTimeStepC != 0) TimeStepKillC = time;
		if (DeadAtTimeStepD != 0) TimeStepKillD = time;


		cout << "Total current eneimes  A = " << ActiveA->count + ActiveShA->count << "\t B= " << ActiveB->count + ActiveShB->count;
		cout << "\t C= " << ActiveC->count + ActiveShC->count << "\t D= " << ActiveD->count + ActiveShD->count << endl;

		cout << "Last time step kill    A = " << TimeStepKillA << "\t B= " << TimeStepKillB;
		cout << "\t C= " << TimeStepKillC << "\t D= " << TimeStepKillD << endl;

		cout << "Total killed by        A = " << TotalDeadA << "\t B= " << TotalDeadB;
		cout << "\t C= " << TotalDeadC << "\t D= " << TotalDeadD << endl;

		cout << "Unpaved distance      A = " << RegionA.Unpaved_Distance << "\t B= " << RegionB.Unpaved_Distance;
		cout << "\t C= " << RegionC.Unpaved_Distance << "\t D= " << RegionD.Unpaved_Distance << endl;

		DeadEnemies(ActiveA, ActiveShA, DeadAtTimeStepA, TotalDeadA, Dead);
		DeadEnemies(ActiveB, ActiveShB, DeadAtTimeStepB, TotalDeadB, Dead);
		DeadEnemies(ActiveC, ActiveShC, DeadAtTimeStepC, TotalDeadC, Dead);
		DeadEnemies(ActiveD, ActiveShD, DeadAtTimeStepD, TotalDeadD, Dead);
		bubbsort(Dead);
		writeoutputfile(ofile, Dead, time);
		deletelist(Dead);


		sumOfTowersHealth = ct.towers[0].Health + ct.towers[1].Health + ct.towers[2].Health + ct.towers[3].Health;
		totalNumberOfEnemies -= (DeadAtTimeStepA + DeadAtTimeStepB + DeadAtTimeStepC + DeadAtTimeStepD);

		if (time == 1)
			cin.get(); //3ashan mesh beteshta3'al ta7t f time step=1 bas

		if (Mode == 1)
			Sleep(1000);
		else
		{
			cin.get();
		}

		//rotation
		/*if (ct.towers[0].Health <= 0);
		if (ct.towers[1].Health <= 0);
		if (ct.towers[2].Health <= 0);
		if (ct.towers[3].Health <= 0);*/
		delete[]EnemyArray;


	}

	if (Mode == 1 || Mode == 2)
	{
		if (DeadAtTimeStepA != 0) TimeStepKillA = time;
		if (DeadAtTimeStepB != 0) TimeStepKillB = time;
		if (DeadAtTimeStepC != 0) TimeStepKillC = time;
		if (DeadAtTimeStepD != 0) TimeStepKillD = time;

		DrawCastle(ct, time);
		cout << "Total current eneimes  A = " << ActiveA->count + ActiveShA->count << "\t B= " << ActiveB->count + ActiveShB->count;
		cout << "\t C= " << ActiveC->count + ActiveShC->count << "\t D= " << ActiveD->count + ActiveShD->count << endl;

		cout << "Last time step kill    A = " << TimeStepKillA << "\t B= " << TimeStepKillB;
		cout << "\t C= " << TimeStepKillC << "\t D= " << TimeStepKillD << endl;

		cout << "Total killed by        A = " << TotalDeadA << "\t B= " << TotalDeadB;
		cout << "\t C= " << TotalDeadC << "\t D= " << TotalDeadD << endl;

		cout << "Unpaved distance      A = " << RegionA.Unpaved_Distance << "\t B= " << RegionB.Unpaved_Distance;
		cout << "\t C= " << RegionC.Unpaved_Distance << "\t D= " << RegionD.Unpaved_Distance << endl;
	}
	bool win = isgame(RegionA, RegionB, RegionC, RegionD, inactive);
	if (win) ofile << " GAME IS WON";
	else ofile << "GAME IS LOST";
	cin.get();
	return 0;
}