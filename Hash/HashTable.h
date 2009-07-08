/*
 * HashTable.h
 *
 *  Created on: 07/07/2009
 *      Author: fabricio
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "../lista2/SearchableContainer.h"

class HashTable : public virtual SearchableContainer
{
protected:
    unsigned int length;
public:
    HashTable (unsigned int);
    virtual unsigned int H (Object const&) const;
};

#endif /* HASHTABLE_H_ */
