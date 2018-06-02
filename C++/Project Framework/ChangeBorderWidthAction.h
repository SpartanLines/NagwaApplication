#pragma once

#include"Actions\Action.h"
#include"ApplicationManager.h"

class ChangeBorderWidthAction :public Action
{
	int newborderwidth;
	Point P;
public:
	ChangeBorderWidthAction(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
};