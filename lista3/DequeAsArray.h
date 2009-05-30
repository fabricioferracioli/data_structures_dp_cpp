/*
 * DequeAsArray.h
 *
 *  Created on: 30/05/2009
 *      Author: fabricio
 */

#ifndef DEQUEASARRAY_H_
#define DEQUEASARRAY_H_

#include "Deque.h"
#include "QueueAsArray.h"

class DequeAsArray : public Deque, public QueueAsArray
{
	public:
		DequeAsArray (unsigned int);
		Object& Head () const;
		void EnqueueTail (Object&);
		Object& DequeueHead ();
		Object& Tail () const;
		void EnqueueHead (Object&);
		Object& DequeueTail ();

		virtual void Enqueue(Object&) = 0;
		virtual Object& Dequeue() = 0;
};

#endif /* DEQUEASARRAY_H_ */
