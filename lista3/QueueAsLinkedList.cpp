/*
 * QueueAsLinkedList.cpp
 *
 *  Created on: 30/05/2009
 *      Author: fabricio
 */

#include "QueueAsLinkedList.h"

QueueAsLinkedList::QueueAsLinkedList () : list ()
{}

void QueueAsLinkedList::Purge ()
{
    if (IsOwner ())
    {
    	ListElement<Object*> const* ptr;

		for (ptr = list.Head (); ptr != 0; ptr = ptr->Next ())
		{
			delete ptr->Datum ();
		}
    }
    list.Purge ();
    count = 0;
}

QueueAsLinkedList::~QueueAsLinkedList ()
{
	Purge ();
}

Object& QueueAsLinkedList::Head () const
{
    if (count == 0)
    {
    	throw std::domain_error ("queue is empty");
    }
    return *list.First ();
}

void QueueAsLinkedList::Enqueue (Object& object)
{
    list.Append (&object);
    ++count;
}

Object& QueueAsLinkedList::Dequeue ()
{
    if (count == 0)
    {
    	throw std::domain_error ("queue is empty");
    }
    Object& result = *list.First ();
    list.Extract (&result);
    --count;
    return result;
}

void QueueAsLinkedList::Accept(Visitor &) const
{}

int QueueAsLinkedList::CompareTo(const Object &) const
{
	return 0;
}
