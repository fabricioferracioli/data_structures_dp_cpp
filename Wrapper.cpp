/*
 * Wrapper.cpp
 *
 *  Created on: May 14, 2009
 *      Author: fabricio
 */

#include "Wrapper.h"

int Compare(int a, int b)
{
	if (a == b)
		return 0;
	else if (a > b)
		return 1;
	else
		return -1;
}

int Compare(char a, char b)
{
	if (a == b)
		return 0;
	else if (a > b)
		return 1;
	else
		return -1;
}

int Compare(double a, double b)
{
	if (a == b)
		return 0;
	else if (a > b)
		return 1;
	else
		return -1;
}

int Compare(std::string a, std::string b)
{
	if (a == b)
		return 0;
	else if (a > b)
		return 1;
	else
		return -1;
}

template <class T>
Wrapper<T>::Wrapper () :
    datum ()
    {}

template <class T>
Wrapper<T>::Wrapper (T const& d) :
    datum (d)
    {}

template <class T>
Wrapper<T>& Wrapper<T>::operator = (T const& d)
{
    datum = d;
    return *this;
}

template <class T>
Wrapper<T>::operator T const& () const
{
	return datum;
}

template <class T>
int Wrapper<T>::CompareTo (Object const& obj) const
{
    Wrapper<T> const& arg = dynamic_cast<Wrapper<T> const&> (obj);
    return ::Compare (datum, arg.datum);
}

template <class T>
void Wrapper<T>::Put (std::ostream& s) const
{
	s << datum;
}
