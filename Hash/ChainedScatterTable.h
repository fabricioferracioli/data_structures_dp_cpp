/*
 * ChainedScatterTable.h
 *
 *  Created on: 07/07/2009
 *      Author: fabricio
 */

#ifndef CHAINEDSCATTERTABLE_H_
#define CHAINEDSCATTERTABLE_H_

#include "HashTable.h"
#include "../lista1/Array.h"

class ChainedScatterTable : public HashTable
{
    class Entry
    {
    public:
    	enum { null = ~0U };
    	Object* object;
    	unsigned int next;

    	Entry ();
    };

    Array<Entry> array;
public:
    ChainedScatterTable (unsigned int);
    ~ChainedScatterTable();
    void Purge();
    void Insert (Object&);
    Object& Find (Object const&) const;
    void Withdraw (Object&);
};

#endif /* CHAINEDSCATTERTABLE_H_ */
