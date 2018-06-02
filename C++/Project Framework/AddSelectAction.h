#ifndef ADD_SELECT_ACTION_H
#define ADD_SELECT_ACTION_H

#include"Actions\Action.h"
class AddSelectAction :public Action
{
private:
	Point p;
	
public:
	AddSelectAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();


};














#endif