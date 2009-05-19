/*
 * Visitor.h
 *
 *  Created on: 18/05/2009
 *      Author: fabricio
 */

#ifndef VISITOR_H_
#define VISITOR_H_

#include "Object.h"

class Visitor
{
public:
    virtual void Visit (Object&) = 0;
    virtual bool IsDone () const
	{ return false; }
};

#endif /* VISITOR_H_ */
