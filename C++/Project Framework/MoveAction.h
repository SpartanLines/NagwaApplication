
#ifndef Move_ACTION_H
#define Move_ACTION_H

#include "Actions\Action.h"
#include "ApplicationManager.h"

class MoveAction :public Action
{
private:	Point movingpoint;
			Point oldaveragecenter;
			int pointer_position;
			int count;
			bool succed;

public:

	MoveAction(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
	virtual void Undo();
	virtual void Redo();

};
















#endif
