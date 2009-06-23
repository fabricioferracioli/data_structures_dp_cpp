#ifndef QUEUEASDEQUEASARRAY_H_
#define QUEUEASDEQUEASARRAY_H_

#include "QueueAsDeque.h"
#include "MyDequeAsArray.h"

class QueueAsDequeAsArray:public virtual QueueAsDeque, public MyDequeAsArray
{
	public:
        QueueAsDequeAsArray(unsigned int = 10);
        Object& Head() const;
        void Enqueue(Object&);
        Object& Dequeue();
};

#endif /*QUEUEASDEQUEASARRAY_H_*/
