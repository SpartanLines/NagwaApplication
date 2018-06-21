#include "LoadFile_Lists.h"

using namespace std;

//To open file, insert data, And check the The region and type of enemy and insert it in the corresponding List:
void LoadData(ifstream &input_file, List* inactive, float &c1, float &c2, float &c3, castle &ct)
{
	input_file.open("Case 150.txt");

	if (input_file.fail())
	{
		cerr << "ERROR! Re-check the existance of your input file... " << endl;
		system("pause");
		exit(1);
	}

	int Tower_health, N, Tower_FirePower;
	input_file >> Tower_health >> N >> Tower_FirePower;

	ct.towers[0].Health = Tower_health;
	ct.towers[1].Health = Tower_health;
	ct.towers[2].Health = Tower_health;
	ct.towers[3].Health = Tower_health;

	ct.towers[0].N = N;
	ct.towers[1].N = N;
	ct.towers[2].N = N;
	ct.towers[3].N = N;

	ct.towers[0].Fire_Power = Tower_FirePower;
	ct.towers[1].Fire_Power = Tower_FirePower;
	ct.towers[2].Fire_Power = Tower_FirePower;
	ct.towers[3].Fire_Power = Tower_FirePower;

	input_file >> c1 >> c2 >> c3;

	int seq;
	input_file >> seq;

	while (seq != -1)
	{
		Node*Temp_Enemy = new Node;

		Temp_Enemy->Enemy.ID = seq;
		Temp_Enemy->Enemy.Distance = 60;
		Temp_Enemy->Enemy.Time_left_shoot = 0;
		Temp_Enemy->Enemy.First_Hit_Time = 0;
		

		int type;
		input_file >> type;

		if (type == 0) Temp_Enemy->Enemy.Type = Paver;
		else if (type == 1) Temp_Enemy->Enemy.Type = Fighter;
		else if (type == 2) Temp_Enemy->Enemy.Type = Shielded;
		else if (type == 3) Temp_Enemy->Enemy.Type = warlock;
		else if (type == 4) Temp_Enemy->Enemy.Type = ninja;
		

		input_file >> Temp_Enemy->Enemy.Arrival_Time >> Temp_Enemy->Enemy.Health >> Temp_Enemy->Enemy.Fire_Power >> Temp_Enemy->Enemy.Reload_Period>>Temp_Enemy->Enemy.speed;

		char reg;
		input_file >> reg;

		if (reg == 'A') Temp_Enemy->Enemy.Region = A_REG;
		else if (reg == 'B') Temp_Enemy->Enemy.Region = B_REG;
		else if (reg == 'C') Temp_Enemy->Enemy.Region = C_REG;
		else if (reg == 'D') Temp_Enemy->Enemy.Region = D_REG;

		if (Temp_Enemy->Enemy.Type == Shielded)
		{
			
			InsertAtEnd(inactive, Temp_Enemy);
		}
		else
		{
			
			InsertAtEnd(inactive, Temp_Enemy);
		}
		input_file >> seq;
	}
	input_file.close();
}


void InputFilesGenerator()
{
	//	srand(time(0));
	fstream outputfile("Input1.txt", ios::out);

	outputfile << 300 << "    " << 3 << "     " << 20 << endl;
	outputfile << 1 << "    " << 0.03 << "   " << 0.01 << endl;
	int randomregion;
	int randomtype;
	char ch;
	int c = 1;
	int tempo = rand() % 26 + 50;
	for (int i = 0; i < 78; i++)
	{
		randomtype = rand() % 5;
		int randomchance = rand() % 8;
		if (randomchance == 0 || randomchance == 2 || randomchance == 5)
		{
			c++;
		}
		else if (randomchance == 4) c = c + rand() % 6;
		else if (randomchance == 3) c += 2;
		randomregion = rand() % 4;
		if (randomregion == 0) ch = 'A';
		if (randomregion == 1) ch = 'B';
		if (randomregion == 2) ch = 'C';
		if (randomregion == 3) ch = 'D';

		outputfile << i << "    " << randomtype << "    " << c << "    " << rand() % 30 + 13 << "    " << rand() % 7 + 2 << "    " << rand() % 4 + 2 << "    " << ch << endl;
	}
}


//To Create a new List and set Front & Rear to NULL and count to 0.
List * InitializeList()
{
	List*temp = new List;
	temp->Front = NULL;
	temp->Rear = NULL;
	temp->count = 0;
	return temp;
}

PList * InitializePList()
{
	PList *temp = new PList;
	temp->Front = NULL;
	temp->Rear = NULL;
	temp->count = 0;
	return temp;
}

void InitializeAll(List *&ActiveX, PList *&ActiveShX)
{
	ActiveX = InitializeList();
	ActiveShX = InitializePList();
}

bool InsertAtEnd(List *ListX, Node *Temp_Enemy)
{
	if (ListX->Front == NULL) //List is empty
	{
		ListX->Front = Temp_Enemy;
		ListX->Rear = Temp_Enemy;
		Temp_Enemy->next = NULL;
		ListX->count++;
		return true;
	}
	Temp_Enemy->next = NULL; //NULL
	ListX->Rear->next = Temp_Enemy;
	ListX->Rear = Temp_Enemy;
	ListX->count++;
	return true;
}

