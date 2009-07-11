/*
 * QueueAsLinkedList.h
 *
 *  Created on: 30/05/2009
 *      Author: fabricio
 */

#ifndef QUEUEASLINKEDLIST_H_
#define QUEUEASLINKEDLIST_H_

#include "Queue.h"
#include "../lista1/LinkedList.h"

class QueueAsLinkedList : public virtual Queue
{
	protected:
		LinkedList<Object*> list;
	public:
		QueueAsLinkedList ();
		void Purge ();
		Object& Head () const;
		void Enqueue (Object&);
		Object& Dequeue ();
		~QueueAsLinkedList ();
		void Accept(Visitor &) const;
		int CompareTo(const Object &) const;
};

#endif /* QUEUEASLINKEDLIST_H_ */
