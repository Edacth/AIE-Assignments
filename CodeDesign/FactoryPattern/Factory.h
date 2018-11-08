//Factory.h
#pragma once
#include <iostream>
#include "IBox.h"
#include "RedBox.h"
#include "BlueBox.h"
#include "IFactory.h"

class Factory : public IFactory
{
private:
	Factory();
	~Factory();

public:
	//This is virtual because it may have children that use the funtion. 
	//Virtual DOES NOT mean it cannot be called.
	virtual IBox * Create(std::string type);
	static Factory& GetInstance();

};
