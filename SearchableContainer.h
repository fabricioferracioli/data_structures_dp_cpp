/*
 * SearchableContainer.h
 *
 *  Created on: 18/05/2009
 *      Author: fabricio
 */

#ifndef SEARCHABLECONTAINER_H_
#define SEARCHABLECONTAINER_H_

#include "Container.h"

class SearchableContainer : public virtual Container
{
public:
	SearchableContainer();
	SearchableContainer(int);
    virtual bool IsMember (Object const&) const = 0;
    virtual void Insert (Object&) = 0;
    virtual void Withdraw (Object&) = 0;
    virtual Object& Find (Object const&) const = 0;
    virtual void Accept(Visitor &) const = 0;
};

#endif /* SEARCHABLECONTAINER_H_ */
