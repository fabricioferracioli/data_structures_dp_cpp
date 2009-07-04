/*
 * ListAsArray.cpp
 *
 *  Created on: 26/06/2009
 *      Author: fabricio
 */

#include "ListAsArray.h"

ListAsArray::ListAsArray (unsigned int size) : array (size)
{}

void ListAsArray::Insert (Object& object)
{
    if (count == array.Length ())
    {
    	throw std::domain_error ("list is full");
    }
    array [count] = &object;
    ++count;
}

Object& ListAsArray::operator [] (unsigned int offset) const
{
    if (offset >= count)
    {
    	throw std::out_of_range ("invalid offset");
    }
    return *array [offset];
}

bool ListAsArray::IsMember (Object const& object) const
{
    for (unsigned int i = 0; i < count; ++i)
	if (array [i] == &object)
	    return true;
    return false;
}

Object& ListAsArray::Find (Object const& object) const
{
    for (unsigned int i = 0; i < count; ++i)
	if (*array [i] == object)
	    return *array [i];
    return NullObject::Instance ();
}

void ListAsArray::Withdraw (Object& object)
{
    if (count == 0)
    {
    	throw std::domain_error ("list is empty");
    }
    unsigned int i = 0;

    while (i < count && array [i] != &object)
    	++i;

    if (i == count)
    {
    	throw std::invalid_argument ("object not found");
    }

    for ( ; i < count - 1U; ++i)
    {
    	array [i] = array [i + 1];
    }
    --count;
}

Position& ListAsArray::FindPosition (Object const& object) const
{
    unsigned int i = 0;
    while (i < count && *array [i] != object)
    {
    	++i;
    }
    return *new Pos (*this, i);
}

Object& ListAsArray::operator [] (Position const& arg) const
{
    Pos const& position = dynamic_cast<Pos const&> (arg);

    if (&position.list != this || position.offset >= count)
    {
    	throw std::invalid_argument ("invalid position");
    }
    return *array [position.offset];
}

void ListAsArray::InsertAfter (Position const& arg, Object& object)
{
    Pos const& position = dynamic_cast<Pos const&> (arg);

    if (count == array.Length ())
    {
    	throw std::domain_error ("list is full");
    }

    if (&position.list != this || position.offset >= count)
    {
    	throw std::invalid_argument ("invalid position");
    }

    unsigned int const insertPosition = position.offset + 1;

    for (unsigned int i = count; i > insertPosition; --i)
    {
    	array [i] = array [i - 1U];
    }
    array [insertPosition] = &object;
    ++count;
}

void ListAsArray::Withdraw (Position const& arg)
{
    Pos const& position = dynamic_cast<Pos const&> (arg);

    if (count == 0)
    {
    	throw std::domain_error ("list is empty");
    }
    if (&position.list != this || position.offset >= count)
    {
    	throw std::invalid_argument ("invalid position");
    }

    for (unsigned int i = position.offset; i < count-1U; ++i)
    {
    	array [i] = array [i + 1];
    }
    --count;
}

ListAsArray::Pos::Pos(ListAsArray const& _list) : list(_list)
{
	Reset();
}

ListAsArray::Pos::Pos(ListAsArray const& _list, unsigned int pos) : list(_list), offset(pos)
{}

bool ListAsArray::Pos::IsDone() const
{
    return offset >= list.Count();
}

Object& ListAsArray::Pos::operator*()const
{
    if(offset < list.Count())
        return *list.array[offset];
    else
        return NullObject::Instance();
}

void ListAsArray::Pos::operator++()
{
    if (offset < list.Count())
        ++offset;
}

void ListAsArray::Pos::Reset()
{
    offset = 0;
}
