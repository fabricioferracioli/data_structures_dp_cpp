/*
 *
 * Lista de exercícios Estrutura de dados
 * Alunos: Fabricio Ferracioli
 *         Moisés Fernando Lima
 *
 */

#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

#include "ListElement.h"
#include <iostream>
#include <stdexcept>

template <class T>
class ListElement;

template <class T>
class SinglyLinkedList
{
    protected:
        ListElement<T>* head;
        int elements;

    public:

        SinglyLinkedList ();
        ~SinglyLinkedList ();
        SinglyLinkedList (SinglyLinkedList const&);

        SinglyLinkedList& operator = (SinglyLinkedList const&);

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

//construtor padrao
template <class T>
SinglyLinkedList<T>::SinglyLinkedList ():
head (0), elements(0)
{
}

//funcao auxiliar do destrutor
template <class T>
void SinglyLinkedList<T>::Purge ()
{
    while (head != 0)
    {
        ListElement<T>* const tmp = head;
        head = head->next;
        delete tmp;
    }
    elements = 0;
}

//destrutor
template <class T>
SinglyLinkedList<T>::~SinglyLinkedList ()
{
    Purge ();
}

template <class T>
ListElement<T> const* SinglyLinkedList<T>::Head () const
{
    return head;
}

template <class T>
ListElement<T> const* SinglyLinkedList<T>::Tail () const
{
    ListElement<T> const* aux = head;
    ListElement<T> const* tmp;
    while(aux != 0){
        tmp = aux;
        aux = aux->next;
    }
    return tmp;
}

template <class T>
bool SinglyLinkedList<T>::IsEmpty () const
{
    return head == 0;
}

template <class T>
T const& SinglyLinkedList<T>::First () const
{
    if (head == 0)
    {
        throw std::domain_error ("list is empty");
    }
    return head->datum;
}

template <class T>
T const& SinglyLinkedList<T>::Last () const
{
    ListElement<T> const* aux = head;
    ListElement<T> const* tmp;
    while(aux != 0){
        tmp = aux;
        aux = aux->next;
    }
    return tmp->datum;
}

template <class T>
int SinglyLinkedList<T>::Elements () const
{
    return elements;
}

template <class T>
void SinglyLinkedList<T>::Prepend (T const& item)
{
    ListElement<T>* const tmp = new ListElement<T> (item, head);
    head = tmp;
    elements++;
}

template <class T>
void SinglyLinkedList<T>::Append (T const& item)
{
    ListElement<T>* const tmp = new ListElement<T> (item, 0);
    ListElement<T>* aux;
    ListElement<T>* aux2;
    for (aux = head; aux != 0; aux = aux->next){
        aux2 = aux;
    }
    aux2->next = tmp;
    elements++;
}

//construtor de copia
template <class T>
SinglyLinkedList<T>::SinglyLinkedList (SinglyLinkedList<T> const& SinglyLinkedList):
head (0), elements(0)
{
    ListElement<T> const* ptr;
    for (ptr = SinglyLinkedList.head; ptr != 0; ptr = ptr->next)
    {
        Append (ptr->datum);
    }
}

template <class T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator = (SinglyLinkedList<T> const& SinglyLinkedList)
{
    if (&SinglyLinkedList != this)
    {
        Purge ();
        ListElement<T> const* ptr;
        for (ptr = SinglyLinkedList.head; ptr != 0; ptr = ptr->next)
        {
            Append (ptr->datum);
        }
    }
    return *this;
}

template <class T>
void SinglyLinkedList<T>::Extract (T const& item)
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

    //percorre a lista em busca da cauda
    ListElement<T> const* aux = head;
    ListElement<T> const* tmp2;
    while(aux != 0){
        tmp2 = aux;
        aux = aux->next;
    }
    tmp2;//cauda

    if (ptr == tmp2)
         tmp2 = prevPtr;

    elements--;
    delete ptr;
}

template <class T>
void SinglyLinkedList<T>::InsertAfter (ListElement<T> const* arg, T const& item)
{
    ListElement<T>* ptr = const_cast<ListElement<T>*> (arg);
    if (ptr == 0)
        throw std::invalid_argument ("invalid position");

    ListElement<T>* const tmp = new ListElement<T> (item, ptr->next);
    ptr->next = tmp;

    //percorre a lista em busca da cauda
    ListElement<T> const* aux = head;
    ListElement<T> const* tmp2;
    while(aux != 0){
        tmp2 = aux;
        aux = aux->next;
    }
    tmp2;//cauda
    if (tmp2 == ptr) tmp2 = tmp;
    elements++;
}

template <class T>
void SinglyLinkedList<T>::InsertBefore (ListElement<T> const* arg, T const& item)
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
void SinglyLinkedList<T>::Show() const
{
    ListElement<T> const* ptr;
    for (ptr = head; ptr != 0; ptr = ptr->next)
    {
       std::cout << ptr->Datum() <<std::endl ;
    }
}

#endif /*SINGLYLINKEDLIST_H_*/

