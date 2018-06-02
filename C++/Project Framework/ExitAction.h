#include "Actions\Action.h"
#include "ApplicationManager.h"

class ExitAction :public Action
{
	bool exit;
public:
	ExitAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};