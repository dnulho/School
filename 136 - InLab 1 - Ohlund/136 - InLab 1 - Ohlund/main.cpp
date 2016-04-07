#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	const int SIZE = 4;
	int value = 0;
	bool done = false;
	int* arr = new int[SIZE];
	char Continue = '\0';

	while (!done)
	{
		for (int ii = 0; ii < SIZE; ii++) // ii should only exist within the for loop it is in, and should disapper when the loop ends.
		{
			cout << "Please insert a numeric value\n";
			cin >> value;
			*(arr + ii) = value;
		}
		for (int ii = 0; ii < SIZE; ii++)
		{
			cout << "[" << *(arr + ii) << "] ";
		}
		//cout << ii; // ii is invalid here, so the compiler is scoping correctly, keeping ii within the for loop as intended.
		cout << endl;
		cout << "Do you want to continue running this program? (Y or N)";
		cin >> Continue;
		switch (Continue)
		{
		case 'y':
		case 'Y':
			cout << "Continuing program" << endl;
			break;
		case 'n':
		case 'N':
			cout << "Exiting Program, Goodbye" << endl;
			done = true;
			break;
		default:
			cout << "Error: Invalid input, Continuing program" << endl;
			break;
		}
	}
	delete[] arr;
	arr = nullptr;
	return 0;
}