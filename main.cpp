#include "lista1/Array.h"
#include "lista1/ListElement.h"
#include "lista1/LinkedList.h"
#include "lista1/Array2D.h"
//#include "Array3D.h"
#include "lista1/SinglyLinkedList.h"
#include "lista1/LinkedListSentinel.h"
#include "lista1/RowVector.h"
#include "lista1/ColumnVector.h"
//Neste caso eh para nao dar definicao multipla do Compare
//#include "lista2/Wrapper.h"
#include "lista2/BagAsArray.h"
#include "lista2/BagAsLinkedList.h"
#include "lista2/Association.h"
#include "lista2/Enumeration.h"
#include "lista3/Stack.h"
#include "lista3/StackAsArray.h"
#include "lista3/StackAsLinkedList.h"
#include "lista3/MultipleStack.h"
#include "lista3/QueueAsDequeAsArray.h"
#include "Hash/HashTable.h"
#include "Counter/Counter.h"
#include "Tree/AVLTree.h"
#include "Visitor/TreeVisitor.h"
#include "Visitor/PrePostVisitor/InOrder.h"
#include "Visitor/PrePostVisitor/PostOrder.h"
#include "Visitor/PrePostVisitor/PreOrder.h"

#include <iostream>
#include <math.h>
#include <string.h>
#include <typeinfo>

typedef Wrapper<int> Int;
typedef Wrapper<char> Char;
typedef Wrapper<double> Double;
typedef Wrapper<std::string> String;

/*
 * exercícios da lista 1
 */

void l1ex1(){
	std::cout << "Exercicio 01" << std::endl << std::endl;

	//construtor default, tudo inicializado com 0
    Array<int> o;
    //construtor que seta tamanho e base
    Array<int> a(10, 0);

    std::cout << "Tamanho " << a.Length() << std::endl;
    std::cout << "Base " << a.Base() << std::endl;

    for (unsigned int i = 0; i < 10; i++)
    {
    	a[i] = i;
    }

    for (unsigned int i = 0; i < 10; i++)
    {
    	std::cout << "a[" << i << "] => " << a[i] << std::endl;
    }

	//inicializando base e tamanho do objeto o
    o.SetBase(0);
    o.SetLength(5);

    std::cout << "Tamanho " << o.Length() << std::endl;
	std::cout << "Base " << o.Base() << std::endl;

	for (unsigned int i = 0; i < 5; i++)
	{
		o[i] = 100 + i;
	}
	//mostro os valores atribuidos em o
	for (unsigned int i = 0; i < 5; i++)
	{
		std::cout << "o[" << i << "] => " << o[i] << std::endl;
	}

	//array com copia do objeto o
	Array<int> copia(o);
	for (unsigned int i = 0; i < 5; i++)
	{
		std::cout << "copia[" << i << "] => " << copia[i] << std::endl;
	}

	for (unsigned int i = 0; i < 5; i++)
	{
		copia[i] = 200 + i;
	}

	for (unsigned int i = 0; i < 5; i++)
	{
		std::cout << "copia[" << i << "] => " << copia[i] << std::endl;
		std::cout << "o[" << i << "] => " << o[i] << std::endl;
	}

    const Array<int> c(2,0);
	std::cout << "Constante c " << c[0] <<std::endl;

	Array<int> d(2, 2);
	for (unsigned int i = 2; i < 4; i++)
	{
		d[i] = i * 3;
	}

	for (unsigned int i = 2; i < 4; i++)
	{
		std::cout << "d[" << i << "] => " << d[i] << std::endl;
	}

	std::cout << std::endl << std::endl;
}

