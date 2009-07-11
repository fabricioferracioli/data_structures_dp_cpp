/*
 * PrePostVisitor.h
 *
 *  Created on: 10/07/2009
 *      Author: fabricio
 */

#ifndef PREPOSTVISITOR_H_
#define PREPOSTVISITOR_H_

#include "../../lista2/Visitor.h"

class PrePostVisitor : public Visitor
{
public:
    virtual void PreVisit (Object&) {}
    virtual void Visit (Object&) {}
    virtual void PostVisit (Object&) {}
};

#endif /* PREPOSTVISITOR_H_ */
