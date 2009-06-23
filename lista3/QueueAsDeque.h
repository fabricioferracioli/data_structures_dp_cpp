#ifndef QUEUEASDEQUE_H_
#define QUEUEASDEQUE_H_

#include "MyDeque.h"

class QueueAsDeque:public virtual MyDeque
{
	public:
        virtual Object& Head() const = 0;
        virtual void Enqueue(Object&) = 0;
        virtual Object& Dequeue() = 0;
};

#endif /*QUEUEASDEQUE_H_*/
