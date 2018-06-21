#include "KillingFunctions_Priority.h"
void move(Enemy & enemy, int unpaveddistance)
{
	enemy.Distance = enemy.Distance - enemy.speed;
	if (enemy.Distance <= unpaveddistance)enemy.Distance = unpaveddistance + 1;
	if (enemy.Distance <= 2)enemy.Distance = 3;
	return;

}
void EnemyHitsTower(Enemy &enemy, region &region, int time)
{
	if (enemy.Time_left_shoot == 0)
	{
		if (enemy.Type == 1)
		{
			region.towers.Health -= (1 / (float)enemy.Distance)*enemy.Fire_Power; //EL health 3'alat keda, mesh bet2el
			enemy.Time_left_shoot = enemy.Reload_Period;
		}
		if (enemy.Type == 4)
		{
			region.towers.Health -= (1 / (float)enemy.Distance)*enemy.Fire_Power; //EL health 3'alat keda, mesh bet2el
			enemy.Time_left_shoot = enemy.Reload_Period;
		}
		if (enemy.Type == 2)
		{
			region.towers.Health -= (2 / (float)enemy.Distance)*enemy.Fire_Power; //EL health 3'alat keda, mesh bet2el
			enemy.Time_left_shoot = enemy.Reload_Period;
		}
		 if (enemy.Type == 0 )

		{
			

			enemy.Distance -= enemy.Fire_Power;// not sure yet
			if (region.Unpaved_Distance > enemy.Distance) region.Unpaved_Distance = enemy.Distance - 1;
			if (enemy.Distance <= 2) enemy.Distance = 3;
			if (region.Unpaved_Distance < 2) region.Unpaved_Distance = 2;
			enemy.Time_left_shoot = enemy.Reload_Period;

		}
	}
	else
	{
		enemy.Time_left_shoot--;
		/*if (enemy.Distance> region.Unpaved_Distance  && enemy.Distance > 2) enemy.Distance -= enemy.speed;// check if the logic is right
		if (enemy.Distance <= region.Unpaved_Distance)enemy.Distance = region.Unpaved_Distance + 1;
		if (enemy.Distance <= 2)enemy.Distance = 3;*/
		if (enemy.Distance > 3) move(enemy, region.Unpaved_Distance);
	}

	return;
}
int warlockcheck(PList* priority)
{
	int checks = 0;
	pNode* current = priority->Front;
	while (current != NULL)
	{
		if (current->Enemy.Type == 3 && current->Enemy.Time_left_shoot == 0)
		{
			checks += current->Enemy.Fire_Power % 3;
			current->Enemy.Time_left_shoot = current->Enemy.Reload_Period;
		}
		current = current->next;
	}
	return checks;
}
void TowerHitsEnemy(region &region, PList*& pq, List*&q,int currenttime)
{

	int i = region.towers.N-warlockcheck(pq);
	if (i < 0) i = 0;
	Node* Nhit = q->Front;
	pNode *Phit = pq->Front;
	// check for warlock's flag first;
	while (i != 0 && Phit != NULL)
	{
		Phit->Enemy.Health =Phit->Enemy.Health -((1 /(float) Phit->Enemy.Distance)* (region.towers.Fire_Power / 2));
		if (Phit->Enemy.First_Hit_Time == NULL) Phit->Enemy.First_Hit_Time = currenttime;
		Phit = Phit->next;
		i--;
	}
	while (i != 0 && Nhit != NULL)
	{
	
		if(Nhit->Enemy.Type!=4) Nhit->Enemy.Health -= (1 /(float) Nhit->Enemy.Distance)*region.towers.Fire_Power * (1 / 1);
		if (Nhit->Enemy.Type == 4&&Nhit->Enemy.Time_left_shoot==0)
		{
			Nhit->Enemy.Health -= (1 /(float) Nhit->Enemy.Distance)*region.towers.Fire_Power * (1 / 1);
			
		}
		if (Nhit->Enemy.First_Hit_Time == NULL) Nhit->Enemy.First_Hit_Time = currenttime;
		Nhit = Nhit->next;
		i--;
	}

	return;
}

