/*
 * PreOrder.h
 *
 *  Created on: 10/07/2009
 *      Author: fabricio
 */

#ifndef PREORDER_H_
#define PREORDER_H_

#include "PrePostVisitor.h"

class PreOrder : public PrePostVisitor
{
    Visitor& visitor;
public:
    PreOrder (Visitor& v) : visitor (v)
	{}
    void PreVisit (Object& object)
	{ visitor.Visit (object); }
};

#endif /* PREORDER_H_ */
