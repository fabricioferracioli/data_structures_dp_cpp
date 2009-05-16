/*
 * Object.h
 *
 *  Created on: May 14, 2009
 *      Author: fabricio
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include <iostream>
#include <typeinfo>
#include "MyHash.h"

class Object {
protected:
    virtual int CompareTo (Object const&) const = 0;
public:
    virtual ~Object ();
    virtual bool IsNull () const;
    virtual int Compare (Object const&) const;
    virtual HashValue Hash () const = 0;
    virtual void Put (std::ostream&) const = 0;
};

#endif /* OBJECT_H_ */

