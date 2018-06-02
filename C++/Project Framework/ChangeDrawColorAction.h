#pragma once

#include"Actions\Action.h"

class ChangeDrawColorAction :public Action
{
private:
	Point click;
	int num;
	mycolor *arr;
	color newcolor;
	color oldfill;
public:
	ChangeDrawColorAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};