#pragma once
#include "Actions\Action.h"

class AddTriangleAction : public Action
{
	Point P1, P2, P3;
	GfxInfo TriGfxInfo;
	
public:
	AddTriangleAction(ApplicationManager * pApp);
	void ReadActionParameters();
	void Execute();
	virtual void Undo();
	virtual void Redo();
};

