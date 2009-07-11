/*
 * InOrder.h
 *
 *  Created on: 10/07/2009
 *      Author: fabricio
 */

#ifndef INORDER_H_
#define INORDER_H_

#include "PrePostVisitor.h"

class InOrder : public PrePostVisitor
{
    Visitor& visitor;
public:
    InOrder (Visitor& v) : visitor (v)
	{}
    void Visit (Object& object)
	{ visitor.Visit (object); }
};

#endif /* INORDER_H_ */
