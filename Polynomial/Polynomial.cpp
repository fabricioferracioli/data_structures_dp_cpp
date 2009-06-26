/*
 * Polynomial.cpp
 *
 *  Created on: 26/06/2009
 *      Author: fabricio
 */

#include "Polynomial.h"

void Polynomial::Differentiate ()
{
    DifferentiatingVisitor visitor;
    Accept (visitor);
    Object& zeroTerm = Find (Term (0, 0));

    if (!zeroTerm.IsNull ())
    {
		Withdraw (zeroTerm);
		delete &zeroTerm;
    }
}

Polynomial operator + (Polynomial const& arg1, Polynomial const& arg2)
{
    Polynomial result;
    Iterator& pos1 = arg1.NewIterator ();
    Iterator& pos2 = arg2.NewIterator ();

    while (!pos1.IsDone () && !pos2.IsDone ())
    {
		Term const& term1 = dynamic_cast<Term const&> (*pos1);
		Term const& term2 = dynamic_cast<Term const&> (*pos2);
		if (term1.Exponent () < term2.Exponent ())
		{
			result.Insert (*new Term (term1));
			++pos1;
		}
		else if (term1.Exponent () > term2.Exponent ())
		{
			result.Insert (*new Term (term2));
			++pos2;
		}
		else
		{
			Term sum = term1 + term2;
			if (sum.Coefficient () != 0)
			result.Insert (*new Term (sum));
			++pos1;
			++pos2;
		}
    }
    while (!pos1.IsDone ())
    {
		Term const& term1 = dynamic_cast<Term const&> (*pos1);
		result.Insert (*new Term (term1));
		++pos1;
    }
    while (!pos2.IsDone ())
    {
		Term const& term2 = dynamic_cast<Term const&> (*pos2);
		result.Insert (*new Term (term2));
		++pos2;
    }
    delete &pos1;
    delete &pos2;
    return result;
}
