#include "Sample.h"
#include <iostream>
using std::cout;
using std::endl;


Sample::Sample()
	:m_age(0), m_shoeSize(0.0F)
{
	cout << "Sample Default CTOR Called" << endl;
}

Sample::Sample(short int age, float shoeSize)
	: m_age(age), m_shoeSize(shoeSize)
{
	cout << "Sample 2 Arg CTOR Called" << endl;
}


Sample::~Sample()
{
	cout << "Sample DTOR Called" << endl;
}

short int Sample::GetAge()
{
	return m_age;
}
