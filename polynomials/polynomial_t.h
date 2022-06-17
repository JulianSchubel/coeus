#ifndef POLYNOMIAL_T_H
#define POLYNOMIAL_T_H

#include <iostream>
#include <cstdint>
#include <cmath>
#include "array_list_t.h" //Header only implementation of array based list

class polynomial_t : public array_list_t<double>
{
	//Friend functions
	friend std::ostream& operator<< (std::ostream&, const polynomial_t&);
	/*
		Outputs the polynomial in standard form.
	*/
	friend std::istream& operator>> (std::istream&, polynomial_t&); 

	public:
		//Constructors
		polynomial_t(int degree = 1);

		//Member functions
		int min(int x, int y) const;
		int max(int x, int y) const;

		//Overloaded operator functions
		polynomial_t operator +(const polynomial_t&) const;
		/*
			Note all such terms a0 are to be interpretted as a sub 0
			(a0 + b0) + (a1x^1 + b1x^1) ... (anx^n + bnx^n)
			Where a and b are the coefficients.
			If some a or b does not exist it is taken to be 0.
			Note that the degree of a zero polynomial is not treated as undefined, but as zero.

		*/

		polynomial_t operator -(const polynomial_t&) const;
		/*
			Note all such terms a0 are to be interpretted as a sub 0
			(a0 - b0) + (a1x^1 - b1x^1) ... (anx^n - bnx^n)
			Where a and b are the coefficients.
			If some a or b does not exist it is taken to be 0.
			Note that the degree of a zero polynomial is not treated as undefined, but as zero.

		*/

		polynomial_t operator *(const polynomial_t&) const;
		/*
			Note all such terms a0 are to be interpretted as a sub 0
			c0 + c1x^1 ... cnx^n
			where cn = a0*bn + a1*bn-1 + ... + an*b0 //I.e. the sum of coefficients for which some a or b exists.
			Where a and b are the coefficients.
			Where n is the degree of the term being considered.
			If some a or b does not exist it is taken to be 0.
			Note that the degree of a zero polynomial is not treated as undefined, but as zero.

		*/

		double operator() (double x);
		/*
			Evaluates the polynomial for x.
		*/
	
		
	protected:
	private:
};

#include "polynomial_t.c++"
#endif //POLYNOMIAL_T_H

