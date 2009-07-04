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
		Object& Find (Object const& object) const;
		void Withdraw (Object& object);
		Position& FindPosition (Object const& object) const;
		Object& operator [] (Position const& arg) const;
		void InsertAfter (Position const& arg, Object& object);
		void Withdraw (Position const& arg);

		friend class Pos;
};

class ListAsLinkedList::Pos : public Position
{
    ListAsLinkedList const& list;
    ListElement<Object*> const* element;
	public:
		Pos(ListAsLinkedList const&);
		Pos(ListAsLinkedList const&, ListElement<Object*> const*);
		virtual void Reset();
		virtual bool IsDone() const;
		virtual Object& operator*() const;
		virtual void operator++();
		friend class ListAsLinkedList;
};


#endif /* LISTASLINKEDLIST_H_ */
