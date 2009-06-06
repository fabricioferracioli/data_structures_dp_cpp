/*
 * Enumeration.cpp
 *
 *  Created on: 06/06/2009
 *      Author: fabricio
 */

#include "Enumeration.h"

Enumeration::Enumeration(Container &obj) : c(obj), it(obj.NewIterator())
{}

bool Enumeration::hasMoreElements ()
{
    return (!it.IsDone());
}

Object& Enumeration::nextElement ()
{
    Object &ret = *it;
    ++it;
    return ret;
}

Enumeration::~Enumeration()
{
    if (IsOwner())
    {
        delete &it;
        delete &c;
    }
}
