/*
 *
 * Lista de exercícios Estrutura de dados
 * Alunos: Fabricio Ferracioli
 *         Moisés Fernando Lima
 *
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "ListElement.h"
#include <iostream>
#include <stdexcept>

template <class T>
class ListElement;

template <class T>
class LinkedList
{
    protected:
        ListElement<T>* head;
        ListElement<T>* tail;
        int elements;

    public:

        LinkedList ();
        ~LinkedList ();
        LinkedList (LinkedList const&);

        LinkedList& operator = (LinkedList const&);

        ListElement<T> const* Head () const;
        ListElement<T> const* Tail () const;
        T const& First () const;
        T const& Last () const;
        int Elements () const;

        bool IsEmpty () const;

        void Prepend (T const&);
        void Append (T const&);
        void Extract (T const&);
        void Purge ();
        void InsertAfter (ListElement<T> const*, T const&);
        void InsertBefore (ListElement<T> const*, T const&);

        void Show() const;
};

template <class T>
LinkedList<T>::LinkedList ():
head (0),tail (0), elements(0)
{
}

template <class T>
void LinkedList<T>::Purge ()
{
    while (head != 0)
    {
        ListElement<T>* const tmp = head;
        head = head->next;
        delete tmp;
    }
    elements = 0;
    tail = 0;
}

template <class T>
LinkedList<T>::~LinkedList ()
{
    Purge ();
}

template <class T>
ListElement<T> const* LinkedList<T>::Head () const
{
    return head;
}

template <class T>
ListElement<T> const* LinkedList<T>::Tail () const
{
    return tail;
}

template <class T>
bool LinkedList<T>::IsEmpty () const
{
    return head == 0;
}

template <class T>
T const& LinkedList<T>::First () const
{
    if (head == 0)
    {
        throw std::domain_error ("list is empty");
    }
    return head->datum;
}

template <class T>
T const& LinkedList<T>::Last () const
{
    if (tail == 0)
	{
        throw std::domain_error ("list is empty");
	}
    return tail->datum;
}

template <class T>
int LinkedList<T>::Elements () const
{
    return elements;
}

template <class T>
void LinkedList<T>::Prepend (T const& item)
{
    ListElement<T>* const tmp = new ListElement<T> (item, head);
    if (head == 0)
    {
        tail = tmp;
    }
    head = tmp;
    elements++;
}

template <class T>
void LinkedList<T>::Append (T const& item)
{
    ListElement<T>* const tmp = new ListElement<T> (item, 0);
    if (head == 0)
    {
        head = tmp;
    }
    else
    {
        tail->next = tmp;
    }
    tail = tmp;
    elements++;
}

template <class T>
LinkedList<T>::LinkedList (LinkedList<T> const& linkedList):
head (0),tail (0), elements(0)
{
    ListElement<T> const* ptr;
    for (ptr = linkedList.head; ptr != 0; ptr = ptr->next)
    {
        Append (ptr->datum);
    }
}

template <class T>
LinkedList<T>& LinkedList<T>::operator = (LinkedList<T> const& linkedList)
{
    if (&linkedList != this)
    {
        Purge ();
        ListElement<T> const* ptr;
        for (ptr = linkedList.head; ptr != 0; ptr = ptr->next)
        {
            Append (ptr->datum);
        }
    }
    return *this;
}

template <class T>
void LinkedList<T>::Extract (T const& item)
{
    ListElement<T>* ptr = head;
    ListElement<T>* prevPtr = 0;

    while (ptr != 0 && ptr->datum != item)
    {
        prevPtr = ptr;
        ptr = ptr->next;
    }

    if (ptr == 0)
        throw std::invalid_argument ("item not found");

    if (ptr == head)
         head = ptr->next;
    else
         prevPtr->next = ptr->next;

    if (ptr == tail)
         tail = prevPtr;

    elements--;
    delete ptr;
}

template <class T>
void LinkedList<T>::InsertAfter (ListElement<T> const* arg, T const& item)
{
    ListElement<T>* ptr = const_cast<ListElement<T>*> (arg);
    if (ptr == 0)
        throw std::invalid_argument ("invalid position");

    ListElement<T>* const tmp = new ListElement<T> (item, ptr->next);
    ptr->next = tmp;

    if (tail == ptr)
        tail = tmp;

    elements++;
}

template <class T>
void LinkedList<T>::InsertBefore (ListElement<T> const* arg, T const& item)
{
    ListElement<T>* ptr = const_cast<ListElement<T>*> (arg);
    if (ptr == 0)
        throw std::invalid_argument ("invalid position");

    ListElement<T>* const tmp = new ListElement<T> (item, ptr);
    if (head == ptr)
        head = tmp;
    else
    {
        ListElement<T>* prevPtr = head;
        while (prevPtr != 0 && prevPtr->next != ptr)
            prevPtr = prevPtr->next;

        if (prevPtr == 0)
            throw std::invalid_argument ("invalid position");

        prevPtr->next = tmp;
    }

    elements++;
}

template <class T>
void LinkedList<T>::Show() const
{
    ListElement<T> const* ptr;
    for (ptr = head; ptr != 0; ptr = ptr->next)
    {
       std::cout << ptr->Datum() <<std::endl ;
    }
}

#endif /*LINKEDLIST_H_*/
