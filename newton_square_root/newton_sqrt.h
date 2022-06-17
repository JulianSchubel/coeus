/* **************************************
	Title:		Newton square root
	Author:		Julian Schubel
	Contact:

	History:	
	///:		25/01/2021
************************************** */

#ifndef NEWTON_SQRT_H
#define	NEWTON_SQRT_H

/*
	x: radicand
	n: number of iterations
 */
long double newton_sqrt(double x, int iterations)
{
    long double output = 1;
    int i = 0;

    while (i < iterations)
    {
        output = 0.5 * (output + x / output);
        i++;
    }
    return output;
}

#endif /* NEWTON_SQRT_H */
