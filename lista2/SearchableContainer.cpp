#include "SearchableContainer.h"

/*bool SearchableContainer::IsMember (Object const& objeto) const
{
    //declata um visitor para obj
    MatchingVisitor v(objeto);
    //container aceita o visitor
	this->Accept(v);
	//retorna true se encontrou o objeto, false caso contrario
	return v.IsDone();
}
*/

/*Object& SearchableContainer::Find (Object const& objeto) const
{
     //declara um visitor para obj
     MatchingVisitor v(objeto);
	 //container aceita o visitor
	 this->Accept(v);
	 //verifica se foi encontrado,
	 if (v.IsDone())
	 {
		//retorna objeto
		return *(v.Found());
	 }
	 else
	 {
	    //retorna objeto nulo
		return NullObject::Instance();
	 }
}*/


/*bool SearchableContainer::IsMember (Object const& objeto) const
{
    //cria uma referencia para o iterador
    Iterator &i = this->NewIterator();
    //percorro o container de acordo com os metodos do iterador
    while(!i.IsDone())
    {
        if(*i == objeto)
        {
            //se objeto for o procurado, retorna true
            return true;
        }
        //incremento o iterador
        ++i;
    }
    //se chegar aqui � porque percorreu todo o container e nao encontrou o objeto
    return false;
}

 */

/*Object& SearchableContainer::Find (Object const& objeto) const
{
    //cria uma referencia para o iterador
    Iterator &i = this->NewIterator();
    //percorro o container de acordo com os metodos do iterador
    while(!i.IsDone())
    {
        if(*i == objeto)
        {
            //se objeto for o procurado, retorna o objeto
            return *i;
        }
        //incremento o iterador
        ++i;
    }
    //se chegar aqui � porque percorreu todo o container e nao encontrou o objeto
    return NullObject::Instance(); //retorna uma instancia nula de objeto
}

*/
