#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <iomanip>
using std::setw;
using std::setprecision;

int main()
{
	const int CALC_NUM = 8;
	int first, second, next;
	double ratio;
	bool done = false;

	while (!done)
	{
		cout << "What is the first number you wish to start with?\n"
			<< "(enter -99 to exit) ";
		cin >> first;
		if (first == -99)
			done = true;
		else
		{
			cout << "What is the second number you wish to start with?\n"
				<< "(enter -99 to exit) ";
			cin >> second;
			if (second == -99)
				done = true;
			else
			{
				for (int ii = 0; ii < CALC_NUM; ii++)
				{
					ratio = static_cast<double>(second) / static_cast<double>(first);
					cout << setprecision(10) << first << " " << second << " " << ratio << endl;
					next = first + second;
					first = second;
					second = next;
				}
			}
		}
	}
	return 0;
}