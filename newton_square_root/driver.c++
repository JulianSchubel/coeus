#include "./newton_sqrt.h"
#include <iostream>

int main(int argc, char * argv[])
{
	std::cout.setf(std::ios::fixed);
	std::cout.setf(std::ios::showpoint);
	std::cout.precision(15);
	std::cout <<  newton_sqrt(9, 5) << std::endl;
	return 0;
}
