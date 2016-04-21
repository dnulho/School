#include "Dog.h"

int main()
{
	std::cout << "Total Number of dogs in system: " << Dog::getCounter() << std::endl;
	Dog d1;
	Dog d2("Spot", "German Shepard", 54.7);
	Dog d3(d2);
	d3 = Dog("Shadow", "Black Lab", 38.2);
	std::cout << "Total Number of dogs in system: " << Dog::getCounter() << std::endl;
	d1.Display();
	d2.Display();
	d3.Display();
	return 0;
}