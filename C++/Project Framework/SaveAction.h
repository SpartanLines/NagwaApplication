#pragma once
#include "Actions\Action.h"
#include "ApplicationManager.h"

class SaveAction :public Action
{
	
public:
	SaveAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};