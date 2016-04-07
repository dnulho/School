/* Author: Steven Ohlund
* Filename: cInventory.h
* Created: 4.6.16
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include <fstream>
using std::ofstream;
using std::ifstream;
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "cBook.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class cInventory
{
public:
	cInventory();
	~cInventory();

	// List Modification Functions
	void Add(const string& ISBN = "0-000-00000-0",
		const string& Author = "Unknown", const cDate& Published = { 0,0,0 },
		const uint16_t& Price = 0, const uint16_t& Quantity = 0);
	void Delete(const string& ISBN);
	void Purge();

	// Load/Save Functions
	void SaveToFile(ofstream& file);
	void LoadFromFile(ifstream& file);

	//Node Modification Functions
	void AddStock(const string& ISBN, uint16_t Quantity);
	void RemoveStock(const string& ISBN, uint16_t Quantity);
	void PriceChange(const string& ISBN, uint16_t newPrice);

	//Misc Functions
	uint32_t TotalValueOfInv();
	uint16_t RetrievePrice(const string& ISBN) const;
	void DisplayPrice(const string& ISBN) const;
	const cBook* const FindBookC(const string& ISBN) const;
	void DisplayFullList() const;

private:
	cBook* FindBook(const string& ISBN);

	cBook * m_head;
	cBook * m_tail;
};

void SaveInvToFile(cInventory & inv, const char * filename);
void LoadInvFromFile(cInventory & inv, const char * filename);

#endif // !INVENTORY_H