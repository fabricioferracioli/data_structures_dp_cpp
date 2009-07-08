/*
 * OpenScatterTable.h
 *
 *  Created on: 07/07/2009
 *      Author: fabricio
 */

#ifndef OPENSCATTERTABLE_H_
#define OPENSCATTERTABLE_H_

#include "HashTable.h"
#include "../lista1/Array.h"

class OpenScatterTable : public HashTable
{
    class Entry
    {
    public:
    	enum State { empty, occupied, deleted };
    	State state;
    	Object* object;

    	Entry ();
    };

    Array<Entry> array;

    unsigned int C (unsigned int) const;
    unsigned int FindMatch (Object const&) const;
    unsigned int FindInstance (Object const&) const;
    unsigned int FindUnoccupied (Object const&) const;
public:
    OpenScatterTable (unsigned int);
    ~OpenScatterTable();
    void Purge();
    void Insert (Object&);
    Object& Find (Object const&) const;
    void Withdraw (Object&);
};

#endif /* OPENSCATTERTABLE_H_ */
