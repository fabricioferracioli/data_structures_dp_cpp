/*
 * StackAsLinkedList.h
 *
 *  Created on: 30/05/2009
 *      Author: fabricio
 */

#ifndef STACKASLINKEDLIST_H_
#define STACKASLINKEDLIST_H_

#include "Stack.h"
#include "../lista1/LinkedList.h"
#include "../lista2/NullObject.h"

class StackAsLinkedList : public Stack
{
		LinkedList<Object*> list;

		class Iter;
	public:
		StackAsLinkedList ();
		void Purge ();
		void Push (Object&);
		Object& Pop ();
		Object& Top () const;
		void Accept (Visitor&) const;
		virtual int CompareTo(const Object&) const;
		~StackAsLinkedList ();
		friend class Iter;
};

class StackAsLinkedList::Iter : public Iterator
{
		StackAsLinkedList const& stack;
		ListElement<Object*> const* position;
	public:
		Iter (StackAsLinkedList const&);
		bool IsDone () const;
		Object& operator * () const;
		void operator ++ ();
		void Reset ();
};

#endif /* STACKASLINKEDLIST_H_ */
