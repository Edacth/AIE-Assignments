#include "Piggy.h"



void Piggy::deposit(float deposit)
{
	balance += deposit;
}


void Piggy::withdrawl()
{
	balance = 0.0;
}

float Piggy::Balance()
{
	return balance;
}