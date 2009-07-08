/*
 * ChainedScatterTable.cpp
 *
 *  Created on: 07/07/2009
 *      Author: fabricio
 */

#include "ChainedScatterTable.h"

ChainedScatterTable::Entry::Entry () : object (0), next (null)
{}

ChainedScatterTable::ChainedScatterTable (unsigned int _length) : HashTable (_length), array (_length)
{}

void ChainedScatterTable::Purge ()
{
    for (unsigned int i = 0; i < length; ++i)
    {
		if (array [i].object != 0)
		{
			if (IsOwner ())
				delete array [i].object;
			array [i] = Entry ();
		}
    }
    count = 0;
}

ChainedScatterTable::~ChainedScatterTable ()
{
	Purge ();
}

void ChainedScatterTable::Insert (Object& object)
{
    if (count == length)
    	throw std::domain_error ("scatter table is full");
    unsigned int probe = H (object);

    if (array [probe].object != 0)
    {
		while (array [probe].next != Entry::null)
			probe = array [probe].next;

		unsigned int const tail = probe;
		probe = (probe + 1) % length;

		while (array [probe].object != 0)
			probe = (probe + 1) % length;

		array [tail].next = probe;
    }
    array [probe].object = &object;
    array [probe].next = Entry::null;
    ++count;
}

Object& ChainedScatterTable::Find (Object const& object) const
{
    unsigned int probe = H (object);

    if (array[probe].object == 0)
    	return NullObject::Instance ();

    for ( ; probe != Entry::null; probe = array [probe].next)
    {
		if (object == *array [probe].object)
			return *array [probe].object;
    }

    return NullObject::Instance ();
}

void ChainedScatterTable::Withdraw (Object& object)
{
    if (count == 0)
    	throw std::domain_error ("scatter table is empty");

    unsigned int i = H (object);

    while (i != Entry::null && array [i].object != &object)
    	i = array [i].next;

    if (i == Entry::null)
    	throw std::invalid_argument ("object not found");

    for (;;)
    {
		unsigned int j;
		for (j = array [i].next; j != Entry::null; j = array [j].next)
		{
			unsigned int const h = H (*array [j].object);
			bool contained = false;

			for (unsigned int k = array [i].next; k != array [j].next && !contained; 	k = array [k].next)
			{
				if (k == h)
					contained = true;
			}

			if (!contained)
				break;
		}

		if (j == Entry::null)
			break;

		array [i].object = array [j].object;
		i = j;
    }

    array [i].object = 0;
    array [i].next = Entry::null;

    for (unsigned int j = (i + length - 1U) % length; j != i; j = (j + length - 1U) % length)
    {
		if (array [j].next == i)
		{
			array [j].next = Entry::null;
			break;
		}
    }
    --count;
}
