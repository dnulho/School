#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ios;
using std::setw;

struct transaction
{
	int amount;
	string name;
	time_t date;
};

int menu();
int add(transaction **& trans, int & count);
void display(transaction ** log, int &count);
void erase(transaction **& log, int& count);


int main()
{

	transaction ** log = nullptr;
	int count = 0;

	cout << "Transaction Log" << endl;
	bool done = false;
	while (!done) 
	{
		switch (menu())
		{
		case 1:
			add(log, count);
			break;
		case 2:
			display(log, count);
			break;
		case 3:
			erase(log, count);
			break;
		case 4:
			done = true;
			break;
		}
	}

	return 0;
}

int menu()
{
	int choice;
	do {
		cout << "Main Menu" << endl;
		cout << "1) Add a transaction" << endl;
		cout << "2) View all transactions" << endl;
		cout << "3) Erase all transactions" << endl;
		cout << "4) Exit" << endl;
		cout << "\nEnter choice: ";
		cin >> choice;
	} while (choice < 1 || choice > 4);
	return choice;
}

int add(transaction **& log, int & count)
{
	char buffer[100];
	int value;

	cout << "Name: ";
	cin >> buffer;
	cout << "Value: ";
	cin >> value;
	transaction ** temp = new transaction* [count + 1];
	for (int ii = 0; ii < count; ii++)
	{
		temp[ii] = log[ii];
	}
	temp[count] = new transaction;
	temp[count]->amount = value;
	temp[count]->name = _strupr(buffer);
	time(&temp[count]->date);

	delete[] log;
	log = temp;
	count++;
	return 0;
}

void display(transaction ** log, int &count)
{
	int total = 0;
	cout << "NAME                           Value     Last Modified" << endl;
	if (log)
	{
		for (int ii = 0; ii < count; ii++)
		{
			cout << setiosflags(ios::left) << setw(30) << log[ii]->name << " " << setw(10) << log[ii]->amount << ctime(&log[ii]->date) << endl;
			total += log[ii]->amount;
		}
	}
	else
	{
		cout << "-- Empty --" << endl;
	}

	cout << "\nTotal: " << total << endl;
}

void erase(transaction **& log, int& count)
{
	for (int ii = 0; ii < count; ii++)
	{
		delete log[ii];
		log[ii] = nullptr;
	}
	delete[] log;
	log = nullptr;
	count = 0;
}
