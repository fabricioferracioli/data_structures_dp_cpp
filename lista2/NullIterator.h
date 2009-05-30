/*
 * NullIterator.h
 *
 *  Created on: 18/05/2009
 *      Author: fabricio
 */

#ifndef NULLITERATOR_H_
#define NULLITERATOR_H_

#include "Iterator.h"

class NullIterator : public Iterator
{
public:
    NullIterator ();
    void Reset ();
    bool IsDone () const;
    Object& operator * () const;
    void operator ++ ();
};

#endif /* NULLITERATOR_H_ */
