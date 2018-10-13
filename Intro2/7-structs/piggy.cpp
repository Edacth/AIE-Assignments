#include <iostream>
#include "piggy.h"

// Returns the total monetary value of all dollar bills.
float calcPiggybankNotes(piggybank piggy)
{
	float total = 0;

	total += (piggy.oneDollarBills * 1.0f);
	total += (piggy.twoDollarBills * 2.0f);
	total += (piggy.fiveDollarBills * 5.0f);
	return total;
}

// Returns the total monetary value of all coins.
float calcPiggybankCoins(piggybank piggy)
{
	float total = 0;

	total += (piggy.quarters * 0.25f);
	total += (piggy.dimes * 0.10f);
	total += (piggy.nickels * 0.05f);
	total += (piggy.pennies * 0.01f);
	return total;
}

// Returns the total monetary value of the piggybank's contents.
float calcPiggybankTotal(piggybank piggy)
{
	float total = 0;

	total += (piggy.oneDollarBills * 1.0f);
	total += (piggy.twoDollarBills * 2.0f);
	total += (piggy.fiveDollarBills * 5.0f);
	total += (piggy.quarters * 0.25f);
	total += (piggy.dimes * 0.10f);
	total += (piggy.nickels * 0.05f);
	total += (piggy.pennies * 0.01f);
	return total;
}


//ASK TERRY WHY THE & THROWS AN ERROR
piggybank deposit(piggybank &myBank, int oneDollarAddition, int twoDollarAddition, 
	int fiveDollarAddition, int quarterAddition, int dimeAddition, int nickelAddition, int pennyAddition)
{
	myBank.oneDollarBills += oneDollarAddition;

	return myBank;
}