#include "polynomial_t.h"

//Constructors
polynomial_t::polynomial_t(int degree) : array_list_t(degree)
{
	length = degree;
	for( int i = 0; i < capacity; ++i )
	{
		array[i] = 0;
	}
}

//Member functions
int polynomial_t::min(int x, int y) const
{
	if( x < y )
	{
		return x;
	}
	return y;
}

int polynomial_t::max(int x, int y) const
{
	if( x > y )
	{
		return x;
	}
	return y;
}

//Overloaded operator functions
polynomial_t polynomial_t::operator+ (const polynomial_t& obj) const
{
	int size = max(length, obj.length);

	//Create a polynomial type large enough to hold the sum of two polynomials
	polynomial_t temp(size);
	
	//Sum the range for which both polynomials could have terms
	for( int i = 0; i < min(length, obj.length); ++i )
	{
		temp.array[i] = array[i] + obj.array[i];	
	}
	
	//Sum the range for which one polynomial has terms of greater degree than the other
	for( int i = min(length, obj.length); i < size; ++i )
	{
		if( length > obj.length )
		{
			temp.array[i] = array[i];
		}
		else
		{
			temp.array[i] = obj.array[i];
		}
	}
	return temp;
}

polynomial_t polynomial_t::operator- (const polynomial_t& obj) const
{
	int size = max(length, obj.length);

	//Create a polynomial type large enough to hold the sum of two polynomials
	polynomial_t temp(size);
	
	//Sum the range for which both polynomials could have terms
	for( int i = 0; i < min(length, obj.length); ++i )
	{
		temp.array[i] = array[i] - obj.array[i];	
	}
	
	//Sum the range for which one polynomial has terms of greater degree than the other
	for( int i = min(length, obj.length); i < size; ++i )
	{
		if( length > obj.length )
		{
			temp.array[i] = array[i];
		}
		else
		{
			temp.array[i] = obj.array[i];
		}
	}
	return temp;
}

polynomial_t polynomial_t::operator* (const polynomial_t& obj) const
{
	int size = length + obj.length - 1; //Maximum possible degree + 1 for constant. Note subtraction as constant included in each length.
	polynomial_t temp(size);
	for(int i = 0; i < size; ++i)	//For every degree starting from 0 (the constant term) in the polynomial product.
	{
		int coefficient = 0;
		for(int a = 0, b = i; b >= 0; ++a, --b) //a and b indicate the degree of the monomial terms for each polynomial object.
		{
			if( a + b == i ) //Include only those coefficient products for which the product of their variables are of the correct degree
			{
				if(length > obj.length)	//Determine which array is longest and therefore contains the monomial term with largest degree.
				{
					(a >= obj.length || b >= length) ? coefficient : coefficient += array[b] * obj.array[a]; 	//consider non-existent a or b as 0
				}
				else
				{
					(a >= length || b >= obj.length) ? coefficient : coefficient += array[a] * obj.array[b];	//consider non-existent a or b as 0
				}
			}
		}	 
		temp.array[i] = coefficient;
	}
	return temp;
}

double polynomial_t::operator() (double x)
{
	double value = 0;
	for( int i = 0; i < length; ++i )
	{
		if(array[i] != 0)
		{
			value = value + (array[i] * pow(x,i));
		}
	}	
	return value;
}

//Friend Functions
std::ostream& operator<< (std::ostream& outs, const polynomial_t& obj)
{
	char sign = '+';
	for( int i = obj.length-1; i >= 0; --i )
	{
		if( obj.array[i] != 0 )
		{
			(obj.array[i] < 0) ? sign = '\0' : sign = '+';
			if( i != 0 )
			{
				outs << sign << obj.array[i] << "x^" << i;
			}
			else
			{
				outs << sign << obj.array[i];
			}
		}
	}
	return outs;
}

std::istream& operator>> (std::istream& ins, polynomial_t& obj)
{
	int coefficient = 0;
	char c = 0;
	while( ins >> coefficient )
	{
		if ( (c = ins.get()) == '\n' )
		{
			obj.insert(0, coefficient); //The underlying array-based-list shifts existing values up one index.
			break;
		}
		else
		{
			ins.putback(c);
			obj.insert(0, coefficient);
		}
	}
	return ins;
}
