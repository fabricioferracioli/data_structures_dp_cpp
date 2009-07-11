/*
 * PostOrder.h
 *
 *  Created on: 10/07/2009
 *      Author: fabricio
 */

#ifndef POSTORDER_H_
#define POSTORDER_H_

#include "PrePostVisitor.h"

class PostOrder : public PrePostVisitor
{
    Visitor& visitor;
public:
    PostOrder (Visitor& v) : visitor (v)
	{}
    void PostVisit (Object& object)
	{ visitor.Visit (object); }
};

#endif /* POSTORDER_H_ */
