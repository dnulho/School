/* Author: Steven Ohlund
* Filename: main.cpp
* Created: 4.6.16
*/

#define _CRTDBG_MAP_ALLOC
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <crtdbg.h>

#include "cInventory.h"

int Menu();

void AddBook(cInventory&);
void RemoveBook(cInventory&);
void FindBook(const cInventory&);
void ChangePrice(cInventory&);
void SellBooks(cInventory&);
void AddInv(cInventory&);

// Driver to prove that the classes work correctly
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	cInventory inv;
	bool done = false;

	LoadInvFromFile(inv, "inv.txt");

	while (!done)
	{
		switch (Menu())
		{
		case 1:
			AddBook(inv);
			break;
		case 2:
			RemoveBook(inv);
			break;
		case 3:
			FindBook(inv);
			break;
		case 4:
			ChangePrice(inv);
			break;
		case 5:
			SellBooks(inv);
			break;
		case 6:
			AddInv(inv);
			break;
		case 7:
			inv.DisplayFullList();
			break;
		case 8:
			DisplayDollars(inv.TotalValueOfInv());
			cout << endl;
			break;
		case 0:
			done = true;
			break;
		}
	}
	SaveInvToFile(inv,"inv.txt");

	return 0;
}

// User Menu
int Menu()
{
	int choice;
	cout << "0) Exit\n"
		<< "1) Add Book\n"
		<< "2) Remove Book\n"
		<< "3) Find/Display Book\n"
		<< "4) Change Price\n"
		<< "5) Sell Books\n"
		<< "6) Add Book Quantity\n"
		<< "7) Display All Inventory\n"
		<< "8) Show Total Value of Inventory\n";
	cin >> choice;
	return choice;
}

// Add a book to the inventory
void AddBook(cInventory& inv)
{
	string ISBN, Author;
	uint8_t day, month;
	uint16_t year;
	int price, quantity;
	char temp[6];

	cout << "What is the ISBN?";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, ISBN);

	cout << "Author's Name: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, Author);

	cout << "Publish Date: (day.month.year) ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(temp, 6, '.');
	day = atoi(temp);
	cin.getline(temp, 6, '.');
	month = atoi(temp);
	cin.getline(temp,6);
	year = atoi(temp);

	cout << "Price in cents: ";
	cin.getline(temp, 6);
	price = atoi(temp);

	cout << "Quantity in store: ";
	cin.getline(temp, 6);
	quantity = atoi(temp);

	inv.Add(ISBN, Author, { day,month,year }, price, quantity);
}

// Remove a book from the inventory
void RemoveBook(cInventory & inv)
{
	string ISBN;
	cout << "What is the ISBN to remove: ";
	cin >> ISBN;
	inv.Delete(ISBN);
}

// Find and display a book to screen based on a book's ISBN
void FindBook(const cInventory& inv)
{
	string ISBN;
	cout << "What is the ISBN to find: ";
	cin >> ISBN;
	const cBook* book = inv.FindBookC(ISBN);
	if (book)
		book->DisplayAll();
	else
		cout << "Error: Book Not Found" << endl;
}

// Modify an ISBN's price
void ChangePrice(cInventory & inv)
{
	string ISBN;
	uint16_t price;
	cout << "What is the ISBN to change the price of: ";
	cin >> ISBN;
	cout << "What is the new price in cents: ";
	cin >> price;
	inv.PriceChange(ISBN, price);
}

// Remove items from an ISBN
void SellBooks(cInventory & inv)
{
	string ISBN;
	uint16_t quantity;
	cout << "What is the ISBN to sell: ";
	cin >> ISBN;
	cout << "How many sold: ";
	cin >> quantity;
	inv.RemoveStock(ISBN, quantity);
}

// Add items from an ISBN
void AddInv(cInventory & inv)
{
	string ISBN;
	uint16_t quantity;
	cout << "What is the ISBN to add quantity to: ";
	cin >> ISBN;
	cout << "How many added: ";
	cin >> quantity;
	inv.AddStock(ISBN, quantity);
}