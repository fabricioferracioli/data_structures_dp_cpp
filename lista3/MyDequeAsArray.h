#ifndef MYDEQUEASARRAY_H_
#define MYDEQUEASARRAY_H_

#include "MyDeque.h"
#include "../lista1/Array.h"

class MyDequeAsArray: public virtual MyDeque
{
	protected:
		Array<Object*> array;
        unsigned int head;
        unsigned int tail;
	public:
		MyDequeAsArray (unsigned int = 10);
        virtual ~MyDequeAsArray();
        void Purge();
        Object& Head () const;
        Object& Tail () const;
        void EnqueueHead (Object&);
        void EnqueueTail (Object&);
        Object& DequeueHead ();
        Object& DequeueTail ();
        void Accept (Visitor& visitor) const;
        bool IsFull()const;
};

#endif /*MYDEQUEASARRAY_H_*/
