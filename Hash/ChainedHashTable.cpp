/*
 * ChainedHashTable.cpp
 *
 *  Created on: 07/07/2009
 *      Author: fabricio
 */

#include "ChainedHashTable.h"

ChainedHashTable::ChainedHashTable (unsigned int _length) : HashTable (_length), array (_length)
{}

void ChainedHashTable::Purge ()
{
    for (unsigned int i = 0; i < length; ++i)
    {
		if (IsOwner ())
		{
			ListElement<Object*> const* ptr;

			for (ptr = array [i].Head ();
				ptr != 0; ptr = ptr->Next ())
			delete ptr->Datum ();
		}
		array [i].Purge ();
    }
    count = 0;
}

ChainedHashTable::~ChainedHashTable ()
{
	Purge ();
}

void ChainedHashTable::Insert (Object& object)
{
    array [H (object)].Append (&object);
    ++count;
}

void ChainedHashTable::Withdraw (Object& object)
{
    array [H (object)].Extract (&object);
    --count;
}

Object& ChainedHashTable::Find (Object const& object) const
{
    ListElement<Object*> const* ptr;

    for (ptr = array [H (object)].Head ();	ptr != 0; ptr = ptr->Next())
    {
    	if (object == *ptr->Datum ())
    		return *ptr->Datum ();
    }
    return NullObject::Instance ();
}