List* mergelists(List* dead, List* Alive)
{
	Node * merged = dead->Front;
	Node * mergea = Alive->Front;
	List *newlist = InitializeList();
	
	Node* removednode;
	
	if (merged == NULL)
	{
		return Alive;
    }
	if (mergea == NULL&&dead->Front!=NULL)
	{
		newlist->Front=dead->Front;
		newlist->Rear = dead->Rear;
		newlist->count = dead->count;
		dead->Front = NULL;
		dead->Rear = NULL;
		dead->count = 0;
		return newlist;
	}
	
	
	
	while (merged!=NULL ||mergea!=NULL)
	{
		if (merged!=NULL && mergea != NULL)
		{
			if (merged->Enemy.Arrival_Time <= mergea->Enemy.Arrival_Time)
			{
				merged = merged->next;
				removednode = DeleteFromBeg(dead);
				InsertAtEnd(newlist, removednode); //ptr=ptr->next?

			}
			else if (merged->Enemy.Arrival_Time > mergea->Enemy.Arrival_Time)
			{
				mergea = mergea->next;
				removednode = DeleteFromBeg(Alive);
				InsertAtEnd(newlist, removednode);
			}
		}
		 if (merged != NULL&&mergea == NULL)
	{
		merged = merged->next;
		removednode = DeleteFromBeg(dead);
		InsertAtEnd(newlist, removednode);
	}
		 if (merged == NULL&&mergea != NULL)
		 {
			 mergea = mergea->next;
			 removednode = DeleteFromBeg(Alive);
			 InsertAtEnd(newlist, removednode);
		 }
	}
	dead->Front = NULL;
	dead->Rear = NULL;
	
	return newlist;
	
	











	/*while (merged != NULL || mergea != NULL)
	{
		if (mergea == Alive->Front&&merged->Enemy.Arrival_Time < mergea->Enemy.Arrival_Time)
		{
			merged = merged->next;
			dead->Front->next = Alive->Front;
			Alive->Front = dead->Front;
			dead->Front = merged->next;
		}
		if (merged->Enemy.Arrival_Time < mergea->Enemy.Arrival_Time)
		{
			merged = merged->next;
			removednode = DeleteFromBeg(dead);
			InsertAtEnd(newlist, removednode);
	}
	*/


}

void reallocateposition(region dead ,region region, List* normal, PList* shielded,List* inactive)
{
	Node*tempo = normal->Front;
	pNode* temp = shielded->Front;
	REGION deadr = dead.regionnum;

	while (tempo != NULL)
	{
		if (tempo->Enemy.Distance <= region.Unpaved_Distance) tempo->Enemy.Distance = region.Unpaved_Distance + 1;
		
		tempo->Enemy.Region = region.regionnum;
		tempo = tempo->next;
		//readjust region
	}
	while (temp != NULL)
	{
		if (temp->Enemy.Distance <= region.Unpaved_Distance) temp->Enemy.Distance = region.Unpaved_Distance + 1;
		temp->Enemy.Region = region.regionnum;
		temp = temp->next;
	}
	Node* aregiontransformer = inactive->Front;
	while (aregiontransformer != NULL)
	{
		if (aregiontransformer->Enemy.Region == deadr)
		{
			aregiontransformer->Enemy.Region = region.regionnum;
			
		}
		aregiontransformer = aregiontransformer->next;
	}
	return;

}
//fight
void TransportEnemiez(region *regionDead, region *regionAlive,List* inactive)
{
	reallocateposition( *regionDead, *regionAlive, regionDead->nsoldiers, regionDead->shielded, inactive);
	//regionAlive->nsoldiers = mergelists(regionDead->nsoldiers, regionAlive->nsoldiers);
	regionAlive->nsoldiers=mergelists(regionDead->nsoldiers, regionAlive->nsoldiers);
	if (regionDead->shielded->Front != NULL&&regionAlive->shielded->Front!=NULL)
	{
		regionAlive->shielded->Rear->next = regionDead->shielded->Front;
		regionAlive->shielded->Rear = regionDead->shielded->Rear;
		regionAlive->shielded->count += regionDead->shielded->count;
	}
	if (regionDead->shielded->Front != NULL&&regionAlive->shielded->Front == NULL)
	{
		regionAlive->shielded->Front = regionDead->shielded->Front;
		regionAlive->shielded->Rear = regionDead->shielded->Rear;
		regionAlive->shielded->count = regionDead->shielded->count;


	}
	regionDead->shielded->count = 0;
	regionDead->shielded->Front = NULL;
	regionDead->shielded->Rear = NULL;




}

