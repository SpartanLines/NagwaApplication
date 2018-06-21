#include "Active_DeadEnemies.h"

//To get the active enemies in each region, insert the prioritty for shielded enemies and sort them accordind to it
void InsertActiveEnemiesInRegionX(List *&inactive, List *&ActiveX, PList *&ActiveShX, int time, REGION Region, float c1, float c2, float c3)
{
	ActiveEnemies(inactive, ActiveX, ActiveShX, time, Region);
	InsertPriority(ActiveShX, c1, c2, c3);
	MergeSortPriority(ActiveShX);
	pNode *current = ActiveShX->Front;
	while (current != NULL && current->next != NULL)
	{
		current = current->next;
	}
	ActiveShX->Rear = current;
}

//should remove the dead enemies from el list of Active and ActiveSh and insert it in Dead list 
void DeadEnemies(List *&ActiveX, PList *&ActiveShX, int &DeadAtTimeStepX, int &TotalDeadX  ,List* dead)
{
	DeadAtTimeStepX = 0;
	Node *Current;
	Current = ActiveX->Front;
	pNode *Current2;
	Current2 = ActiveShX->Front;
	if (Current == NULL&& Current2==NULL)return;
	while (Current != NULL)
	{
		if (Current->Enemy.Health <= 0)
		{
			Node *DeadEnemy = DeleteNodeFromMid(ActiveX, Current); //this function should return a node of one dead enemy
			InsertAtEnd(dead, DeadEnemy);
			DeadAtTimeStepX++;
			TotalDeadX++;
			/*	Current = Current->next;*/ //no need to do this step as it happens in DeleteNodeFromMid Function
		}
		else
		{
			Current = Current->next;
		}
			

	}

	
	while (Current2 != NULL)
	{
		if (Current2->Enemy.Health <= 0)
		{
			pNode * DeadEnemySh = DeleteNodeFromMidShielded(ActiveShX, Current2); // because the function makes pnode and the dead list is of type node
			Node* insertdead = new Node;
			insertdead->Enemy = DeadEnemySh->Enemy;
			InsertAtEnd(dead, insertdead);
			DeadAtTimeStepX++;
			TotalDeadX++;
		}
		else
		{
			Current2 = Current2->next;
		}
			
	}
}



int countlist(Node* head)
{
	Node* ptr = head;
	int count=0;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return count;
}

void deletelist(List* deleted)
{
	Node* delnode = deleted->Front;

	while (deleted->Front != NULL)
	{
		delnode = deleted->Front;
		deleted->Front = deleted->Front->next;
		delete delnode;
	}
	
	deleted->Front = NULL;
	deleted->Rear = NULL;
	deleted->count=0;
	return;

}
