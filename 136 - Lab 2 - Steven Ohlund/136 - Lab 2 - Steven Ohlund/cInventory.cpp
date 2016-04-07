/* Author: Steven Ohlund
* Filename: cInventory.cpp
* Created: 4.6.16
*/

#include "cInventory.h"

// Set inital nullptrs so everything works correctly
cInventory::cInventory()
	:m_head(nullptr),m_tail(nullptr)
{
}

// Self-explanatory
cInventory::~cInventory()
{
	Purge();
}

// Add a Book to the list
void cInventory::Add(const string& ISBN, const string& Author, const cDate& PubDate,
	const uint16_t& Price, const uint16_t& Quantity)
{
	cBook * nn = new cBook(ISBN, Author, PubDate, Price, Quantity);
	// If the head is null/empty or the new node is going to be added to front
	if (m_head == nullptr || nn->m_ISBN <= m_head->m_ISBN)
	{							// 1 = node before, 2 = new node, 3 = next node
		nn->m_next = m_head;			// 2 next points to head		
		if (m_tail == nullptr)		// If tail is empty
			m_tail = nn;				// tail points to 2
		else
			m_head->m_previous = nn;	// 3 previous points to 2
		m_head = nn;					// head points to 2
	}
	else
	{
		cBook * travel = m_head;
		// Iterate through the list until the new song title goes before the traveling pointer
		// or travel reaches the end of the list
		while (travel != nullptr && travel->m_ISBN < nn->m_ISBN)
		{
			travel = travel->m_next;
		}
		// If the song is being added to the end of the list
		if (travel == nullptr)
		{							 // 1 = node before, 2 = new node, 3 = next node
			m_tail->m_next = nn;	 // 1 next points to 2
			nn->m_previous = m_tail; // 2 previous points to 1
			m_tail = nn;			 // tail points to 2
		}
		// If the song is being added in the middle of the list
		else
		{								 // 1 = node before, 2 = new node, 3 = next node
			nn->m_previous = travel->m_previous; // 2 previous points to 1
			travel->m_previous->m_next = nn;	 // 1 next points to 2
			travel->m_previous = nn;			 // 3 previous points to 2
			nn->m_next = travel;				 // 2 next points to 3
		}
	}
}

// Delete the ISBN Book from the list
void cInventory::Delete(const string& ISBN)
{
	// If list is not empty
	if (m_head != nullptr)
	{
		cBook * travel = m_head;
		// Move along list until the ISBN is found
		while (travel != nullptr && travel->m_ISBN != ISBN)
		{
			travel = travel->m_next;
		}
		// If the book is found
		if (travel != nullptr)
		{								 // 1 = node before, 2 = current node, 3 = next node in list
			if (travel->m_previous != nullptr)			// If 1 exists
				travel->m_previous->m_next = travel->m_next;		// 1 next points to 3
			else
				m_head = travel->m_next;							// head points to 3
			if (travel->m_next != nullptr)				// If 3 exists
				travel->m_next->m_previous = travel->m_previous;	// 3 previous points to 1
			else
				m_tail = travel->m_previous;						// tail points to 1
			delete travel;											// Dealllocate 2
		}
		// If the book is not found do nothing
	}
}

// Remove all books from memory, and empty the inventory
void cInventory::Purge()
{
	while (m_head != nullptr)			// While there are elements in the list
	{
		m_head = m_head->m_next;		// Move m_head to the next element
		if (m_head != nullptr)			// if head points to something
			delete m_head->m_previous;	// Delete the previous element
		else
			delete m_tail;				// Delete the last node
	}
	m_tail = nullptr;
}						// At the end of this function, m_head and m_tail are nullptr

// Save all books to passed ofstream
void cInventory::SaveToFile(ofstream& file)
{
	cBook * travel = m_head;
	while (travel != nullptr)
	{
		file << travel->m_ISBN << "|" << travel->m_Author << "|" << travel->m_PubDate << "|" 
			<< travel->m_Price << "|" << travel->m_Quantity;
		if (travel->m_next != nullptr)
			file << "\n";
		travel = travel->m_next;
	}
}

