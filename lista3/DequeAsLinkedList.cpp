/*
 * DequeAsLinkedList.cpp
 *
 *  Created on: 30/05/2009
 *      Author: fabricio
 */

#include "DequeAsLinkedList.h"

Object& DequeAsLinkedList::Head () const
{
	return QueueAsLinkedList::Head ();
}

void DequeAsLinkedList::EnqueueTail (Object& object)
{
	QueueAsLinkedList::Enqueue (object);
}

Object& DequeAsLinkedList::DequeueHead ()
{
	return QueueAsLinkedList::Dequeue ();
}

Object& DequeAsLinkedList::Tail () const
{
    if (count == 0)
    {
    	throw std::domain_error ("deque is empty");
    }
    return *list.Last ();
}

void DequeAsLinkedList::EnqueueHead (Object& object)
{
    list.Prepend (&object);
    ++count;
}

Object& DequeAsLinkedList::DequeueTail ()
{
    if (count == 0)
    {
    	throw std::domain_error ("deque is empty");
    }
    Object& result = *list.Last ();
    list.Extract (&result);
    --count;
    return result;
}

void DequeAsLinkedList::Enqueue (Object& object)
{
	EnqueueTail (object);
}

Object& DequeAsLinkedList::Dequeue ()
{
	return DequeueHead ();
}

void DequeAsLinkedList::Purge()
{}

void DequeAsLinkedList::Accept(Visitor &) const
{}


int DequeAsLinkedList::CompareTo(const Object &) const
{
	return 0;
}
