#pragma once
class Person
{
public:
	Person(int ID, char gender);
	Person();
	~Person();

	void SetID(int ID);
	void SetGender(char gender);
	int GetID();
	char GetGender();

private:
	int m_id;
	char m_gender;
};