void l1ex2()
{
	std::cout << "Exercicio 02" << std::endl << std::endl;

    //teste de insercao na lista, na frente e atras
    LinkedList<int> lista;
    lista.Append(42);
    lista.Append(37);
    lista.Append(987);
    lista.Append(540);
    lista.Append(56);
    lista.Append(45);
    lista.Prepend(1);

    //teste de construtor de copia
    LinkedList<int> copia(lista);

    //teste de acesso a cabeca e cauda, por valor e elemento de lista
    std::cout << "Metodo First " << lista.First() << std::endl;
    std::cout << "Metodo Head " << lista.Head()->Datum() << std::endl;

    std::cout << "Metodo First " << lista.Last() << std::endl;
    std::cout << "Metodo Head " << lista.Tail()->Datum() << std::endl;

    //teste de retorno do extract
    std::cout << "Elementos da lista original" << std::endl;
    lista.Show();
    std::cout << "Quantidade de elementos: " << lista.Elements() << std::endl;
    lista.Extract(540);
    std::cout << "Elementos da lista depois de extract" << std::endl;
    lista.Show();
    std::cout << "Quantidade de elementos: " << lista.Elements() << std::endl;

    std::cout << "Elementos da lista copiada" << std::endl;
    copia.Show();
    std::cout << "Quantidade de elementos: " << copia.Elements() << std::endl;

    //teste do perador de atribuicao
    lista = copia;
    std::cout << "Elementos da lista depois de receber a copia por atribuicao" << std::endl;
    lista.Show();
    std::cout << "Quantidade de elementos: " << lista.Elements() << std::endl;

    //teste de purge e empty
    lista.Purge();
    std::cout << "Elementos da lista apos purge" << std::endl;
    lista.Show();
    std::cout << "Quantidade de elementos: " << lista.Elements() << std::endl;
    std::cout<< "A lista esta vazia? " << lista.IsEmpty() << std::endl;

    std::cout << std::endl << std::endl;
}

void l1ex3()
{

    std::cout << "Exercicio 03" << std::endl << std::endl;

    //teste de insercao na lista, na frente e atras
    LinkedList<int> lista;
    lista.Append(42);
    lista.Append(37);
    lista.Append(987);
    lista.Append(540);
    lista.Append(56);
    lista.Append(45);
    lista.Prepend(1);
    lista.Show();

    //teste de construtor de copia
    LinkedList<int> copia(lista);
    std::cout << std::endl << "lista copia" << std::endl;
    copia.Show();
    std::cout << std::endl;

    //teste de acesso a cabeca e cauda, por valor e elemento de lista
    std::cout << "Metodo First: " << lista.First() << std::endl;
    std::cout << "Metodo Head: " << lista.Head()->Datum() << std::endl;

    std::cout << "Metodo Last: " << lista.Last() << std::endl;
    std::cout << "Metodo Tail: " << lista.Tail()->Datum() << std::endl;

    //teste de retorno do extract
    std::cout << "Elementos da lista original" << std::endl;
    lista.Show();
    std::cout << "Quantidade de elementos: " << lista.Elements() << std::endl;
    lista.Extract(540);
    std::cout << "Elementos da lista depois de extract" << std::endl;
    lista.Show();
    std::cout << "Quantidade de elementos: " << lista.Elements() << std::endl;

    std::cout << "Elementos da lista copiada" << std::endl;
    copia.Show();
    std::cout << "Quantidade de elementos: " << copia.Elements() << std::endl;

    //teste do perador de atribuicao
    lista = copia;
    std::cout << "Elementos da lista depois de receber a copia por atribuicao" << std::endl;
    lista.Show();
    std::cout << "Quantidade de elementos: " << lista.Elements() << std::endl;

    //teste de purge e empty
    lista.Purge();
    std::cout << "Elementos da lista apos purge" << std::endl;
    lista.Show();
    std::cout << "Quantidade de elementos: " << lista.Elements() << std::endl;
    std::cout<< "A lista esta vazia? " << lista.IsEmpty() << std::endl;


}

void l1ex4()
{

    std::cout << "Exercicio 04" << std::endl << std::endl;

    //criando uma lista
    LinkedListSentinel<int> lista;

    //testando inser��o de elementos
    cout << "lista";
    lista.Append(42);
    lista.Append(37);
    lista.Append(987);
    lista.Append(540);
    lista.Append(56);
    lista.Append(45);
    lista.Prepend(1);
    lista.Show();
    cout << endl;

    //testando construtor de copia
    LinkedListSentinel<int> copia = lista;
    copia.Append(4);

    cout << "lista copia" << endl;
    copia.Show();
    cout << endl;

    //testando operador de atribuicao entre listas
    LinkedListSentinel<int> copia2;
    copia2 = copia;
    cout << "atribuicao de lista" << endl;
    copia2.Show();

    //testando o extract
    cout << "extraindo o elemento 540" << endl;
    copia2.Extract(540);
    copia2.Show();

    //testes de insercao , antes e depois
    copia2.InsertAfter(copia2.Head(),11);
    copia2.InsertBefore(copia2.Head(),22);
    cout << "teste de insercao antes e depois" << endl;
    copia2.Show();


    cout<<"Lista"<<endl;
    cout<<endl <<"Valor do Head: "<< lista.Head()->Datum()<<endl;
    cout<<endl <<"First: "<<lista.First()<<endl;
    cout<<"Last: "<<lista.Last()<<endl;
    lista.Show();

    cout<<"Copia"<<endl;
    cout<<endl <<"Valor do Head: "<< copia.Head()->Datum()<<endl;
    cout<<endl <<"First: "<<copia.First()<<endl;
    cout<<"Last: "<<copia.Last()<<endl;
    copia.Show();

    cout<<"Copia 2 "<<endl;
    cout<<endl <<"Valor do Head: "<< copia2.Head()->Datum()<<endl;
    cout<<endl <<"First: "<<copia2.First()<<endl;
    cout<<"Last: "<<copia2.Last()<<endl;
    copia2.Show();
    cout<<endl;


}

