#include <iostream>
using std::cout;
using std::cin;
using std::endl;

struct Point
{
	int x;
	int y;
};

int FindMax(int first, int second);
Point FindMax(Point first, Point second);
void PrintPoint(const Point& point);

int main()
{
	int a, b = 0;
	Point c, d;
	cout << "Please input first value: ";
	cin >> a;
	cout << "Please input second value: ";
	cin >> b;
	cout << "The larger value is " << FindMax(a, b) << endl;

	cout << "Please input first x value: ";
	cin >> c.x;
	cout << "Please input first y value: ";
	cin >> c.y;
	cout << "Please input second x value: ";
	cin >> d.x;
	cout << "Please input second y value: ";
	cin >> d.y;

	cout << "The max of ";
	PrintPoint(c);
	cout << " and ";
	PrintPoint(d);
	cout << " is ";
	PrintPoint(FindMax(c, d));
	cout << endl;
	return 0;
}

int FindMax(int first, int second)
{
	int larger = first;
	if (first <= second)
		larger = second;
	return larger;
}

Point FindMax(Point first, Point second)
{
	Point max;
	max.x = FindMax(first.x, second.x);
	max.y = FindMax(first.y, second.y);
	return max;
}

void PrintPoint(const Point& point)
{
	cout << "[" << point.x << ", " << point.y << "]";
}