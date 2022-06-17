#include "./counting.h"
#include <iostream>

int main(int argc, char * argv[])
{
	int n = 5;
	int r = 2;	

	std::cout << "n^r:\t" << nr(n,r) << std::endl;
	std::cout << "nPr:\t" << nPr(n,r) << std::endl;
	std::cout << "nCr:\t" << nCr(n,r) << std::endl;
	std::cout << "nMr:\t" << nMr(n,r) << std::endl;
	return 0;
}