// Load all books from passed ifstream
void cInventory::LoadFromFile(ifstream & file)
{
	string ISBN;
	string Author;

	cDate PubDate;
	uint16_t Price;
	uint16_t Quantity;

	const uint8_t BUFF_S = 10;
	char buffer[BUFF_S];

	while (!file.eof())
	{
		// Get ISBN and Author for the next book
		getline(file, ISBN, '|');
		getline(file, Author, '|');

		// Get PubDate from file
		file.getline(buffer, BUFF_S, '.');
		PubDate.SetDay(atoi(buffer));
		file.getline(buffer, BUFF_S, '.');
		PubDate.SetMonth(atoi(buffer));
		file.getline(buffer, BUFF_S, '|');
		PubDate.SetYear(atoi(buffer));

		//Get Price from file
		file.getline(buffer, BUFF_S, '|');
		Price = atoi(buffer);

		//Get Quantity from file
		file.getline(buffer, BUFF_S);
		Quantity = atoi(buffer);

		Add(ISBN, Author, PubDate, Price, Quantity);
	}
}

// Add Quantity from m_Quantity in ISBN book
void cInventory::AddStock(const string & ISBN, uint16_t Quantity)
{
	FindBook(ISBN)->Add_Q(Quantity);
}

// Remove Quantity from m_Quantity in ISBN book
void cInventory::RemoveStock(const string & ISBN, uint16_t Quantity)
{
	FindBook(ISBN)->Remove_Q(Quantity);
}

// Change Price of ISBN book to newPrice
void cInventory::PriceChange(const string & ISBN, uint16_t newPrice)
{
	FindBook(ISBN)->ChangePrice(newPrice);
}

// Returns total value of all books in inventory;
uint32_t cInventory::TotalValueOfInv()
{
	cBook* travel = m_head;
	uint32_t value = 0;
	while (travel != nullptr)
	{
		value += (travel->GetPrice() * travel->Get_Q());
		travel = travel->m_next;
	}
	return value;
}

// Returns price value of ISBN book
uint16_t cInventory::RetrievePrice(const string & ISBN) const
{
	return FindBookC(ISBN)->GetPrice();
}

// Displays price of ISBN book
void cInventory::DisplayPrice(const string & ISBN) const
{
	FindBookC(ISBN)->DisplayPrice();
}

// If ISBN not found, returns nullptr
const cBook * const cInventory::FindBookC(const string & ISBN) const
{
	cBook * travel = m_head;
	while (travel != nullptr && travel->m_ISBN != ISBN)
	{
		travel = travel->m_next;
	}
	return travel;
}

// Displays all info of all books in list
void cInventory::DisplayFullList() const
{
	cBook * travel = m_head;
	while (travel != nullptr)
	{
		travel->DisplayAll();
		travel = travel->m_next;
	}
}

// Private Function
// Returns nullptr if not found
cBook * cInventory::FindBook(const string & ISBN)
{
	cBook * travel = m_head;
	while (travel != nullptr && travel->m_ISBN != ISBN)
	{
		travel = travel->m_next;
	}
	return travel;
}

// Wrapper for cInventory SaveToFile function
void SaveInvToFile(cInventory & inv, const char * filename)
{
	ofstream file(filename);
	if (file.is_open())
	{
		inv.SaveToFile(file);
		file.close();
	}
	else
		cout << "Error: Unable to open " << filename << endl;
}

// Wrapper for cInventory LoadFromFile function
void LoadInvFromFile(cInventory & inv, const char * filename)
{
	ifstream file(filename);
	if (file.is_open())
	{
		inv.LoadFromFile(file);
		file.close();
	}
	else
		cout << "Error: Unable to open " << filename << endl;
}
