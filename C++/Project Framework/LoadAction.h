#pragma once
#include"Actions\Action.h"
#include "ApplicationManager.h"

class LoadAction :public Action
{

public:
   LoadAction(ApplicationManager *pApp);

	void ReadActionParameters();
	void Execute();
};