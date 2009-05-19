/*
 * NullIterator.cpp
 *
 *  Created on: 18/05/2009
 *      Author: fabricio
 */

#include "NullIterator.h"
#include "NullObject.h"


NullIterator::NullIterator ()
{}

void NullIterator::Reset ()
{}

bool NullIterator::IsDone () const
{
	return true;
}

Object& NullIterator::operator * () const
{
	return NullObject::Instance ();
}

void NullIterator::operator ++ ()
{}
