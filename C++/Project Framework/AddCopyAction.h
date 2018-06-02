#pragma once
#include "Actions\Action.h"
#include"ApplicationManager.h"

class AddCopyAction : public Action
{
//	CFigure *list;
public:
	
	AddCopyAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

