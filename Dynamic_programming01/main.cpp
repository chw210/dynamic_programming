#include <iostream>
#include "Rectangular.h"
using namespace std;

int main()
{
	Rectangular test1;
	test1.set_values(3, 4);
	cout << "Area is " << test1.area() <<endl;
	system("pause");
	return 0;
}