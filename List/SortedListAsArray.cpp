/*
 * SortedListAsArray.cpp
 *
 *  Created on: 26/06/2009
 *      Author: fabricio
 */

#include "SortedListAsArray.h"

void SortedListAsArray::Insert (Object& object)
{
    if (count == array.Length ())
    {
    	throw std::domain_error ("list is full");
    }
    unsigned int i = count;

    while (i > 0 && *array [i - 1U] > object)
    {
		array [i] = array [i - 1U];
		--i;
    }

    array [i] = &object;
    ++count;
}

unsigned int SortedListAsArray::FindOffset (Object const& object) const
{
    int left = 0;
    int right = count - 1;

    while (left <= right)
    {
		int const middle = (left + right) / 2;

		if (object > *array [middle])
		{
			left = middle + 1;
		}
		else if (object < *array [middle])
		{
			right = middle - 1;
		}
		else
		{
			return middle;
		}
    }
    return count;
}

Object& SortedListAsArray::Find (Object const& object) const
{
    unsigned int const offset = FindOffset (object);

    if (offset < count)
    {
    	return *array [offset];
    }
    else
    {
    	return NullObject::Instance ();
    }
}

Position& SortedListAsArray::FindPosition (Object const& object) const
{
    Pos& result = *new Pos (*this);
    result.offset = FindOffset (object);
    return result;
}

void SortedListAsArray::Withdraw (Object& object)
{
    if (count == 0)
    {
    	throw std::domain_error ("list is empty");
    }

    unsigned int const offset = FindOffset (object);

    if (offset == count)
    {
    	throw std::invalid_argument ("object not found");
    }

    for (unsigned int i = offset; i < count - 1U; ++i)
    {
    	array [i] = array [i + 1];
    }
    --count;
}
