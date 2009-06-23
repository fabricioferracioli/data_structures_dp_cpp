#include "QueueAsDequeAsArray.h"

QueueAsDequeAsArray::QueueAsDequeAsArray (unsigned int size) : MyDequeAsArray(size)
{}

Object& QueueAsDequeAsArray::Head () const
{
    return MyDequeAsArray::Head();
}

void QueueAsDequeAsArray::Enqueue (Object& object)
{
    MyDequeAsArray::EnqueueTail(object);
}

Object& QueueAsDequeAsArray::Dequeue ()
{
    return MyDequeAsArray::DequeueHead();
}