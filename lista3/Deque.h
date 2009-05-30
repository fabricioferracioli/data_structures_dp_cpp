/*
 * Deque.h
 *
 *  Created on: 30/05/2009
 *      Author: fabricio
 */

#ifndef DEQUE_H_
#define DEQUE_H_

#include "Queue.h"

class Deque : public virtual Queue
{
public:
    virtual Object& Head () const = 0;
    virtual Object& Tail () const = 0;
    virtual void Enqueue (Object&);
    virtual void EnqueueHead (Object&) = 0;
    virtual void EnqueueTail (Object&) = 0;
    virtual Object& Dequeue ();
    virtual Object& DequeueHead () = 0;
    virtual Object& DequeueTail () = 0;
};

#endif /* DEQUE_H_ */
