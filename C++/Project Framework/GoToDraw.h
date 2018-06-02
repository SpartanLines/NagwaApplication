#pragma once
#include"Actions\Action.h"

class GoToDraw :public Action
{
private:	Point click;
public:
	GoToDraw(ApplicationManager *pApp);

	void ReadActionParameters();
	void Execute();
};

