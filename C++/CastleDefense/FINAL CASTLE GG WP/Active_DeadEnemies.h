#pragma once
#include "Structs_Utility.h"
#include "KillingFunctions_Priority.h"
#include "Active_DeadEnemies.h"


void InsertActiveEnemiesInRegionX(List *&inactive, List *&ActiveX, PList *&ActiveShX, int time, REGION Region, float c1, float c2, float c3);

void DeadEnemies(List *&ActiveX, PList *&ActiveShX, int &DeadAtTimeStepX, int &TotalDeadX,List* dead);
void deletelist(List* deleted);