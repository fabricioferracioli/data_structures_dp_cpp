/*
 * QueueAsArray.h
 *
 *  Created on: 30/05/2009
 *      Author: fabricio
 */

#ifndef QUEUEASARRAY_H_
#define QUEUEASARRAY_H_

#include "Queue.h"
#include "../lista1/Array.h"

class QueueAsArray : public virtual Queue
{
	protected:
		Array<Object*> array;
		unsigned int head;
		unsigned int tail;
	public:
		QueueAsArray (unsigned int);
		void Purge ();
		Object& Head () const;
		void Enqueue (Object&);
		Object& Dequeue ();
		~QueueAsArray ();
};

#endif /* QUEUEASARRAY_H_ */
