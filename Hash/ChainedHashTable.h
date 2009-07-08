/*
 * ChainedHashTable.h
 *
 *  Created on: 07/07/2009
 *      Author: fabricio
 */

#ifndef CHAINEDHASHTABLE_H_
#define CHAINEDHASHTABLE_H_

#include "HashTable.h"
#include "../lista1/Array.h"
#include "../lista1/LinkedList.h"

class ChainedHashTable : public HashTable
{
    Array<LinkedList<Object*> > array;
public:
    ChainedHashTable (unsigned int);
    ~ChainedHashTable ();
    void Purge();
    void Insert (Object&);
    void Withdraw (Object&);
    Object& Find (Object const&) const;
};

#endif /* CHAINEDHASHTABLE_H_ */
