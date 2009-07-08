/*
 * OpenScatterTable.cpp
 *
 *  Created on: 07/07/2009
 *      Author: fabricio
 */

#include "OpenScatterTable.h"

OpenScatterTable::Entry::Entry () : state (empty), object (0)
{}

OpenScatterTable::OpenScatterTable (unsigned int _length) : HashTable (_length), array (_length)
{}

void OpenScatterTable::Purge ()
{
    for (unsigned int i = 0; i < length; ++i)
    {
		if (array [i].state == Entry::occupied)
		{
			if (IsOwner ())
				delete array [i].object;
			array [i] = Entry ();
		}
    }
    count = 0;
}

OpenScatterTable::~OpenScatterTable ()
{
	Purge ();
}

unsigned int OpenScatterTable::C (unsigned int i) const
{
	return i;
}

unsigned int OpenScatterTable::FindUnoccupied (Object const& object) const
{
    unsigned int const hash = H (object);
    for (unsigned int i = 0; i < count + 1; ++i)
    {
		unsigned int const probe = (hash + C (i)) % length;
		if (array [probe].state != Entry::occupied)
			return probe;
    }
    return length;
}

void OpenScatterTable::Insert (Object& object)
{
    if (count == length)
    	throw std::domain_error ("scatter table is full");

    unsigned int const offset = FindUnoccupied (object);
    array [offset].state = Entry::occupied;
    array [offset].object = &object;
    ++count;
}

unsigned int OpenScatterTable::FindMatch (Object const& object) const
{
    unsigned int const hash = H (object);

    for (unsigned int i = 0; i < length; ++i)
    {
		unsigned int const probe = (hash + C (i)) % length;

		if (array [probe].state == Entry::empty)
			break;

		if (array [probe].state == Entry::occupied && object == *array [probe].object)
			return probe;
    }
    return length;
}

Object& OpenScatterTable::Find (Object const& object) const
{
    unsigned int const offset = FindMatch (object);

    if (offset < length)
    	return *array [offset].object;
    else
    	return NullObject::Instance ();
}

unsigned int OpenScatterTable::FindInstance (Object const&) const
{
	return 0;
}

void OpenScatterTable::Withdraw (Object& object)
{
    if (count == 0)
    	throw std::domain_error ("scatter table is empty");

    unsigned int const offset = FindInstance (object);

    if (offset == length)
    	throw std::invalid_argument ("object not found");

    array [offset].state = Entry::deleted;
    array [offset].object = 0;
    --count;
}

/* Alternativa ao metodo de cima
void OpenScatterTable::Withdraw (Object& object)
{
    if (count == 0)
	throw domain_error ("scatter table is empty");
    unsigned int i = FindInstance (object);
    if (i == length)
	throw invalid_argument ("object not found");
    for (;;)
    {
	unsigned int j;
	for (j = (i + 1) % length;
	    array [j].state == Entry::occupied;
	    j = (j + 1) % length)
	{
	    unsigned int const h = H (*array [j].object);
	    if ((h <= i && i < j) || (i < j && j < h) ||
		(j < h && h <= i))
		break;
	}
	if (array [j].state == Entry::empty)
	    break;
	array [i] = array [j];
	i = j;
    }
    array [i].state = Entry::empty;
    array [i].object = 0;
    --count;
}
*/
