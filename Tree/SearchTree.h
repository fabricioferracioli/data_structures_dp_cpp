/*
 * SearchTree.h
 *
 *  Created on: 11/07/2009
 *      Author: fabricio
 */

#ifndef SEARCHTREE_H_
#define SEARCHTREE_H_

#include "Tree.h"
#include "../lista2/SearchableContainer.h"

class SearchTree : public virtual Tree, public virtual SearchableContainer
{
public:
    virtual Object& FindMin () const = 0;
    virtual Object& FindMax () const = 0;
};

#endif /* SEARCHTREE_H_ */
