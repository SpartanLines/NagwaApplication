#pragma once
#include"Actions\Action.h"
class DeleteAction : public Action
{
	int pointer_position;
	int count;
public:
	DeleteAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

