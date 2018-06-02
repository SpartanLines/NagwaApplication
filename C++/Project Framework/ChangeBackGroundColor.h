#pragma once

#include"Actions\Action.h"

class ChangeBackGroundColorAction :public Action
{
private:
	Point click;
	color old_color;
	color newcolor;
	bool wrongcolor;
public:
	ChangeBackGroundColorAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};