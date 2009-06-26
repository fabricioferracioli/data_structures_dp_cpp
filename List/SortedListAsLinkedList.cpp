/*
 * SortedListAsLinkedList.cpp
 *
 *  Created on: 26/06/2009
 *      Author: fabricio
 */

#include "SortedListAsLinkedList.h"

void SortedListAsLinkedList::Insert (Object& object)
{
    ListElement<Object*> const* prevPtr = 0;
    ListElement<Object*> const* ptr =
	linkedList.Head ();

    while (ptr != 0 && *ptr->Datum () < object)
    {
		prevPtr = ptr;
		ptr = ptr->Next ();
    }

    if (prevPtr == 0)
    {
    	linkedList.Prepend (&object);
    }
    else
    {
    	linkedList.InsertAfter (prevPtr, &object);
    }

    ++count;
}
