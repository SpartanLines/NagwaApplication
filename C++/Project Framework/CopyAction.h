#pragma once
#include "Actions\Action.h"
#include"ApplicationManager.h"

class CopyAction : public Action
{

public:

	CopyAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

