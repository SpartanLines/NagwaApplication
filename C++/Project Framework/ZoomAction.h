#pragma once

#include"Actions\Action.h"
#include"ApplicationManager.h"
#include<Windows.h>
#include<fstream>
#include<ShObjIdl.h>

class ZoomAction :public Action
{
public:
	ZoomAction(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();


	
};
