#pragma once
#include "Actions\Action.h"
#include"ApplicationManager.h"

class PasteAction : public Action
{
private:
	Point PastePnt;
	int count;
	int pointer_position;
	bool succed;
public:

	PasteAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

