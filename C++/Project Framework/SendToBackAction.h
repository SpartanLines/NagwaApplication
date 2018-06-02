#include "Actions\Action.h"
#include"ApplicationManager.h"


class SendToBackAction :public Action
{
public:
	SendToBackAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};