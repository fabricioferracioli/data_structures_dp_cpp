/*
 * Object.cpp
 *
 *  Created on: May 14, 2009
 *      Author: fabricio
 */

#include "Object.h"


bool Object::IsNull () const
    { return false; }

int Object::Compare (Object const& object) const
{
    if (typeid (*this) == typeid (object))
    	return CompareTo (object);
    else if (typeid (*this).before (typeid (object)))
    	return -1;
    else
    	return 1;
}

Object::~Object() {
	// TODO Auto-generated destructor stub
}

inline bool operator == (Object const& left, Object const& right)
{
	return left.Compare (right) == 0;
}

inline bool operator != (Object const& left, Object const& right)
{
	return left.Compare (right) != 0;
}

inline bool operator <= (Object const& left, Object const& right)
{
	return left.Compare (right) <= 0;
}

inline bool operator <  (Object const& left, Object const& right)
{
	return left.Compare (right) <  0;
}

inline bool operator >= (Object const& left, Object const& right)
{
	return left.Compare (right) >= 0;
}

inline bool operator >  (Object const& left, Object const& right)
{
	return left.Compare (right) >  0;
}

inline std::ostream& operator << (std::ostream& s, Object const& object)
{
	object.Put (s); return s;
}

