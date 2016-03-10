#ifndef SAMPLE_H
#define SAMPLE_H
class Sample
{
public:
	Sample();
	Sample(short int age, float shoeSize = 8.0F);
	~Sample();

	short int GetAge();

private:
	short int m_age;
	float m_shoeSize;
};
#endif