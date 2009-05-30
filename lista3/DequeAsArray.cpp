/*
 * DequeAsArray.cpp
 *
 *  Created on: 30/05/2009
 *      Author: fabricio
 */

#include "DequeAsArray.h"

Object& DequeAsArray::Head () const
{
	return QueueAsArray::Head ();
}

void DequeAsArray::EnqueueTail (Object& object)
{
	QueueAsArray::Enqueue (object);
}

Object& DequeAsArray::DequeueHead ()
{
	return QueueAsArray::Dequeue ();
}

Object& DequeAsArray::Tail () const
{
    if (count == 0)
    {
    	throw std::domain_error ("deque is empty");
    }
    return *array [tail];
}

void DequeAsArray::EnqueueHead (Object& object)
{
    if (count == array.Length ())
    {
    	throw std::domain_error ("deque is full");
    }
    if (head-- == 0)
    {
    	head = array.Length () - 1U;
    }
    array [head] = &object;
    ++count;
}


Object& DequeAsArray::DequeueTail ()
{
    if (count == 0)
    {
    	throw std::domain_error ("deque is empty");
    }
    Object& result = *array [tail];
    if (tail-- == 0)
    {
    	tail = array.Length () - 1U;
    }
    --count;
    return result;
}
