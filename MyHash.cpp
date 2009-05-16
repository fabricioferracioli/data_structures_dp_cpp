/*
 * Hash.cpp
 *
 *  Created on: 15/05/2009
 *      Author: fabricio
 */

#include "MyHash.h"

MyHash::MyHash() {
	// TODO Auto-generated constructor stub

}

HashValue MyHash::Hash (char c)
{
	return abs (c);
}

HashValue MyHash::Hash (int i)
{
	return abs (i);
}

HashValue MyHash::Hash (double d)
{
	if (d == 0)
	return 0;
	else
	{
		int exponent;
		double mantissa = frexp (d, &exponent);
		return (2 * fabs (mantissa) - 1) * ~0U;
	}
}
unsigned int const shift = 6;
HashValue const mask = ~0U << (sizeof (HashValue) - shift);

HashValue MyHash::Hash (std::string const& s)
{
	HashValue result = 0;
	for (unsigned int i = 0; s [i] != 0; ++i)
	result = (result & mask) ^ (result << shift) ^ s [i];
	return result;
}

MyHash::~MyHash() {
	// TODO Auto-generated destructor stub
}
