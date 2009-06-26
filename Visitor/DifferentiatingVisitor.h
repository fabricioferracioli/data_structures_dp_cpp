/*
 * DifferentiatingVisitor.h
 *
 *  Created on: 26/06/2009
 *      Author: fabricio
 */

#ifndef DIFFERENTIATINGVISITOR_H_
#define DIFFERENTIATINGVISITOR_H_

#include "../lista2/Visitor.h"
#include "../Term/Term.h"

class DifferentiatingVisitor : public Visitor
{
	public:
		void Visit (Object& object)
		{
			Term& term = dynamic_cast<Term&> (object);
			term.Differentiate ();
		}
};

#endif /* DIFFERENTIATINGVISITOR_H_ */
