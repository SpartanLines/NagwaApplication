#pragma once

#include "Actions\Action.h"
#include "ApplicationManager.h"

class RedoAction :public Action

{
public:
	RedoAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};