void l1ex5()
{
	std::cout << "Exercicio 05" << std::endl << std::endl;

	std::cout << "Testando uma matriz 2x3" << std::endl;

	Array2D<int> mat(2, 3);

	for (unsigned int i = 0; i < 2; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			mat[i][j] = i + j;
		}
	}

	for (unsigned int i = 0; i < 2; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			std::cout << "mat[" << i << "][" << j << "] " << mat[i][j] << std::endl;
		}
	}

	std::cout << "Testando uma matriz 4x4 com base 2" << std::endl;

	unsigned int size = 4;
	unsigned int base = 2;
	Array2D<int> tab(size, size, base);

	for (unsigned int i = base; i < base + size; i++)
	{
		for (unsigned int j = base; j < base + size; j++)
		{
			tab[i][j] = i * j;
		}
	}

	for (unsigned int i = base; i < base + size; i++)
	{
		for (unsigned int j = base; j < base + size; j++)
		{
			std::cout << "Tab[" << i << "][" << j <<"] " << tab[i][j] << std::endl;
		}
	}

	std::cout << std::endl << std::endl;
}

//void l1ex6()
//{
//	std::cout << "Exercicio 06" << std::endl << std::endl;
//
//	Array3D<int> mat(2, 2, 2);
//
//	for (unsigned int i = 0; i < 2; i++)
//	{
//		for (unsigned int j = 0; j < 2; j++)
//		{
//			for (unsigned int k = 0; k < 2; k++)
//			{
//				mat[i][j][k] = i + j + k;
//			}
//		}
//	}
//
//	std::cout << std::endl << std::endl;
//}

void l1ex7()
{
	std::cout << "Exercicio 07" << std::endl << std::endl;

	RowVector<int> row(5);
	for (unsigned int i = 0; i < 5; i++)
	{
		row[i] = 4 * i;
	}
	for (unsigned int i = 0; i < 5; i++)
	{
		std::cout << "Row[0][" << i << "] " << row[i] << std::endl;
	}

	ColumnVector<int> column(5);
	for (unsigned int i = 0; i < 5; i++)
	{
		column[i] = 23 * i;
	}
	for (unsigned int i = 0; i < 5; i++)
	{
		std::cout << "Column[" << i << "][0] " << column[i] << std::endl;
	}
}

/*
 * exercícios da lista 2
 */

void l2ex1()
{
	std::cout << "Exercicio 01" << std::endl;
	std::cout << "Testando para Int" << std::endl;
	Int a(1);
	Int b(2);
	if(a == b)
		std::cout << "a = b" << std::endl;
	else
		std::cout << "a != b" << std::endl;

	a = 2;
	if(a == b)
			std::cout << "a = b" << std::endl;
		else
			std::cout << "a != b" << std::endl;

	std::cout << std::endl << "Testando para Char" << std::endl;
	Char c('s');
	Char d('k');
	if (c == d)
		std::cout << "c = d" << std::endl;
	else
		std::cout << "c != d" << std::endl;

	d = 's';
	if (c == d)
		std::cout << "c = d" << std::endl;
	else
		std::cout << "c != d" << std::endl;

	std::cout << std::endl << "Testando para Double" << std::endl;
	Double e(1.234);
	Double f(2.652);
	if (e == f)
		std::cout << "e = f" << std::endl;
	else
		std::cout << "e != f" << std::endl;

	f = 1.234;
	if (e == f)
		std::cout << "e = f" << std::endl;
	else
		std::cout << "e != f" << std::endl;

	std::cout << std::endl << "Testando para String" << std::endl;
	String g("teste");
	String h("testando");
	if (g == h)
		std::cout << "g = h" << std::endl;
	else
		std::cout << "g != h" << std::endl;

	h = "teste";
	if (e == f)
		std::cout << "g = h" << std::endl;
	else
		std::cout << "g != h" << std::endl;

	std::cout << std::endl;
}

