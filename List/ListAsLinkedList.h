/*
 * ListAsLinkedList.h
 *
 *  Created on: 26/06/2009
 *      Author: fabricio
 */

#ifndef LISTASLINKEDLIST_H_
#define LISTASLINKEDLIST_H_

#include "OrderedList.h"
#include "../lista1/LinkedList.h"
#include "../Iterator/Position.h"

class ListAsLinkedList : public virtual OrderedList
{
	protected:
		LinkedList<Object*> linkedList;

		class Pos;
	public:
		ListAsLinkedList ();

		friend class Pos;
};

class ListAsLinkedList::Pos : public Position
{
    ListAsLinkedList const& list;
    ListElement<Object*> const* element;
	public:
		friend class ListAsLinkedList;
};


#endif /* LISTASLINKEDLIST_H_ */
