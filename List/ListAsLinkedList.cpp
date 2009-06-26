/*
 * ListAsLinkedList.cpp
 *
 *  Created on: 26/06/2009
 *      Author: fabricio
 */

#include "ListAsLinkedList.h"

ListAsLinkedList::ListAsLinkedList () : linkedList ()
{}

void ListAsLinkedList::Insert (Object& object)
{
    linkedList.Append (&object);
    ++count;
}

Object& ListAsLinkedList::operator [] (unsigned int offset) const
{
    if (offset >= count)
    {
    	throw std::out_of_range ("invalid offset");
    }

    unsigned int i = 0;
    ListElement<Object*> const* ptr = linkedList.Head ();

    while (i < offset && ptr != 0)
    {
    	ptr = ptr->Next ();
    	++i;
    }

    if (ptr == 0)
    {
    	throw std::logic_error ("should never happen");
    }
    return *ptr->Datum ();
}

bool ListAsLinkedList::IsMember (Object const& object) const
{
    ListElement<Object*> const* ptr;

    for (ptr = linkedList.Head (); ptr != 0; ptr = ptr->Next ())
	if (ptr->Datum () == &object)
	    return true;
    return false;
}

Object& ListAsLinkedList::Find (Object const& object) const
{
    ListElement<Object*> const* ptr;

    for (ptr = linkedList.Head (); ptr != 0; ptr = ptr->Next ())
	if (*ptr->Datum () == object)
	    return *ptr->Datum ();
    return NullObject::Instance ();
}

void ListAsLinkedList::Withdraw (Object& object)
{
    if (count == 0)
    {
    	throw std::domain_error ("list is empty");
    }
    linkedList.Extract (&object);
    --count;
}

Position& ListAsLinkedList::FindPosition (Object const& object) const
{
    ListElement<Object*> const* ptr = linkedList.Head ();
    while (ptr != 0 && *ptr->Datum () != object)
    {
    	ptr = ptr->Next ();
    }
    return *new Pos (*this, ptr);
}

Object& ListAsLinkedList::operator [] (Position const& arg) const
{
    Pos const& position = dynamic_cast<Pos const&> (arg);

    if (&position.list != this || position.element == 0)
    {
    	throw std::invalid_argument ("invalid position");
    }
    return *position.element->Datum ();
}

void ListAsLinkedList::InsertAfter (Position const& arg, Object& object)
{
    Pos const& position = dynamic_cast<Pos const&> (arg);

    if (&position.list != this || position.element == 0)
    {
    	throw std::invalid_argument ("invalid position");
    }
    linkedList.InsertAfter (position.element, &object);
    ++count;
}

void ListAsLinkedList::Withdraw (Position const& arg)
{
    Pos const& position = dynamic_cast<Pos const&> (arg);

    if (count == 0)
    {
    	throw std::domain_error ("list is empty");
    }

    if (&position.list != this || position.element == 0)
    {
    	throw std::invalid_argument ("invalid position");
    }

    linkedList.Extract (position.element->Datum ());
    --count;
}
