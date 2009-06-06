/*
 * BagAsLinkedList.cpp
 *
 *  Created on: 06/06/2009
 *      Author: fabricio
 */

#include "BagAsLinkedList.h"

BagAsLinkedList::BagAsLinkedList() : list()
{}

int BagAsLinkedList::CompareTo(const Object& obj)const
{
    return 0;
}

void BagAsLinkedList::Purge ()
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

BagAsLinkedList::~BagAsLinkedList()
{
    Purge();
}

Iterator& BagAsLinkedList::NewIterator () const
{
    return *new Iter(*this);
}

void BagAsLinkedList::Accept (Visitor& visitor) const
{
    ListElement<Object*> const* ptr;

    for (ptr = list.Head (); ptr != 0 && !visitor.IsDone (); ptr = ptr->Next())
    {
        visitor.Visit (*ptr->Datum ());
    }
}

bool BagAsLinkedList::IsMember (Object const& object) const
{
    MatchingVisitor v(object);
	this->Accept(v);
	return v.IsDone();
}

void BagAsLinkedList::Insert (Object& object)
{
    list.Append (&object);
    ++count;
}

Object& BagAsLinkedList::Find (Object const& object) const
{
     MatchingVisitor v(object);
	 this->Accept(v);

	 if (v.IsDone())
	 {
		return *(v.Found());
	 }
	 else
	 {
		return NullObject::Instance();
	 }
}

void BagAsLinkedList::Withdraw (Object& object)
{
    if(count == 0)
        throw std::domain_error("list is empty");

    list.Extract(&object);

    --count;
}

BagAsLinkedList::Iter::Iter (BagAsLinkedList const& _bag) : bag (_bag)
{
    Reset ();
}

bool BagAsLinkedList::Iter::IsDone() const
{
    return position == 0;
}

Object& BagAsLinkedList::Iter::operator*()const
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

void BagAsLinkedList::Iter::operator++()
{
   if (position != 0)
   {
        position = position->Next ();
   }
}

void BagAsLinkedList::Iter::Reset()
{
    position = bag.list.Head ();
}
