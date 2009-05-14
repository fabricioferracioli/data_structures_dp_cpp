/*
 * NullObject.cpp
 *
 *  Created on: May 14, 2009
 *      Author: fabricio
 */

#include "NullObject.h"

NullObject NullObject::instance;

NullObject::NullObject ()
    {}

bool NullObject::IsNull () const
    { return true; }

int NullObject::CompareTo (Object const&) const
    { return 0; }

HashValue NullObject::Hash () const
    { return 0; }

void NullObject::Put (std::ostream& s) const
    { s << "NullObject"; }

NullObject& NullObject::Instance ()
    { return instance; }
