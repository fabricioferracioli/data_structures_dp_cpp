/*
 * BST.cpp
 *
 *  Created on: 11/07/2009
 *      Author: fabricio
 */

#include "BST.h"

BST::BST():BinaryTree()
{}

BST::BST (Object& _key) : BinaryTree(_key)
{}

BST& BST::Left () const
{
	return dynamic_cast<BST&> (BinaryTree::Left ());
}

BST& BST::Right () const
{
	return dynamic_cast<BST&> (BinaryTree::Right ());
}

Object& BST::Find (Object const& object) const
{
    if (IsEmpty ())
    	return NullObject::Instance ();

    int const diff = object.Compare (*key);

    if (diff == 0)
    	return *key;
    else if (diff < 0)
    	return Left ().Find (object);
    else
    	return Right ().Find (object);
}

Object& BST::FindMin () const
{
    if (IsEmpty ())
    	return NullObject::Instance ();
    else if (Left ().IsEmpty ())
    	return *key;
    else
    	return Left ().FindMin();
}

void BST::Insert (Object& object)
{
    if (IsEmpty ())
    	AttachKey (object);
    else
    {
		int const diff = object.Compare (*key);
		if (diff == 0)
			throw std::invalid_argument ("duplicate key");
		if (diff < 0)
			Left ().Insert (object);
		else
			Right ().Insert (object);
    }
    Balance ();
}

void BST::AttachKey (Object& object)
{
    if (!IsEmpty ())
    	throw std::domain_error ("invalid operation");
    key = &object;
    left = new BST ();
    right = new BST ();
}

void BST::Balance ()
{}

void BST::Withdraw (Object& object)
{
    if (IsEmpty ())
    	throw std::invalid_argument ("object not found");

    int const diff = object.Compare (*key);

    if (diff == 0)
    {
		if (!Left ().IsEmpty ())
		{
			Object& max = Left ().FindMax ();
			key = &max;
			Left ().Withdraw (max);
		}
		else if (!Right ().IsEmpty ())
		{
			Object& min = Right ().FindMin ();
			key = &min;
			Right ().Withdraw (min);
		}
		else
			DetachKey ();
    }
    else if (diff < 0)
    	Left ().Withdraw (object);
    else
    	Right ().Withdraw (object);
    Balance ();
}

Object& BST::DetachKey ()
{
    if (!IsLeaf ())
    	throw std::domain_error ("invalid operation");

    Object& result = *key;
    delete left;
    delete right;
    key = 0;
    left = 0;
    right = 0;
    return result;
}

bool BST::IsMember(const Object&) const
{
	return false;
}

Object& BST::FindMax () const
{
	return NullObject::Instance ();
}
