/*
 * QueueAsArray.cpp
 *
 *  Created on: 30/05/2009
 *      Author: fabricio
 */

#include "QueueAsArray.h"

QueueAsArray::QueueAsArray (unsigned int size) : array (size), head (0), tail (size - 1U)
{}

void QueueAsArray::Purge ()
{
    if (IsOwner ())
    {
		for (unsigned int i = 0; i < count; ++i)
		{
			delete array [head];
			if (++head == array.Length ())
			{
				head = 0;
			}
		}
    }
    count = 0;
}

QueueAsArray::~QueueAsArray ()
{
	Purge ();
}

Object& QueueAsArray::Head () const
{
    if (count == 0)
    {
    	throw std::domain_error ("queue is empty");
    }
    return *array [head];
}

void QueueAsArray::Enqueue (Object& object)
{
    if (count == array.Length ())
    {
    	throw std::domain_error ("queue is full");
    }
    if (++tail == array.Length ())
    {
    	tail = 0;
    }
    array [tail] = &object;
    ++count;
}

Object& QueueAsArray::Dequeue ()
{
    if (count == 0)
    {
    	throw std::domain_error ("queue is empty");
    }
    Object& result = *array [head];

    if (++head == array.Length ())
    {
    	head = 0;
    }
    --count;
    return result;
}
