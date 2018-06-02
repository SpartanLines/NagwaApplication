#pragma once
#include "Actions\Action.h"
#include"ApplicationManager.h"


class RotateAction:public Action
{
private:
	int angle_of_rotation;
	Point p;
	bool succed;
	int *rot;
	int no_of_rotated;
public:
	RotateAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
