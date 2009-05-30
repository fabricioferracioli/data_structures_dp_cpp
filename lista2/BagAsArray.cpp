/*
 * BagAsArray.cpp
 *
 *  Created on: 29/05/2009
 *      Author: fabricio
 */

#include "BagAsArray.h"

BagAsArray::BagAsArray(unsigned int size) : array(size)
{
}

int BagAsArray::CompareTo(const Object& obj)const
{
    return 0;
}

void BagAsArray::Purge ()
{
	if(IsOwner())
	{
		for(unsigned int i = 0; i < count; i++)
		{
				delete array[i];
		}
	}
	count = 0;
}

bool BagAsArray::IsFull () const
{
    if(count == array.Length())
        return true;
    else
        return false;
}

Iterator& BagAsArray::NewIterator () const
{
    return *new Iter(*this);
}

void BagAsArray::Accept (Visitor& visitor) const
{
    for (unsigned int i = 0; i < count && !visitor.IsDone(); i++)
    {
        visitor.Visit(*array[i]);
    }
}

bool BagAsArray::IsMember (Object const& objeto) const
{
    MatchingVisitor v(objeto);
	this->Accept(v);
	return v.IsDone();
}

void BagAsArray::Insert (Object& objeto)
{
    if(IsFull())
        throw std::domain_error("Bag is Full");
    array[count++] = &objeto;

}

Object& BagAsArray::Find (Object const& objeto) const
{

	MatchingVisitor v(objeto);

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

void BagAsArray::Withdraw (Object& objeto)
{
    if(!IsMember(objeto))
        return;

    int pos = 0;
    for (unsigned int i = 0; i < count; i++)
    {
        if(*array[i] == objeto)
        {     pos = i;
              break;
        }
    }

    for (unsigned int k = pos; k<count-1; k++)
        array[k] = array[k+1];
    count--;

}


BagAsArray::~BagAsArray()
{
    Purge();
}

BagAsArray::Iter::Iter(BagAsArray const& _bag): bag(_bag)
{
	Reset();
}

bool BagAsArray::Iter::IsDone() const
{
    return position >= bag.Count();
}

Object& BagAsArray::Iter::operator*()const
{
    if(position < bag.Count())
        return *bag.array[position];
    else
        return NullObject::Instance();
}

void BagAsArray::Iter::operator++()
{
    if (position < bag.count)
        ++position;
}

void BagAsArray::Iter::Reset()
{
    position = 0;
}
