




#ifndef ADD_CIRCLE_ACTION_H
#define ADD_CIRCLE_ACTION_H

#include "Actions\Action.h"

//Add Rectangle Action class
class AddCircleAction : public Action
{
private:
	Point P1, P2; //Rectangle Corners
	int radius;
	GfxInfo CircleGfxInfo;
	
public:
	AddCircleAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

};

#endif















