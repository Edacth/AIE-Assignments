#pragma once

class Person 
{

private:
	int age = 25;
	int poundCake = 10;

public:
	void Greet();

	int getAge();
	void setAge(int a);
	int getPoundCake();
};