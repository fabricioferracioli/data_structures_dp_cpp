/*
 * Tree.h
 *
 *  Created on: 10/07/2009
 *      Author: fabricio
 */

#ifndef TREE_H_
#define TREE_H_

#include "../lista2/Container.h"
#include "../lista2/Iterator.h"
#include "../lista2/NullObject.h"
#include "../lista3/QueueAsLinkedList.h"
#include "../lista3/StackAsLinkedList.h"
#include "../Visitor/PrePostVisitor/PreOrder.h"

class Tree : public virtual Container
{
    class Iter;
public:
    virtual Object& Key () const = 0;
    virtual Tree& Subtree (unsigned int) const = 0;
    virtual bool IsEmpty () const = 0;
    virtual bool IsLeaf () const = 0;
    virtual unsigned int Degree () const = 0;
    virtual int Height () const;
    virtual void DepthFirstTraversal (PrePostVisitor&) const;
    virtual void BreadthFirstTraversal (Visitor&) const;
    void Accept (Visitor&) const;

    virtual void DepthFirstTraversal (PreOrder) const;
};

class Tree::Iter : public Iterator
{
    Tree const& tree;
    Stack& stack;
public:
    Iter (Tree const&);
    ~Iter ();
    void Reset ();
    bool IsDone () const;
    Object& operator * () const;
    void operator ++ ();
};

#endif /* TREE_H_ */
