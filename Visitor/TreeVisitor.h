/*
 * TreeVisitor.h
 *
 *  Created on: 27/07/2009
 *      Author: fabricio
 */

#ifndef TREEVISITOR_H_
#define TREEVISITOR_H_

#include "../lista2/Visitor.h"

class TreeVisitor : public virtual Visitor
{
    public:
       TreeVisitor(){}
       void Visit(Object& arg)
       {
           std::cout << arg << ' ';
       }
};

#endif /* TREEVISITOR_H_ */
