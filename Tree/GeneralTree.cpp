/*
 * GeneralTree.cpp
 *
 *  Created on: 10/07/2009
 *      Author: fabricio
 */
/*
#include "GeneralTree.h"

GeneralTree::GeneralTree (Object& _key) : key (&_key), degree (0), list ()
{}

void GeneralTree::Purge ()
{
    ListElement<GeneralTree*> const* ptr;

    if (IsOwner ())
    	delete key;
    for (ptr = list.Head (); ptr != 0; ptr = ptr->Next ())
    	delete ptr->Datum ();
    key = 0;
    list.Purge ();
}

GeneralTree::~GeneralTree ()
{
	Purge ();
}

Object& GeneralTree::Key () const
{
	return *key;
}

GeneralTree& GeneralTree::Subtree (unsigned int i) const
{
    if (i >= degree)
    	throw std::out_of_range ("invalid subtree index");

    unsigned int j = 0;
    ListElement<GeneralTree*> const* ptr =	list.Head ();

    while (j < i && ptr != 0)
    {
    	++j;
    	ptr = ptr->Next ();
    }

    if (ptr == 0)
    	throw std::logic_error ("should never happen");
    return *ptr->Datum ();
}

void GeneralTree::AttachSubtree (GeneralTree& t)
{
    list.Append (&t);
    ++degree;
}

GeneralTree& GeneralTree::DetachSubtree (GeneralTree& t)
{
    list.Extract (&t);
    --degree;
    return t;
}
*/
