#pragma once

//Declaring a struct
struct piggybank
{
	//Age of person
	int oneDollarBills;
	int twoDollarBills;
	int fiveDollarBills;
	int quarters;
	int dimes;
	int nickels;
	int pennies;

};

// Returns the total monetary value of all dollar bills.
float calcPiggybankNotes(piggybank piggy);

// Returns the total monetary value of all coins.
float calcPiggybankCoins(piggybank piggy);

// Returns the total monetary value of the piggybank's contents.
float calcPiggybankTotal(piggybank piggy);

//Withdrals
piggybank deposit(piggybank &myBank, int oneDollarAddition, int twoDollarAddition,
	int fiveDollarAddition, int quarterAddition, int dimeAddition, int nickelAddition, int pennyAddition);