void l2ex2()
{
	std::cout << "Exercicio 02" << std::endl;
	std::cout << "Verifique arquivo SearchableContainer.txt" << std::endl;
	std::cout << std::endl;
}

void l2ex3()
{
	std::cout << "Exercicio 03" << std::endl;
	std::cout << "Verifique arquivo SearchableContainer.txt" << std::endl;
	std::cout << std::endl;
}

void l2ex4()
{
	std::cout << "Exercicio 04" << std::endl;
	std::cout << "Verifique arquivo SearchableContainer.txt" << std::endl;
	std::cout << std::endl;
}

void l2ex5()
{
	std::cout << "Exercicio 05" << std::endl;

	BagAsArray bag(5);

	bag.Insert (*new Int (3));
	bag.Insert (*new Int (1));
	bag.Insert (*new Int (4));
	bag.Insert (*new Int (7));
	bag.Insert (*new Int (6));

	Iterator& i = bag.NewIterator ();
	while (!i.IsDone ())
	{
		std::cout << *i << " ";
		++i;
	}
	std::cout << std::endl;
	delete &i;

	bag.Withdraw(*new Int (7));

	std::cout << bag.Find (*new Int(7)) << std::endl;
	std::cout << bag.Find (*new Int(6)) << std::endl;
	std::cout << bag.IsMember (*new Int(7)) << std::endl;
	std::cout << bag.IsMember (*new Int(6)) << std::endl;

	std::cout << std::endl;
}

void l2ex6()
{
	std::cout << "Exercicio 06" << std::endl;

    BagAsLinkedList bag;

    bag.Insert (*new Int (1));
    bag.Insert (*new Int (2));
    bag.Insert (*new Int (3));
    bag.Insert (*new Int (4));
    bag.Insert (*new Int (5));

    Int num(6);
    bag.Insert (num);

    Iterator& i = bag.NewIterator ();
    while (!i.IsDone ())
    {
        std::cout << *i << " ";
        ++i;
    }
    std::cout<< std::endl;
    delete &i;

    bag.Withdraw(num);

	std::cout << bag.Find (*new Int(5)) << std::endl;
	std::cout << bag.Find (*new Int(6)) << std::endl;
	std::cout << bag.IsMember (*new Int(5)) << std::endl;
	std::cout << bag.IsMember (*new Int(6)) << std::endl;

	std::cout << std::endl;
}

void l2ex7()
{
	std::cout << "Exercicio 07" << std::endl;

    Association a(*new Int(2), *new Int(2));
    Association b(*new Int(3), *new Int(3));

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    if(a == b)
        std::cout << "Associacoes (a,b) Iguais" << std::endl;
    else
        std::cout << "Associacoes (a,b) Diferentes" << std::endl;

    Association c(*new Int(5), *new Int(42));
	Association d(*new Int(5), *new Int(31));

	std::cout << c << std::endl;
	std::cout << d << std::endl;

	if(c == c)
		std::cout << "Associacoes (c,d) Iguais" << std::endl;
	else
		std::cout << "Associacoes (c,d) Diferentes" << std::endl;

    std::cout << std::endl;
}

void l2ex8()
{
	std::cout << "Exercicio 08" << std::endl;

    BagAsArray bag(5);

    bag.Insert (*new Int (10));
    bag.Insert (*new Int (9));
    bag.Insert (*new Int (8));
    bag.Insert (*new Int (7));
    bag.Insert (*new Int (6));

    Enumeration e(bag);

    while (e.hasMoreElements())
    {
        std::cout << e.nextElement() << std::endl;
    }

    std::cout << std::endl;
}

bool isNumber(char str[], unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		if (!std::isdigit(str[i]))
		{
			return false;
		}
		else if (str[i] == '\0')
		{
			return true;
		}
	}
}

