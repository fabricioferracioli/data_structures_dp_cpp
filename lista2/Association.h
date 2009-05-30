/*
 * Association.h
 *
 *  Created on: 30/05/2009
 *      Author: fabricio
 */

#ifndef ASSOCIATION_H_
#define ASSOCIATION_H_

#include "Object.h"
#include "NullObject.h"
#include "Ownership.h"

class Association : public Object, public Ownership
{
    protected:
        Object* key;
        Object* value;

        int CompareTo (Object const&) const;

    public:
        Association (Object&);
        Association (Object&, Object&);
        ~Association ();

        Object& Key () const;
        Object& Value () const;

        void Put (std::ostream&) const;
};

#endif /* ASSOCIATION_H_ */
