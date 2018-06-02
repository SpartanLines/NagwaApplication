#pragma once
#include "Actions\Action.h"
#include "ApplicationManager.h"
class ResizeAction : public Action
{
private:
	
	Point P;// to get his click on resize choices
	float factor;
	bool succed;
	int *id;
	int num;

public:
	ResizeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

