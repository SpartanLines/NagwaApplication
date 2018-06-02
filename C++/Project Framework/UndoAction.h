#pragma once 
#include "Actions\Action.h"
#include"ApplicationManager.h"

class UndoAction :public Action
{
public:
	UndoAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	
	virtual void Execute();
};