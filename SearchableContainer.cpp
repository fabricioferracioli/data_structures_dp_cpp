/*
 * SearchableContainer.cpp
 *
 *  Created on: 18/05/2009
 *      Author: fabricio
 */

#include "SearchableContainer.h"


SearchableContainer::SearchableContainer(int size) : count(size)
{}

bool SearchableContainer::IsMember(Object const & obj) const
{
	return false;
}

Object& SearchableContainer::Find(Object const & obj) const
{

}

void SearchableContainer::Accept(Visitor & vis) const
{

}

