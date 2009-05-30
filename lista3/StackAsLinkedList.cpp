/*
 * StackAsLinkedList.cpp
 *
 *  Created on: 30/05/2009
 *      Author: fabricio
 */

#include "StackAsLinkedList.h"

StackAsLinkedList::StackAsLinkedList () : list ()
{}

void StackAsLinkedList::Purge ()
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

StackAsLinkedList::~StackAsLinkedList ()
{
	Purge ();
}

void StackAsLinkedList::Push (Object& object)
{
    list.Prepend (&object);
    ++count;
}

Object& StackAsLinkedList::Pop ()
{
    if (count == 0)
    {
    	throw std::domain_error ("stack is empty");
    }
    Object& result = *list.First ();
    list.Extract (&result);
    --count;
    return result;
}

Object& StackAsLinkedList::Top () const
{
    if (count == 0)
    {
    	throw std::domain_error ("stack is empty");
    }
    return *list.First ();
}

void StackAsLinkedList::Accept (Visitor& visitor) const
{
    ListElement<Object*> const* ptr;

    for (ptr = list.Head (); ptr != 0 && !visitor.IsDone (); ptr = ptr->Next ())
    {
    	visitor.Visit (*ptr->Datum ());
    }
}

StackAsLinkedList::Iter::Iter (StackAsLinkedList const& _stack) : stack (_stack)
{
	Reset ();
}

bool StackAsLinkedList::Iter::IsDone () const
{
	return position == 0;
}

Object& StackAsLinkedList::Iter::operator * () const
{
    if (position != 0)
    {
    	return *position->Datum ();
    }
    else
    {
    	return NullObject::Instance ();
    }
}

void StackAsLinkedList::Iter::operator ++ ()
{
    if (position != 0)
    {
    	position = position->Next ();
    }
}

void StackAsLinkedList::Iter::Reset ()
{
	position = stack.list.Head ();
}
