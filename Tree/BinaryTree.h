/*
 * BinaryTree.h
 *
 *  Created on: 11/07/2009
 *      Author: fabricio
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include "Tree.h"
#include "../Visitor/PrePostVisitor/PrePostVisitor.h"

class BinaryTree : public virtual Tree
{
protected:
    Object* key;
    BinaryTree* left;
    BinaryTree* right;
public:
    BinaryTree ();
    BinaryTree (Object&);
    ~BinaryTree ();

    Object& Key () const;
    virtual void AttachKey (Object&);
    virtual Object& DetachKey ();
    virtual BinaryTree& Left () const;
    virtual BinaryTree& Right () const;
    virtual void AttachLeft (BinaryTree&);
    virtual void AttachRight (BinaryTree&);
    virtual BinaryTree& DetachLeft ();
    virtual BinaryTree& DetachRight ();

    void Purge ();
    void DepthFirstTraversal (PrePostVisitor&) const;
    int CompareTo (Object const&) const;

    virtual bool IsEmpty() const;
    virtual Tree& Subtree(unsigned int) const;
    virtual bool IsLeaf() const;
    virtual unsigned int Degree() const;
};

#endif /* BINARYTREE_H_ */
