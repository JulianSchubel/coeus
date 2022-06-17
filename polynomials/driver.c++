#include <iostream>
#include "polynomial_t.h"

int main(int argc, char * argv[])
{
	polynomial_t polynomial_a(1);
	std::cout << "Enter a sequence of space delimited co-efficients: ";
	std::cin >> polynomial_a;
	std::cout << polynomial_a << std::endl;

	polynomial_t polynomial_b(3);
	polynomial_b.insert(0,1);
	polynomial_b.insert(1,1);
	polynomial_b.insert(2,1);
	
	std::cout << polynomial_a * polynomial_b << std::endl;
	return 0;
}
