/*
 * BagAsLinkedList.h
 *
 *  Created on: 06/06/2009
 *      Author: fabricio
 */

#ifndef BAGASLINKEDLIST_H_
#define BAGASLINKEDLIST_H_

#include "Bag.h"
#include "../lista1/LinkedList.h"

class BagAsLinkedList : public virtual Bag
{

    private:
        LinkedList<Object*> list;
        class Iter;

    public:
        BagAsLinkedList();
        Iterator& NewIterator () const;
        int CompareTo(const Object&)const;
        void Purge ();
        void Accept (Visitor&) const;
        bool IsMember (Object const&) const;
        void Insert (Object&);
        void Withdraw (Object&);
        Object& Find (Object const&) const;
        virtual ~BagAsLinkedList();

        friend class Iter;
};

class BagAsLinkedList::Iter : public Iterator
{
    private:
		BagAsLinkedList const& bag;
		ListElement<Object*> const* position;

    public:
		Iter(BagAsLinkedList const&);
		bool IsDone()const;
		Object& operator*()const;
		void operator++();
		void Reset();
};

#endif /* BAGASLINKEDLIST_H_ */