//Rotation..Laz
bool MoveEnemiez(region* regionX,List* inactive)
{
	region* dead = regionX;
	region *temp = regionX;
	int counter = 0;
	
		while (temp->towers.Health <= 0)
		{
			temp = temp->Next;
			counter++;
			if (counter == 4)
			{
				cout << "all The towers are dead....\n";
				return false;
			}
		}

		TransportEnemiez(dead, temp, inactive);
		MergeSortPriority(temp->shielded);
	}


void SimulateEachRegion(List *&ActiveX, PList *&ActiveShX, char Region, int time, region &RegionX,List* inactive)
{
	Node *Current;
	pNode *PCurrent;
//	Current = ActiveX->Front;
//	PCurrent = ActiveShX->Front;
	Current = RegionX.nsoldiers->Front;
	PCurrent = RegionX.shielded->Front;
	TowerHitsEnemy(RegionX, ActiveShX, ActiveX, time);
	while (PCurrent != NULL)
	{
		EnemyHitsTower(PCurrent->Enemy, RegionX, time);
		PCurrent = PCurrent->next;
	}

	while (Current != NULL)
	{ 
		EnemyHitsTower(Current->Enemy, RegionX, time);
		Current = Current->next;
	}

	

	if (RegionX.towers.Health <= 0)
	{
		RegionX.towers.Health = 0;
		region * reg = &RegionX;
		MoveEnemiez(reg,inactive);
	}


}

//to insert priority in each pnode
void InsertPriority(PList* &pactive, float c1, float c2, float c3)
{
	pNode * calculator = pactive->Front;
	while (calculator != NULL)
	{
		calculator->priority = (float(calculator->Enemy.Fire_Power) / float(calculator->Enemy.Distance))*c1 + (c2 / float(calculator->Enemy.Time_left_shoot + 1)) + c3*float(calculator->Enemy.Health);
		calculator = calculator->next;
	}
	return;
}

//Merge Sort
pNode* SortedMergePriority(PList* a, PList* b)
{
	pNode* result = NULL;

	// Base cases
	if (a->Front == NULL)
		return(b->Front);
	else if (b->Front == NULL)
		return(a->Front);

	// Pick either a or b, and recur
	// Phase2 if (a->Front->Enemy.Priority >=  b->Front->Enemy.Priority)
	if (a->Front->priority >= b->Front->priority) //For Phase 1
	{
		result = a->Front;
		a->Front = a->Front->next;
		result->next = SortedMergePriority(a, b);
	}
	else
	{
		result = b->Front;
		b->Front = b->Front->next;
		result->next = SortedMergePriority(a, b);
	}
	return(result);
}


void FrontBackSplitPriority(pNode* NewList, PList* FrontRef, PList* backRef)
{
	pNode* fast;
	pNode* slow;
	if (NewList == NULL || NewList->next == NULL)
	{
		// length < 2 cases
		FrontRef->Front = NewList;
		backRef->Front = NULL;
	}
	else
	{
		slow = NewList;
		fast = NewList->next;

		// Advance 'fast' two Nodes, and advance 'slow' one Node
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}

		FrontRef->Front = NewList;
		backRef->Front = slow->next;
		slow->next = NULL;
	}
}
void MergeSortPriority(PList* myList)
{
	pNode * Front = myList->Front;
	PList* a;
	PList* b;
	a = InitializePList();
	b = InitializePList();

	// Base case -- length 0 or 1
	if ((myList->Front == NULL) || (myList->Front->next == NULL))
	{
		return;
	}

	// Split Front into 'a' and 'b' subLists
	FrontBackSplitPriority(Front, a, b);

	// Recursively sort the subLists
	MergeSortPriority(a);
	MergeSortPriority(b);

	// answer = merge the two sorted Lists together
	myList->Front = SortedMergePriority(a, b);
}


