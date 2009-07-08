/*
 * Term.cpp
 *
 *  Created on: 26/06/2009
 *      Author: fabricio
 */

#include "Term.h"

Term::Term (double _coefficient, unsigned int _exponent) : coefficient (_coefficient), exponent (_exponent)
{}

int Term::CompareTo (Object const& object) const
{
    Term const& term = dynamic_cast<Term const&> (object);
    if (exponent == term.exponent)
    {
    	return ::Compare (coefficient, term.coefficient);
    }
    else
    {
    	return exponent - term.exponent;
    }
}

void Term::Differentiate ()
{
    if (exponent > 0)
    {
		coefficient *= exponent;
		exponent -= 1;
    }
    else
    	coefficient = 0;
}

unsigned int Term::Coefficient () const
{
	return coefficient;
}

unsigned int Term::Exponent () const
{
	return exponent;
}

Term operator + (Term const& arg1, Term const& arg2)
{
    if (arg1.exponent != arg2.exponent)
    {
    	throw std::domain_error ("unequal exponents");
    }
    return Term (arg1.coefficient + arg2.coefficient,	arg1.exponent);
}

HashValue Term::Hash() const
{
	return 0;
}

void Term::Put(std::ostream &) const
{}
