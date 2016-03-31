/***************************************************
* Author: Steven Ohlund
* Filename: main.cpp
* Date Created: 3.30.16
* Modifications: none
***************************************************/
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

struct Coin
{
	int denom;				// 1 or 5 or 10 or 25
	long count;				// Occurrence count
	const char* single; 	// Text for ONE (1) occurrence (ie, “penny”);
	const char* multiple;	// Text for MORE THEN ONE occurrence (ie, “pennies”);
};

void CoinInit(Coin bank[4]);
long int GetAmount();
void CountCoins(Coin bank[4], long & value);
void PrintBank(const Coin bank[4]);
void ResetBank(Coin bank[4]);

/***************************************************
* Lab / Assignment: CST 136 - Lab 1
*
* Overview: This program will calculates the minimum number of quarters, dimes,
* nickels, and pennies that are contained within a given amount of money.  
*
* Input: User entered values for # of cents to be calculated. The value must be
* entered as an integer value of cents, not in dollar notation.
*
* Output: This program prints the optimal number of quarters  dimes, nickels, and
* pennies that make up the given cent value.
*
***************************************************/
int main()
{
	Coin bank[4];
	CoinInit(bank);
	bool done = false;
	
	cout << "Welcome to Steven's Optimal Change Computing Program\n";

	while (!done)
	{
		long int value = GetAmount();
		if (value == -1)
		{
			done = true;
			cout << "Thank you for using Steven's Optimal Change Computing Program\n"
				<< "Goodbye and have a nice day." << endl;
		}
		else if (value > -1)
		{
			system("cls");
			cout << "Optimal coinage for " << value << " cents is:\n";
			CountCoins(bank, value);
			PrintBank(bank);
		}
		else
			cout << "Error: Invalid amount" << endl;
		ResetBank(bank);
	}
	return 0;
}

/***************************************************
* Purpose: To Initialize the bank values at the beginning of the program.
*
* Preconditions: bank must be initialized before being passed.
*
* Postconditions: All of the values in bank are set to known and correct values.
***************************************************/
void CoinInit(Coin bank[4])
{
	bank[3].denom = 1;
	bank[3].single = "Penny";
	bank[3].multiple = "Pennies";

	bank[2].denom = 5;
	bank[2].single = "Nickel";
	bank[2].multiple = "Nickels";

	bank[1].denom = 10;
	bank[1].single = "Dime";
	bank[1].multiple = "Dimes";

	bank[0].denom = 25;
	bank[0].single = "Quarter";
	bank[0].multiple = "Quarters";

	ResetBank(bank);
}

/***************************************************
* Purpose: Gather User Input and pass to caller.
*
* Preconditions: None
*
* Postconditions: Pass user input to caller
***************************************************/
long int GetAmount()
{
	long value = 0;
	cout << "Please input the number of cents you wish to compute"
		<< "\n(enter -1 to exit):";
	cin >> value;
	return value;
}

/***************************************************
* Purpose: Distribute value to optimal coinages in bank.
*
* Preconditions: bank must be initialized before being passed.
*				 value should have a positive value.
*
* Postconditions: value = 0, bank contains the optimal number of each coin
*				  to equal original value.
***************************************************/
void CountCoins(Coin bank[4], long & value)
{
	for (int ii = 0; ii < 4; ii++)
	{
		while (value >= bank[ii].denom)
		{
			bank[ii].count++;
			value -= bank[ii].denom;
		}
	}
}

/***************************************************
* Purpose: To display bank in a user friendly way to the display.
*
* Preconditions: bank must be initilized and should hold valid data.
*
* Postconditions: Info in bank is displayed onscreen.
***************************************************/
void PrintBank(const Coin bank[4])
{
	for (int ii = 0; ii < 4; ii++)
	{
		switch (bank[ii].count)
		{
		case 0:
			break;
		case 1:
			cout << "\t1 " << bank[ii].single << endl;
			break;
		default:
			cout << "\t" << bank[ii].count << " " << bank[ii].multiple << endl;
			break;
		}
	}
}

/***************************************************
* Purpose: To 0-out the bank so a new value can be computed.
*
* Preconditions: bank must be initialized before being passed.
*
* Postconditions: All bank counts are 0.
***************************************************/
void ResetBank (Coin bank[4])
{
	for (int ii = 0; ii < 4; ii++)
	{
		bank[ii].count = 0;
	}
}