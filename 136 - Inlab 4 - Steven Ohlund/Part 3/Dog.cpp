#include "Dog.h"

int Dog::m_counter = 0;
Dog::Dog(char name[20], char * breed, double weight)
	: m_name(), m_breed(nullptr), m_weight(weight)
{
	strcpy(m_name, name);
	
	m_breed = new char[strlen(breed) + 1];
	strcpy(m_breed, breed);
	
	m_counter++;
}

Dog::Dog(const Dog & copy)
	:m_name(), m_breed(nullptr), m_weight(copy.m_weight)
{
	strcpy(m_name, copy.m_name);
	
	m_breed = new char[strlen(copy.m_breed) + 1];
	strcpy(m_breed, copy.m_breed);
	
	this->m_weight = copy.m_weight;

	m_counter++;
}

Dog & Dog::operator=(Dog & rhs)
{
	strcpy(this->m_name, rhs.m_name);
	
	delete[] this->m_breed;
	this->m_breed = new char[strlen(rhs.m_breed) + 1];
	strcpy(m_breed, rhs.m_breed);

	this->m_weight = rhs.m_weight;
	return *this;
}

void Dog::Display()
{
	std::cout << this->m_name
		<< "\n\t" << (this->m_breed ? this->m_breed : "NULL")
		<< "\n\t" << this->m_weight << std::endl;
}
