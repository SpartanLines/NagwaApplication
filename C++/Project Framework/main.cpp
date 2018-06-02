#include "ApplicationManager.h"


int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the interface
		if (AppManager.getzoomed()==0)
		AppManager.UpdateInterface();	
		else{
			AppManager.UpdateInterface(-1, 1);
		}

	}while(AppManager.getstate());
	

	
	return 0;
}

