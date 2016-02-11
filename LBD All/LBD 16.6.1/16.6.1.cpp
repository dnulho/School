#include <iostream>																																
using std::cout;
using std::cin;
using std::endl;

double MyPow(double power, int base);

int main()
{
	double base = 3;
	int power = -2;

	cout << MyPow(base, power) << endl;
	system("pause");
	return 0;
}

double MyPow(double base, int power)
{
	double temp = -1;
	bool recipricol = false;
	
	if (power < 0)
	{
		recipricol = true;
		power *= -1;
	}
	if (power == 0)
		temp = 1;

	if (power == 1)
		temp = base;
	else if (power >= 1)
	{
		power--;
		temp = MyPow(base, power);
		temp *= base;
	}

	if (recipricol)
	{
		temp = 1 / temp;
	}
	return temp;
}