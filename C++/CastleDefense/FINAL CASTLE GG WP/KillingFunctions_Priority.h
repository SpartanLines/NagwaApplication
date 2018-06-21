#pragma once

#include "Structs_Utility.h"
#include "LoadFile_Lists.h"

void EnemyHitsTower(Enemy &enemy, region &region, int time);

void TowerHitsEnemy(region &region, PList*& pq, List*&q,int currenttime);

void TransportEnemiez(region *regionDead, region *regionAlive,List* inactive);

bool MoveEnemiez(region* regionX,List* inactive);

void InsertPriority(PList* &pactive, float c1, float c2, float c3);

pNode* SortedMergePriority(PList* a, PList* b);

void FrontBackSplitPriority(pNode* NewList, PList* FrontRef, PList* backRef);

void MergeSortPriority(PList* myList);

void SimulateEachRegion(List *&ActiveX, PList *&ActiveShX, char Region, int time, region &RegionX,List* inactive);

