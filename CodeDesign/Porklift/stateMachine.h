#pragma once
enum GStates
{
	MainMenu=0,
	OptionsMenu,
	PlayerSelect,
	InGame,
	GameOver
};

class stateMachine
{
// since the only constructors are private, only this class can create it
private:
	int state;
	stateMachine();
	stateMachine(stateMachine const&);
	void operator=(stateMachine const&);

public:
	// other parts of your code have to use this function to get an instance of TestSingleton
	static stateMachine& GetInstance();
	static int addInts(const int a, const int b);
	static bool setState(const int a);
	static int getState();
	~stateMachine();
};

