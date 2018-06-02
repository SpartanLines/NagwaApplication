#pragma once
#include"Actions\Action.h"

class GoToPlay:public Action
{
private:	Point click;
public:
	GoToPlay(ApplicationManager *pApp);

	void ReadActionParameters();
	void Execute();
};