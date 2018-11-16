#include "stateMachine.h"

stateMachine::stateMachine()
{
	state = 0;
}


stateMachine::~stateMachine()
{
}

stateMachine& stateMachine::GetInstance()
{
	static stateMachine instance;
	return instance;
}

bool stateMachine::setState(const int a)
{
	if (GetInstance().state != a)
	{
		GetInstance().state = a;
		return true;
	}
	return false;
}

int stateMachine::getState()
{
	return GetInstance().state;
}