bool InsertAtTheEndPList(PList* pq, Enemy enemy)
{
	pNode *ptr = new pNode;
	if (ptr == NULL) //No enough memory
		return false;

	ptr->Enemy = enemy;
	ptr->next = NULL;
	ptr->priority = 0;
	if (pq->Rear == NULL) //list empty
	{
		pq->Front = ptr;
		pq->Rear = ptr;
		pq->count++;
		return true;
	}
	pq->Rear->next = ptr;
	pq->Rear = ptr;
	pq->count++;
	return true;
}

//Simple DeleteFromBeg, but it DeleteFromBegs a Node instead of a val of type int.
Node * DeleteFromBeg(List*ListX)
{
	//if (ListX->Front == NULL) //empty
	//	return; 

	Node *temp = ListX->Front;
	ListX->Front = ListX->Front->next;
	if (ListX->Front == NULL)
		ListX->Rear = NULL;

	ListX->count--;

	temp->next = NULL;
	return temp;
}

pNode * DeleteFromBegShielded(PList*ListX)
{
	//if (ListX->Front == NULL) //empty
	//	return; 

	pNode *temp = ListX->Front;
	ListX->Front = ListX->Front->next;
	if (ListX->Front == NULL)
		ListX->Rear = NULL;

	ListX->count--;

	temp->next = NULL;
	return temp;
}

// In case of Dead Enemies in The Middle of a List, it Removes them From List and Returns the deleted Node
Node * DeleteNodeFromMid(List*ListX, Node *&delNode)
{
	Node *current = ListX->Front;

	if (current == delNode) //first element
	{
		delNode = delNode->next;
		Node *y = DeleteFromBeg(ListX);
		
		//ListX->Front=delNode ;
		return y;
	}
	Node *pre = ListX->Front;
	current = current->next;

	while (current != NULL && current != delNode) //del surely exists
	{
		pre = pre->next;
		current = current->next;
	}
	delNode = delNode->next;
	pre->next = pre->next->next;
	if (pre->next == NULL)
		ListX->Rear = pre;


	ListX->count--;

	current->next = NULL;

	return current;
}

pNode * DeleteNodeFromMidShielded(PList*ListX, pNode *&delNode)
{
	pNode *current = ListX->Front;

	if (current == delNode) //first element
	{
		pNode *y = DeleteFromBegShielded(ListX);
		delNode = delNode->next;
		return y;
	}
	pNode *pre = ListX->Front;
	current = current->next;

	while (current != NULL && current != delNode) //del surely exists
	{
		pre = pre->next;
		current = current->next;
	}
	delNode = delNode->next;
	pre->next = pre->next->next;
	if (pre->next == NULL)
		ListX->Rear = pre;


	ListX->count--;

	current->next = NULL;

	return current;
}

//Recieves a list of inactive enemies, and DeleteFromBeg/from mid the Active ones and inserts them in the ActiveX/ActiveSh List
// at each time step
void ActiveEnemies(List* &inactive, List* &ActiveX, PList* &ActiveSh, int time, REGION region)
{
	Node*current = inactive->Front;
	Node *y;
	while (current != NULL && current->Enemy.Arrival_Time <= time)
	{
		if (current->Enemy.Region == region)
		{
			y = DeleteNodeFromMid(inactive, current);
			if (y->Enemy.Type == Shielded || y->Enemy.Type == warlock)
			{
				Enemy Shielded = y->Enemy;
				InsertAtTheEndPList(ActiveSh, Shielded);
			}
			else
				InsertAtEnd(ActiveX, y);
		}
		else
			current = current->next;
	}
}

void bubbsort(List*dead)
{
	int j = dead->count-1;
	Node* ptr = dead->Front;
	if (dead->Front == NULL||dead->Front->next==NULL) return;
	Node* next = ptr->next;
	Node* temp = new Node;
	while (j != 0)
	{
		for (int i = 0; i<j;i++)
		{
			if (ptr->Enemy.First_Hit_Time - ptr->Enemy.Arrival_Time > next->Enemy.First_Hit_Time - next->Enemy.Arrival_Time)
			{
				temp->Enemy = ptr->Enemy;
				ptr->Enemy = next->Enemy;
				next->Enemy = temp->Enemy;
			}
			ptr = ptr->next;
			next = next->next;
		
		}
		j--;
	}

	return;

}
void writeoutputfile(ofstream & ofile, List* dead,int timedeath)
{
	Node * ptr = dead->Front;

	while (ptr != NULL)
	{
		ofile << timedeath << "   " << ptr->Enemy.ID << "   " << ptr->Enemy.First_Hit_Time - ptr->Enemy.Arrival_Time << "   " << timedeath - ptr->Enemy.First_Hit_Time << "    " << timedeath - ptr->Enemy.Arrival_Time << endl;
		ptr = ptr->next;
	}
}


bool isgame(region a, region b, region c, region d, List* inactives)
{
	if (a.towers.Health == 0 && b.towers.Health == 0 && c.towers.Health == 0 && d.towers.Health == 0)
		return false;

	else return true;



}