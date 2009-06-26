/*
 * Polynomial.h
 *
 *  Created on: 26/06/2009
 *      Author: fabricio
 */

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include "../List/ListAsLinkedList.h"
#include "../Visitor/DifferentiatingVisitor.h"

class Polynomial : public ListAsLinkedList
{
	public:
		void Differentiate ();
		friend Polynomial operator + (Polynomial const&, Polynomial const&);
};

#endif /* POLYNOMIAL_H_ */
