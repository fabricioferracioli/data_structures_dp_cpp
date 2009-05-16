/*
 * Wrapper.h
 *
 *  Created on: May 14, 2009
 *      Author: fabricio
 */

#ifndef WRAPPER_H_
#define WRAPPER_H_

#include "Object.h"
#include <iostream>

template <class T>
class Wrapper : public Object
{
protected:
    T datum;

    int CompareTo (Object const&) const;
public:
    Wrapper ();
    Wrapper (T const&);
    Wrapper& operator = (T const&);
    operator T const& () const;
    HashValue Hash () const;
    void Put (std::ostream&) const;
};

#endif /* WRAPPER_H_ */
