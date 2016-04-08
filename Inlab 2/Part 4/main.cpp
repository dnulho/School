#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <array>
using std::array;
#include <vector>
using std::vector;

int main()
{
	vector <int> vec(5);
	array <int, 5> arr;

	cout << arr.size() << endl;
	cout << &arr.front() << endl;
	cout << arr.back() << endl;

	cout << vec.capacity() << endl;
	cout << vec.empty() << endl;
	cout << vec.size() << endl;
	return 0;
}
