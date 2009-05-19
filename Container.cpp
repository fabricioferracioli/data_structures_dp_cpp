/*
 * Container.cpp
 *
 *  Created on: 18/05/2009
 *      Author: fabricio
 */

#include "Container.h"
#include "NullIterator.h"
#include "PuttingVisitor.h"

Iterator& Container::NewIterator () const
{
	return *new NullIterator ();
}

void Container::Put (std::ostream& s) const
{
    PuttingVisitor visitor (s);

    s << typeid (*this).name () << " {";
    Accept (visitor);
    s << "}";
}
