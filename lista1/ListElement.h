#ifndef LISTELEMENT_H_
#define LISTELEMENT_H_

#include "LinkedList.h"
#include "SinglyLinkedList.h"
//#include "LinkedListSentinel.h"
#include <iostream>

template <class T>
class LinkedList;

template <class T>
class SinglyLinkedList;

template <class T>
class LinkedListSentinel;

template <class T>
class ListElement
{
    protected:
        T datum;
        ListElement* next;
    public:
        T const& Datum () const;
        ListElement const* Next () const;
        ListElement (T const&, ListElement*);

        friend class LinkedList<T>;
        friend class LinkedListSentinel<T>;
        friend class SinglyLinkedList<T>;
};

template <class T>
ListElement<T>::ListElement(T const& _datum, ListElement<T>* _next)
:datum (_datum), next (_next)
{
}

template <class T>
T const& ListElement<T>::Datum()const
{
    return datum;
}

template <class T>
ListElement<T> const* ListElement<T>::Next()const
{
    return next;
}

#endif /* LISTELEMENT_H_ */
