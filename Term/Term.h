/*
 * Term.h
 *
 *  Created on: 26/06/2009
 *      Author: fabricio
 */
template <class T>
int Compare(T a, T b)
{
    if (a == b)
        return 0;
    else if (a > b)
        return 1;
    else
        return -1;
}

#ifndef TERM_H_
#define TERM_H_

#include "../lista2/Object.h"
#include <stdexcept>

class Term : public Object
{
    double coefficient;
    unsigned int exponent;
	public:
		Term (double, unsigned int);
		int CompareTo (Object const&) const;
		void Differentiate ();
		unsigned int Coefficient () const;
		unsigned int Exponent () const;

		friend Term operator + (Term const&, Term const&);

		virtual HashValue Hash() const;
		virtual void Put(std::ostream &) const;
};

#endif /* TERM_H_ */
