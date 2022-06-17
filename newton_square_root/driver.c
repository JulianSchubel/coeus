#include "./newton_sqrt.h"
#include <stdio.h>

int main(int argc, char * argv[])
{
	printf("%.15Lf", newton_sqrt(9, 5));
	return 0;
}
