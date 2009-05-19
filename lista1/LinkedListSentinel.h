/*
 *
 * Lista de exercícios Estrutura de dados
 * Alunos: Fabricio Ferracioli
 *         Moisés Fernando Lima
 *
 */

#ifndef LINKEDLISTSENTINEL_H_
#define LINKEDLISTSENTINEL_H_

#include "ListElement.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
class LinkedListSentinel
{
    protected:
        //atributos
        ListElement<T> *head;
        ListElement<T> sentinela;
        int elements;

    public:
        LinkedListSentinel ();
        ~LinkedListSentinel ();
        LinkedListSentinel (LinkedListSentinel const&);

        LinkedListSentinel& operator = (LinkedListSentinel const&);

        ListElement<T> const* Head () const;
        T const& First () const;
        T const& Last () const;
        int Elements () const;
        bool IsEmpty () const;
        void Show() const;
        void Prepend (T const&);
        void Append (T const&);
        void Extract (T const&);
        void Purge ();
        void InsertAfter (ListElement<T> const*, T const&);
        void InsertBefore (ListElement<T> const*, T const&);
};

//inicializa o sentinela apontando para ele mesmo
template <class T>
LinkedListSentinel<T>::LinkedListSentinel():
head(&sentinela), sentinela(0,&sentinela), elements(0)
{
}

template <class T>
void LinkedListSentinel<T>::Purge ()
{

    ListElement<T>* percorre = sentinela.next;
    while (percorre->next != &sentinela)
    {
        ListElement<T>* const tmp = percorre;
        percorre = percorre->next;
        delete tmp;
    }
    delete percorre;
    elements = 0;
}

template <class T>
LinkedListSentinel<T>::~LinkedListSentinel ()
{
    Purge ();
}

template <class T>
void LinkedListSentinel<T>::Prepend (T const& item)
{
    ListElement<T>* const tmp = new ListElement<T> (item, sentinela.next);
    sentinela.next = tmp;
    elements++;
}

template <class T>
void LinkedListSentinel<T>::Append (T const& item)
{
    ListElement<T>* tmp = new ListElement<T> (item, &sentinela);

    ListElement<T>* percorre = sentinela.next;
    while (percorre->next != &sentinela)
    {
        percorre = percorre->next;
    }
    percorre->next = tmp;

    elements++;
}

template <class T>
ListElement<T> const* LinkedListSentinel<T>::Head () const
{
    return sentinela.next;
}

template <class T>
bool LinkedListSentinel<T>::IsEmpty () const
{
    return sentinela.next == &sentinela;
}

template <class T>
T const& LinkedListSentinel<T>::First () const
{
    if (sentinela.next == &sentinela)
    {
        throw domain_error ("lista vazia");
    }
    return sentinela.next->datum;
}

template <class T>
T const& LinkedListSentinel<T>::Last () const
{

    //verifica se a lista esta vazia
    if(sentinela.next == &sentinela)
    {
        throw domain_error ("list is empty");
    }
    else
	{
        ListElement<T>* percorre = sentinela.next;
        while (percorre->next != &sentinela)
        {
            percorre = percorre->next;
        }
        return percorre->datum;
	}
}

template <class T>
int LinkedListSentinel<T>::Elements () const
{
    return elements;
}


template <class T>
LinkedListSentinel<T>::LinkedListSentinel (LinkedListSentinel<T> const& LinkedListSentinel):
head(&sentinela), sentinela(0,&sentinela), elements(0)
{

    ListElement<T> const *first = LinkedListSentinel.Head();
    ListElement<T> const *percorre;

    for (percorre = first; percorre->next !=first; percorre = percorre->next)
    {
        Append(percorre->datum);
    }
}

template <class T>
LinkedListSentinel<T>& LinkedListSentinel<T>::operator = (LinkedListSentinel<T> const& LinkedListSentinel)
{
    if (&LinkedListSentinel != this)
    {
        Purge ();
        ListElement<T> const *first = LinkedListSentinel.Head();
        ListElement<T> const *percorre;
        for (percorre = first; percorre->next != first; percorre = percorre->next)
        {
            Append (percorre->datum);
        }
    }
    return *this;
}

template <class T>
void LinkedListSentinel<T>::Extract (T const& item)
{
    ListElement<T>* ptr = sentinela.next;
    ListElement<T>* prevPtr = 0;

    //faz a busca
    while (ptr->next != &sentinela && ptr->datum != item)
    {
        prevPtr = ptr;
        ptr = ptr->next;
    }

    if (ptr->next == &sentinela && ptr->datum != item)
        throw invalid_argument ("item nao encontrado");

    //item na head
    if (ptr == sentinela.next)
         sentinela.next = ptr->next;
    else
    {
         prevPtr->next = ptr->next;
    }

    elements--;
    delete ptr;
}

template <class T>
void LinkedListSentinel<T>::InsertAfter (ListElement<T> const* arg, T const& item)
{
    ListElement<T>* ptr = const_cast<ListElement<T>*> (arg);
    if (ptr->next == Head())
        throw invalid_argument ("invalid position");

    ListElement<T>* const tmp = new ListElement<T> (item, ptr->next);
    ptr->next = tmp;

    elements++;
}

template <class T>
void LinkedListSentinel<T>::InsertBefore (ListElement<T> const* arg, T const& item)
{
    ListElement<T>* ptr = const_cast<ListElement<T>*> (arg);

    //posiçao invalida
    if (ptr == 0)
        throw invalid_argument ("invalid position");

    ListElement<T>* const tmp = new ListElement<T> (item, ptr);

    //caso cabeca
    if (sentinela.next == ptr)
        sentinela.next = tmp;
    else
    {
        ListElement<T>* prevPtr = sentinela.next;
        while (prevPtr != Head() && prevPtr->next != ptr)
            prevPtr = prevPtr->next;

        if (prevPtr == 0)
            throw invalid_argument ("invalid position");

        prevPtr->next = tmp;
    }

    elements++;
}

template <class T>
void LinkedListSentinel<T>::Show() const
{
    if (IsEmpty())
    {
        cout<<"Lista Vazia";
    }
    else
    {
        ListElement<T> const* ptr;
        for (ptr = sentinela.next; ptr->next != &sentinela; ptr = ptr->next)
        {
           cout<<ptr->Datum() << endl;
        }
        cout<<ptr->Datum() << endl;
    }
    cout << endl;
}

#endif /*LINKEDLISTSENTINEL_H_*/
