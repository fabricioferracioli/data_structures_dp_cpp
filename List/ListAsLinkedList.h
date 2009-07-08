/*
 * ListAsLinkedList.h
 *
 *  Created on: 26/06/2009
 *      Author: fabricio
 */

#ifndef LISTASLINKEDLIST_H_
#define LISTASLINKEDLIST_H_

#include "OrderedList.h"
#include "../lista1/LinkedList.h"
#include "../Iterator/Position.h"

class ListAsLinkedList : public virtual OrderedList
{
	protected:
		LinkedList<Object*> linkedList;

		class Pos;
	public:
		ListAsLinkedList ();
		void Insert (Object&);
		Object& operator [] (unsigned int) const;
		bool IsMember (Object const&) const;
		Object& Find (Object const&) const;
		void Withdraw (Object&);
		Position& FindPosition (Object const&) const;
		Object& operator [] (Position const&) const;
		void InsertAfter (Position const&, Object&);
		void InsertBefore (Position const&, Object&);
		void Withdraw (Position const&);

		friend class Pos;
};

class ListAsLinkedList::Pos : public Position
{
    ListAsLinkedList const& list;
    ListElement<Object*> const* element;
	public:
		Pos(ListAsLinkedList const&);
		Pos(ListAsLinkedList const&, ListElement<Object*> const*);
		void Reset();
		bool IsDone() const;
		Object& operator*() const;
		void operator++();
		friend class ListAsLinkedList;
};


#endif /* LISTASLINKEDLIST_H_ */
