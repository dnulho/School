/*****************************************************************************************************
*			Code Sample - check on CONST's and clean-up my mess!
*	1) Review briefly this piece of code.  Take a second and focus on 1 - 5 below!  Indicate if
* 	each of those FIVE lines will work as one might think BEFORE you run the code
*   	2)  COPY the code into VS and run it to do the proof.  Feel free to format, etc as desired.
* 	Maybe it will work ?
*	3)  IF the code for some reason does NOT work, please fix as needed.  YOU DO NOT have to print
*	 this out! Just demo to us–AFTER it works. All it needs to do is print out the values of z,y,t 
****************************************************************************************************/
#include <iostream>
using std::cout;

class Test
{
private:
	const int z = 999;  // 1.  OK?  Work???
	int y;		// 2.  OK? Prata said ok - is it supported by compiler???
	const int t;		// 3.  OK?  Think about our discussion on WEDNESDAY in class!?!?!

public:
	Test(int a = 234)
		:t(a)
	{
		y = 555;	// 5.  OK??? Will it work?  
	}

	void getem()
	{
		cout << " Here is z:"  << z << " y: " << y << " t : " << t;
	}
};
	// ALL WARNINGS ARE TO BE REMOVED - GET THIS THING FORMATTED CORRECTLY!
int main()
{
	Test t1(5);
	t1.getem();
	Test t2;
	t2.getem();

	return 0;
}