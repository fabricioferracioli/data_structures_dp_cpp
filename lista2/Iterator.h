/*
 * Iterator.h
 *
 *  Created on: 18/05/2009
 *      Author: fabricio
 */

#ifndef ITERATOR_H_
#define ITERATOR_H_

#include "Object.h"

class Iterator
{
public:
    virtual ~Iterator ();
    virtual void Reset () = 0;
    virtual bool IsDone () const = 0;
    virtual Object& operator * () const = 0;
    virtual void operator ++ () = 0;
};

#endif /* ITERATOR_H_ */