void RPNCalculator (Stack& stack)
{
	std::cout << "Exercicio 01" << std::endl;
	unsigned int size = 10;
    char c[size];

    while (std::cin >> c, !std::cin.eof ())
    {
		if (strcmp(c, "+") == 0)
		{
			Double& arg2 = dynamic_cast<Double&> (stack.Pop ());
			Double& arg1 = dynamic_cast<Double&> (stack.Pop ());
			stack.Push (*new Double (arg1 + arg2));
			delete &arg1;
			delete &arg2;
		}
		else if (strcmp(c, "*") == 0)
		{
			Double& arg2 = dynamic_cast<Double&> (stack.Pop ());
			Double& arg1 = dynamic_cast<Double&> (stack.Pop ());
			stack.Push (*new Double (arg1 * arg2));
			delete &arg1;
			delete &arg2;
		}
		else if (strcmp(c, "-") == 0)
		{
			Double& arg2 = dynamic_cast<Double&> (stack.Pop ());
			Double& arg1 = dynamic_cast<Double&> (stack.Pop ());
			stack.Push (*new Double (arg1 - arg2));
			delete &arg1;
			delete &arg2;
		}
		else if (strcmp(c, "/") == 0)
		{
			Double& arg2 = dynamic_cast<Double&> (stack.Pop ());
			Double& arg1 = dynamic_cast<Double&> (stack.Pop ());
			stack.Push (*new Double (arg1 / arg2));
			delete &arg1;
			delete &arg2;
		}
		else if (strcmp(c, "^") == 0)
		{
			Double& arg2 = dynamic_cast<Double&> (stack.Pop ());
			Double& arg1 = dynamic_cast<Double&> (stack.Pop ());
			stack.Push (*new Double (pow(arg1, arg2)));
			delete &arg1;
			delete &arg2;
		}
		else if (strcmp(c, "~") == 0)
		{
			Double& arg1 = dynamic_cast<Double&> (stack.Pop ());
			stack.Push(*new Double (-arg1));
			delete &arg1;
		}
		else if (strcmp(c, "=") == 0)
		{
			Double& arg = dynamic_cast<Double&> (stack.Pop ());
			std::cout << arg << std::endl;
			delete &arg;
		}
		else if(strcmp(c, "c") == 0)
		{
			std::cout << "Limpando o conteudo da pilha" << std::endl;
			stack.Purge();
		}
		else if(strcmp(c, "p") == 0)
		{
			std::cout << "Conteudo da pilha" << std::endl;
			Iterator& i = stack.NewIterator ();
			while (!i.IsDone ())
			{
				std::cout << *i << " ";
				++i;
			}
			std::cout<< std::endl;
			delete &i;
		}
		else/* (isNumber(c, size))*/
		{
			stack.Push (*new Double (atof(c)));
		}
    }
    std::cout << std::endl;
}

void polish(Stack& stack)
{
	std::cout << "Exercicio 02" << std::endl;
	char c;
	while (std::cin >> c, !std::cin.eof ())
	{
		if (!std::isdigit(c))
		{
			switch (c)
			{
				case '+':
				case '-':
				case '*':
				case '/':
				case '^':
				case '~':
					stack.Push(*new Char(c));
					break;
				case '=':
					Char& arg = dynamic_cast<Char&> (stack.Pop ());
					printf("%c", arg - '0');
					delete &arg;
					break;
			}
		}
		else
		{
			Char& arg1 = dynamic_cast<Char&> (stack.Top());

			if (std::isdigit(arg1))
			{
				stack.Pop();

				Char& Operator = dynamic_cast<Char&> (stack.Pop());

				switch (Operator)
				{
					case '+':
						stack.Push (*new Char (arg1 + c));
						break;
					case '-':
						stack.Push (*new Char (arg1 - c));
						break;
					case '*':
						stack.Push (*new Char (arg1 * c));
						break;
					case '/':
						stack.Push (*new Char (arg1 / c));
						break;
					case '^':
						stack.Push (*new Char (pow(arg1, c)));
						break;
					case '~':
						stack.Push(*new Char(-c));
						break;
				}
			}
			else
			{
				stack.Push(*new Char (c));
			}

		}
	}
	std::cout << std::endl;
}

