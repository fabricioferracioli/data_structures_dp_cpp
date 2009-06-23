#include "MultipleStack.h"

MultipleStack::MultipleStack (unsigned int size) : array(size)
{
    for (unsigned int i = 0; i < size; i++)
    {
		StackAsLinkedList* nova_pilha = new StackAsLinkedList();
		array[i] = nova_pilha;
	}
}

void MultipleStack::MultipleStack::Purge ()
{
    for (unsigned int i = 0; i < array.Length(); i++)
    {
        array[i]->Purge();
        delete array[i];
    }
}

void MultipleStack::Push (Object& obj, unsigned int index)
{
   if (index < array.Length())
   {
		array[index]->Push(obj);
   }
   else
   {
        throw std::domain_error("invalid index");
   }
}

Object& MultipleStack::Pop (unsigned int index)
{

	if (index<array.Length())
   	{
        return array[index]->Pop();
 	}
  	else
   	{
        return NullObject::Instance ();
   	}
}

Object& MultipleStack::Top (unsigned int index) const
{

   if (index<array.Length())
   {
        return array[index]->Top();
   }
   else
   {
        return NullObject::Instance ();
   }
}

unsigned int MultipleStack::SizeOfStack (unsigned int index) const
{
   if (index<array.Length())
   {
       return array[index]->Count();
   }
   else
   {
       return 0;
   }
}

void MultipleStack::Accept (Visitor& visitor) const
{
    for(unsigned int i = 0; i < array.Length(); i++)
    {
        array[i]->Accept(visitor);
        std::cout << std::endl;
    }
}

MultipleStack::~MultipleStack()
{
    Purge();
}
