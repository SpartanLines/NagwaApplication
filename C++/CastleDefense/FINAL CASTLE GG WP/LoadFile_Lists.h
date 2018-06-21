#pragma once

#include "Structs_Utility.h"
#include <fstream>

void LoadData(ifstream &input_file, List*inactive, float &c1, float &c2, float &c3, castle &ct);

void InputFilesGenerator();

List * InitializeList();

PList * InitializePList();

void InitializeAll(List *&ActiveX, PList *&ActiveShX);

bool InsertAtEnd(List *ListX, Node *Temp_Enemy);

bool InsertAtTheEndPList(PList* pq, Enemy enemy);

Node * DeleteFromBeg(List*ListX);

pNode * DeleteFromBegShielded(PList*ListX);

Node * DeleteNodeFromMid(List*ListX, Node *&delNode);

pNode * DeleteNodeFromMidShielded(PList*ListX, pNode *&delNode);

void ActiveEnemies(List*&inactive, List*&ActiveX, PList*&ActiveSh, int time, REGION region);

void bubbsort(List*dead);

void writeoutputfile(ofstream & ofile, List* dead, int timedeath);

bool isgame(region a, region b, region c, region d, List* inactives);