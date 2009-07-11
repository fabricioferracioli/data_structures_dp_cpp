/*
 * BinaryTree.cpp
 *
 *  Created on: 11/07/2009
 *      Author: fabricio
 */

#include "BinaryTree.h"

BinaryTree::BinaryTree () : key (0), left (0), right (0)
{}

BinaryTree::BinaryTree (Object& _key) : key (&_key), left (new BinaryTree ()), right (new BinaryTree ())
{}

void BinaryTree::Purge ()
{
    if (!IsEmpty ())
    {
		if (IsOwner ())
			delete key;

		delete left;
		delete right;
		key = 0;
		left = 0;
		right = 0;
    }
}

BinaryTree::~BinaryTree ()
{
	Purge ();
}

void BinaryTree::DepthFirstTraversal (PrePostVisitor& visitor) const
{
    if (visitor.IsDone ())
    	return;

    if (!IsEmpty ())
    {
		visitor.PreVisit (*key);
		left->DepthFirstTraversal (visitor);
		visitor.Visit (*key);
		right->DepthFirstTraversal (visitor);
		visitor.PostVisit (*key);
    }
}

int BinaryTree::CompareTo (Object const& object) const
{
    BinaryTree const& arg = dynamic_cast<BinaryTree const&> (object);

    if (IsEmpty ())
    	return arg.IsEmpty () ? 0 : -1;
    else if (arg.IsEmpty ())
    	return 1;
    else
    {
		int result = Key ().Compare (arg.Key ());

		if (result == 0)
			result = Left ().CompareTo (arg.Left ());

		if (result == 0)
			result = Right ().CompareTo (arg.Right ());

		return result;
    }
}

void BinaryTree::AttachKey (Object& arg)
{
    key = &arg;
}

void BinaryTree::AttachLeft (BinaryTree& arg)
{
    left = &arg;
}

void BinaryTree::AttachRight (BinaryTree& arg)
{
    right = &arg;
}

Object& BinaryTree::Key () const
{
    return *key;
}

bool BinaryTree::IsEmpty () const
{
    return (key == 0 && IsLeaf()) ? true : false;
}

BinaryTree& BinaryTree::Left () const
{
     return *left;
}

BinaryTree& BinaryTree::Right () const
{
    return *right;
}

bool BinaryTree::IsLeaf () const
{
    return (left == 0 && right == 0) ? true : false;
}

BinaryTree& BinaryTree::DetachLeft ()
{
    BinaryTree& arg = *new BinaryTree();
    arg = *left;
    left = 0;
    return arg;
}

BinaryTree& BinaryTree::DetachRight ()
{
    BinaryTree& arg = *new BinaryTree();
    arg = *right;
    right = 0;
    return arg;
}

Object& BinaryTree::DetachKey ()
{
    Object &arg = *key;
    key = 0;
    return arg;
}

Tree& BinaryTree::Subtree (unsigned int arg) const
{
    BinaryTree& ret = *new BinaryTree();
    return ret;
    //return NullObject::Instance();
}

unsigned int BinaryTree::Degree() const
{
	return 0;
}
