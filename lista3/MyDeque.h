#ifndef MYDEQUE_H_
#define MYDEQUE_H_

#include "../lista2/Container.h"

class MyDeque:public virtual Container
{
	public:
	    virtual Object& Head () const = 0;
	    virtual Object& Tail () const = 0;
	    virtual void EnqueueHead (Object&) = 0;
	    virtual void EnqueueTail (Object&) = 0;
	    virtual Object& DequeueHead () = 0;
	    virtual Object& DequeueTail () = 0;
};

#endif /*MYDEQUE_H_*/
