#include <iostream>
#include <stdlib.h>

#include "Sem2_Lab8.hpp"
using namespace std;

int main()
{
	Complex<double> num1(1, 5);
	Complex<double> num2(3, 4);
	cout << "num1 += num2\n" << (num1 += num2) << endl;
	cout << "num1 *= num2\n" << (num1 *= num2) << endl;
	cout << "num1 *= 2\n" << (num1 *= 2) << endl;
	cout << "num1 /= 10\n" << (num1 /= 10) << endl;

	cout << "num1 == num1" << endl;
	if (num1 == num1)
		cout << "works" << endl;
	return 0;
}
