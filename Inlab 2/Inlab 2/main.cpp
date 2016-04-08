#include<iostream>
using std::endl;
using std::cout;
using std::cin;


void Find(const int* arr, const int length, int& max, int& min);
void Swap(int& a, int& b);
void Sort(int& x, int& y, int& z);
void PrintThem(int start, int end, int perLine = 5);

int main()
{
	const int array[] = { 5, -6, 21, 15, -8 };
	int sortarr[] = { 4,5,6 };
	/* JUST FOR FUN PRINT OUT THE CONTENTS OF THIS ARRAY RIGHT HERE
	USING A ‘RANGE BASED FOR LOOP’ AS DISCUSSED IN CLASS – JUST
	PRINT EACH NUMBER OF THE ARRAY ON A SEPARATE LINE */
	Sort(sortarr[0],sortarr[1],sortarr[2]);

	for (int ii = 0; ii < sizeof(sortarr) / sizeof(sortarr[0]); ii++)
	{
		cout << sortarr[ii] << endl;
	}

	for (int ii = 0; ii < sizeof(array) / sizeof(array[0]); ii++)
	{
		cout << array[ii] << endl;
	}
	
	const int length = sizeof(array) / sizeof(*array);

	/* ADD ANOTHER RANGE BASED LOOP THAT BUMPS EACH
	ELEMENT OF THE ARRAY BY 1  - AND AGAIN PRINT OUT THE RESULTS */
	for (int ii = 0; ii < sizeof(array) / sizeof(array[0]); ii++)
	{
		cout << (array[ii]+1) << endl;
	}

	int max;
	auto  min(0);  // what is the deal with auto?  Will it work – be able to explain it
	Find(array, length, max, min);
	cout << "max = " << max << endl;
	cout << "min = " << min << endl;
	bool done = false;
	while (!done)
	{
		int start, end, line;
		cout << "What is the starting number: ";
		cin >> start;
		cout << "What is the ending number: ";
		cin >> end;
		cout << "How many number per line: ";
		cin >> line;
		if (start == -1 || end == -1 || line == -1)
		{
			done = true;
		}
		else
		{
			PrintThem(start, end, line);
			cout << endl << endl << endl;
			PrintThem(start, end);
		}

	}
	return 0;
}

void Find(const int* arr, const int length, int& max, int& min)
{
	min = arr[0];
	max = arr[0];
	for (int ii = 0; ii < length; ii++)
	{
		if (min > arr[ii])
			min = arr[ii];
		if (max < arr[ii])
			max = arr[ii];
	}
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Sort(int& x, int& y, int& z)
{
	if (x < y)
		Swap(x, y);
	if (y < z)
	{
		Swap(y, z);
		if (x < y)
			Swap(x, y);
	}
}

void PrintThem(int start, int end, int perLine)
{
	int line = 0;
	for (int ii = start; ii <= end; ii++)
	{
		cout << ii << " ";
		line++;	
		if (line == perLine)
		{
			line = 0;
			cout << "\n";
		}
	}
}