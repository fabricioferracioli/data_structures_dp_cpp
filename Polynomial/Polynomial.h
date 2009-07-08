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
	int CompareTo (Object const&) const;
	public:
		void Differentiate ();
		friend Polynomial operator + (Polynomial const&, Polynomial const&);

		/* listaslinkedlist */
//		Object& operator [] (unsigned int) const;
//		bool IsMember (Object const&) const;
//		Object& Find (Object const&) const;
//		void Withdraw (Object&);
//		Position& FindPosition (Object const&) const;
//		Object& operator [] (Position const&) const;
//		void InsertAfter (Position const&, Object& );
//		void InsertBefore (Position const&, Object&);
//		void Withdraw (Position const&);

		/* container */
//		unsigned int Count () const;
//		bool IsEmpty () const;
//		bool IsFull () const;
//		HashValue Hash () const;
//		void Put (std::ostream&) const;
//		Iterator& NewIterator () const;

		void Purge ();
		void Accept (Visitor&) const;

};

#endif /* POLYNOMIAL_H_ */
