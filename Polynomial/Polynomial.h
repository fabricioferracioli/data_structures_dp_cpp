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

		virtual int CompareTo(const Object&) const;
		virtual void Purge();
		virtual void Accept(Visitor &) const;
		virtual void Insert(Object &);
		virtual void Withdraw(Object &);
		virtual Object& Find(const Object&) const;
		virtual bool IsMember(const Object&) const;
		virtual Object& operator[](unsigned int) const;
		virtual Object& operator[](const Position&) const;
		virtual Position& FindPosition(const Object&) const;
		virtual void Withdraw(const Position&);
		virtual void InsertAfter(const Position&, Object&);
		virtual void InsertBefore(const Position&, Object&);
};

#endif /* POLYNOMIAL_H_ */
