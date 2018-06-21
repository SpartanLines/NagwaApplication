#include "Structs_Utility.h"

void initializereg(region &region, Tower tower)
{

	region.towers = tower;
	region.nsoldiers = NULL;
	region.shielded = NULL;
	region.Unpaved_Distance = 30;

}

void initializeregions(region &regiona, region& regionb, region& regionc, region& regiond, castle ct)
{
	/*Tower t = ct.towers[0];
	initializereg(regiona, t);
	initializereg(regionb, t);
	initializereg(regionc, t);
	initializereg(regiond, t);*/
	initializereg(regiona, ct.towers[0]);
	initializereg(regionb, ct.towers[1]);
	initializereg(regionc, ct.towers[2]);
	initializereg(regiond, ct.towers[3]);
	regiona.Next = &regionb;
	regionb.Next = &regionc;
	regionc.Next = &regiond;
	regiond.Next = &regiona;
	regiona.regionnum = A_REG;
	regionb.regionnum = B_REG;
	regionc.regionnum = C_REG;
	regiond.regionnum = D_REG;
	return;
}


void holdq(region &region, List *active, PList *pactive) // gives every region hold of its own Lists, hence direct linking of Lists and the tower they should hit
{
	region.nsoldiers = active;
	region.shielded = pactive;
	return;
}