void infix(Stack& stack)
{
	std::cout << "Exercicio 03" << std::endl;
	StackAsLinkedList infix_exp;
	while (!stack.IsEmpty())
	{
		String& arg = dynamic_cast<String&> (stack.Pop());
		if (arg == *new String("+") || arg == *new String("-") || arg == *new String("*") || arg == *new String("/") || arg == *new String("~") || arg == *new String("^"))
		{
			//se eh um operador, retiro os dois numeros do topo, concateno e armazeno na nova pilha
			String& arg1 = (!infix_exp.IsEmpty()) ? dynamic_cast<String&> (infix_exp.Pop()) : dynamic_cast<String&> (stack.Pop());
			String& arg2 = dynamic_cast<String&> (stack.Pop());

			string begin = "(";
			string operator1 = arg2;
			string operation = arg;
			string operator2 = arg1;
			string end = ")";

			infix_exp.Push(*new String (begin.append(operator1.append(operation.append(operator2.append(end))))));
		}
		else
		{
			//eh um numero, posso empilhar na nova pilha
			infix_exp.Push(*new String(arg));
		}
	}
	std::cout << infix_exp.Top() << std::endl;
	std::cout << std::endl;
}
/*
void l3ex07()
{
    std::cout << "Exercicio 07" << std::endl;

    try
    {
        MultipleStack stack(3);

        stack.Push(*new Int(1),0);
        stack.Push(*new Int(2),0);
        stack.Push(*new Int(3),0);
        stack.Pop(0);
        stack.Push(*new Int(4),0);

        stack.Push(*new Int(1),1);
        stack.Push(*new Int(2),1);
        stack.Pop(1);
        stack.Push(*new Int(3),1);

        stack.Push(*new Int(1),2);
        stack.Pop(2);
        stack.Push(*new Int(2),2);


        //stack.Push(*new Int(24),24);

        std::cout << stack << std::endl;
    }
     catch(exception &e){
        cerr << "Caught: " << e.what( ) << endl;
        cerr << "Type: " << typeid( e ).name( ) << endl;
     }
}

void l3ex09()
{
   std::cout <<"Exercicio 09" << std::endl;

   try
   {
        QueueAsDequeAsArray queue(10);

        queue.Enqueue(*new Int(5));
        queue.Enqueue(*new Int(10));
        queue.Enqueue(*new Int(15));
        queue.Enqueue(*new Int(20));
        queue.Enqueue(*new Int(25));

        queue.Dequeue();
        queue.Dequeue();

        queue.Enqueue(*new Int(30));
        std::cout << queue << std::endl << std::endl;
    }
    catch(exception &e){
        cerr << "Caught: " << e.what( ) << std::endl;
        cerr << "Type: " << typeid( e ).name( ) << std::endl;
     }
}
*/
void lista1()
{
	std::cout << "Lista de exercicios 01" << std::endl;
	l1ex1();
	l1ex2();
	l1ex3();
	l1ex4();
	l1ex5();
//	l1ex6();
	l1ex7();
}

void lista2()
{
	std::cout << "Lista de exercicios 02" << std::endl;
	l2ex1();
	l2ex2();
	l2ex3();
	l2ex4();
	l2ex5();
	l2ex6();
	l2ex7();
	l2ex8();
}

void lista3()
{
	std::cout << "Lista de exercicios 03" << std::endl;
	//exercicio 1, mantido o nome da funcao contida no livro
	StackAsLinkedList p;
	RPNCalculator(p);

	//exercicio 2
	StackAsLinkedList q;
	polish(q);

	//exercicio 3
	StackAsLinkedList r;
	r.Push(*new String("5"));
	r.Push(*new String("*"));
	r.Push(*new String("3"));
	r.Push(*new String("4"));
	r.Push(*new String("+"));
	infix(r);
}

void CountWords (HashTable& table)
{
    std::string word;
    while (cin >> word, !cin.eof ())
    {
		Object& obj = table.Find (Association (*new String (word)));
		if (obj.IsNull ())
			table.Insert (*new Association (*new String (word), *new Counter (1)));
		else
		{
			Association& assoc = dynamic_cast<Association&> (obj);
			Counter& i = dynamic_cast<Counter&> (assoc.Value ());
			++i;
		}
    }
    std::cout << table << std::endl;
}

