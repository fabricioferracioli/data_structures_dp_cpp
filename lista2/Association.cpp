/*
 * Association.cpp
 *
 *  Created on: 30/05/2009
 *      Author: fabricio
 */

#include "Association.h"

Association::Association (Object& _key) : key (&_key), value (0)
{}

Association::Association (Object& _key, Object& _value) : key (&_key), value (&_value)
{}

Association::~Association ()
{
    if (IsOwner ())
    {
    	delete key;
    	delete value;
    }
}

Object& Association::Key () const
{
    return *key;
}

Object& Association::Value () const
{
    if (value == 0)
    {
        return NullObject::Instance ();
    }
    else
    {
        return *value;
    }
}

int Association::CompareTo (Object const& object) const
{
    Association const& association = dynamic_cast<Association const&> (object);
    return Key().Compare (association.Key ());
}

void Association::Put (std::ostream& s) const
{
    s << "Association {" << *key;
    if (value != 0)
    {
    	s << ", " << *value;
    }
    s << "}";
}
