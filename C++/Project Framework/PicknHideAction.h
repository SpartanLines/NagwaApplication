#pragma once
#include "Actions\Action.h"
#include"ApplicationManager.h"

class PicknHideAction : public Action
{
private:
	int mode,x,y;

public:

	PicknHideAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};