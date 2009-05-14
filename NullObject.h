/*
 * NullObject.h
 *
 *  Created on: May 14, 2009
 *      Author: fabricio
 */

#ifndef NULLOBJECT_H_
#define NULLOBJECT_H_

#include "Object.h"
#include <iostream>

class NullObject : public Object
{
    static NullObject instance;

    NullObject ();
protected:
    int CompareTo (Object const&) const;
public:
    bool IsNull () const;
    HashValue Hash () const;
    void Put (std::ostream& s) const;

    static NullObject& Instance ();
};

#endif /* NULLOBJECT_H_ */
