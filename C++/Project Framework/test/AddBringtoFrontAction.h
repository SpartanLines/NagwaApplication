#pragma once
#include"Actions\Action.h"
#include"ApplicationManager.h"
class AddBringtoFrontAction : public Action
{
	
public:
	AddBringtoFrontAction(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