void TesteBinaryTree()
{
	try
	{
		BinaryTree tree(*new Int(4));
		std::cout << tree << std::endl;

		//insere filhos do Nodo raiz
		tree.AttachLeft( *new BinaryTree(*new Int(5)));
		tree.AttachRight(*new BinaryTree(*new Int(2)));

		//insere filhos do Nodo com chave 2
		tree.Left().AttachLeft ( *new BinaryTree(*new Int(6)));
		tree.Left().AttachRight( *new BinaryTree(*new Int(7)));

		//insere filhos do Nodo com chave 5
		tree.Right().AttachLeft( *new BinaryTree(*new Int(8)));
		tree.Right().AttachRight(*new BinaryTree(*new Int(1)));

		//impressao dos valores da arvore
		//cout<<endl<<tree<<endl;

		//teste De percursos em Arvore
		//PuttingVisitor v(std::cout);
		TreeVisitor v;
		std::cout << "Percurso em PreOrdem" << std::endl;
		tree.DepthFirstTraversal (*new PreOrder (v));
		std::cout << std::endl;

		std::cout << "Percurso em Ordem" << std::endl;
		tree.DepthFirstTraversal (*new InOrder (v));
		std::cout << std::endl;

		std::cout << "Percurso em PosOrdem" << std::endl;
		tree.DepthFirstTraversal (*new PostOrder (v));
		std::cout << std::endl;

		//Teste do percurso em Nivel
		//cout<<"Percurso em Nivel"<<endl;
		//tree.BreadthFirstTraversal (*new TreeVisitor());

		//Uso de Iterator
		/*
		BinaryTree tree;
		Iterator& i = tree.NewIterator;
		while (!i.IsDone ()) {
			cout << *i << endl;
			++i;
		}
		delete &i;
		*/
	}
	catch(exception &e)
	{
		cerr << "Caught: " << e.what( ) << endl;
		cerr << "Type: " << typeid( e ).name( ) << endl;
	}
}

void TesteAvl()
{
   try
   {
       //cria arvore AVL
       AVLTree tree;

       //cria objetos a serem inseridos
       Object &ob1 = *new Int(1);
       Object &ob2 = *new Int(2);
       Object &ob3 = *new Int(3);
       Object &ob4 = *new Int(4);
       Object &ob5 = *new Int(5);
       Object &ob6 = *new Int(6);
       Object &ob7 = *new Int(7);

       //insere elementos
       // na ordem de chaves: 4,2,6,1,3,5,7
       /*
       tree.Insert(ob4);
       tree.Insert(ob2);
       tree.Insert(ob6);
       tree.Insert(ob1);
       tree.Insert(ob3);
       tree.Insert(ob5);
       tree.Insert(ob7);
        */

       //insere elementos
       // na ordem de chaves: 4,2,1,6,7,5,3
       tree.Insert(ob4);
       tree.Insert(ob2);
       tree.Insert(ob1); //rotacao direita (4)
       tree.Insert(ob6);
       tree.Insert(ob7); //rotacao esquerda (4)
       tree.Insert(ob5); //rotacao direita (6) esquerda (2)
       tree.Insert(ob3);

       TreeVisitor v;
	   std::cout << "Percurso em Ordem" << std::endl;
	   tree.DepthFirstTraversal (*new InOrder (v));
	   std::cout << std::endl;

       //teste de remocao
       tree.Withdraw(ob7);
       tree.Withdraw(ob5);
       tree.Withdraw(ob1);
       tree.Withdraw(ob6); //rotacao esquerda (2) direita (4)

       //mostra arvore
       std::cout << "[*] Arvore: " << std::endl;
       std::cout << tree << std::endl;

       //acha maior elemento
       std::cout << "Max: " << tree.FindMax() << std::endl;

       //acha menor elemento
       std::cout << "Min: " << tree.FindMin() << std::endl;

       //verifica se ob7 esta na arvore
       if(tree.IsMember(ob7))
            std::cout << "ob7 esta na arvore ... " << std::endl;
       else
            std::cout << "ob7 nao esta na arvore ... " << std::endl;

       std::cout << "Find ob4: " << tree.Find(ob4) << std::endl;

	   std::cout << "Percurso em Ordem" << std::endl;
	   tree.DepthFirstTraversal (*new InOrder (v));
	   std::cout << std::endl;

    }
    catch(exception &e){
        cerr << "Caught: " << e.what( ) << endl;
        cerr << "Type: " << typeid( e ).name( ) << endl;
    }

}

int main()
{
	std::cout << "Main" << std::endl;
//	lista1();
//	lista2();
//	lista3();
//	TesteBinaryTree();
	TesteAvl();


	return 0;
}

