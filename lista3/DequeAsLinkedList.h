/*
 * DequeAsLinkedList.h
 *
 *  Created on: 30/05/2009
 *      Author: fabricio
 */

#ifndef DEQUEASLINKEDLIST_H_
#define DEQUEASLINKEDLIST_H_

#include "Deque.h"
#include "QueueAsLinkedList.h"

class DequeAsLinkedList : public Deque, public QueueAsLinkedList
{
	public:
		DequeAsLinkedList ();
		Object& Head () const;
		void EnqueueTail (Object&);
		Object& DequeueHead ();
		Object& Tail () const;
		void EnqueueHead (Object&);
		Object& DequeueTail ();

		virtual void Enqueue(Object&);
		virtual Object& Dequeue();
		void Accept(Visitor &) const;
		int CompareTo(const Object &) const;

		void Purge ();
};

#endif /* DEQUEASLINKEDLIST_H_ */
