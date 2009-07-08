/*
 * Container.h
 *
 *  Created on: 18/05/2009
 *      Author: fabricio
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Object.h"
#include "Ownership.h"
#include "Iterator.h"
#include "Visitor.h"
#include "NullIterator.h"
#include "PuttingVisitor.h"
#include "../Visitor/HashingVisitor.h"
#include <typeinfo>

class Container : public virtual Object, public virtual Ownership
{

protected:
    unsigned int count;

    Container ();
public:
    virtual unsigned int Count () const;
    virtual bool IsEmpty () const;
    virtual bool IsFull () const;
    virtual HashValue Hash () const;
    virtual void Put (std::ostream&) const;
    virtual Iterator& NewIterator () const;

    virtual void Purge () = 0;
    virtual void Accept (Visitor&) const = 0;
};

#endif /* CONTAINER_H_ */
