/*
 * Deque.cpp
 *
 *  Created on: 30/05/2009
 *      Author: fabricio
 */

#include "Deque.h"

void Deque::Enqueue (Object& object)
{
	EnqueueTail (object);
}

Object& Deque::Dequeue ()
{
	return DequeueHead ();
}
