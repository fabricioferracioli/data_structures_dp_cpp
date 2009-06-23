#include "MyDequeAsArray.h"

MyDequeAsArray::MyDequeAsArray(unsigned int size) : array (size), head (0), tail (size - 1U)
{}

void MyDequeAsArray::Purge ()
{
    if (IsOwner ())
    {
        for (unsigned int i = 0; i < count; ++i)
        {
            delete array [head];
            if (++head == array.Length ())
            head = 0;
        }
    }
    count = 0;
}

void MyDequeAsArray::Accept (Visitor& visitor) const
{
    if (count == 0)
    {
        throw std::domain_error ("queue is empty");
    }

    unsigned int i = head;

    while(i != tail && !visitor.IsDone())
    {
        visitor.Visit(*array[i]);
        if(++i == array.Length())
        {
            i = 0;
        }
    }
    visitor.Visit(*array[i]);
}

Object& MyDequeAsArray::Head () const
{
    if (count == 0)
    {
        throw std::domain_error ("queue is empty");
    }
    return *array [head];
}

void MyDequeAsArray::EnqueueTail (Object& object)
{

    if (count == array.Length ())
    {
        throw std::domain_error ("queue is full");
    }

    if (++tail == array.Length ())
        tail = 0;

    array [tail] = &object;
    ++count;
}

Object& MyDequeAsArray::DequeueHead ()
{
     if (count == 0)
     {
        throw std::domain_error ("queue is empty");
     }

    Object& result = *array [head];
    if (++head == array.Length ())
    {
        head = 0;
    }

    --count;
    return result;
}

Object& MyDequeAsArray::Tail () const
{
    if (count == 0)
    {
        throw std::domain_error ("deque is empty");
    }
    return *array [tail];
}

void MyDequeAsArray::EnqueueHead (Object& object)
{
    if (count == array.Length ())
    {
        throw std::domain_error ("deque is full");
    }

    if (head-- == 0)
    {
        head = array.Length () - 1U;
    }

    array [head] = &object;
    ++count;
}

Object& MyDequeAsArray::DequeueTail ()
{
    if (count == 0)
    {
        throw std::domain_error ("deque is empty");
    }

    Object& result = *array [tail];

    if (tail-- == 0)
    {
        tail = array.Length () - 1U;
    }

    --count;
    return result;
}

bool MyDequeAsArray::IsFull () const
{
    return (count == array.Length());
}

MyDequeAsArray::~MyDequeAsArray ()
{
    Purge ();
}
