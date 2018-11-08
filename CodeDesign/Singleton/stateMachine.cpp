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

int stateMachine::addInts(const int a, const int b)
{
	return a + b;
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