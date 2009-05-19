/*
 *
 * Lista de exercícios Estrutura de dados
 * Alunos: Fabricio Ferracioli
 *         Moisés Fernando Lima
 *
 */


#include "Array.h"
#include "ListElement.h"
#include "LinkedList.h"
#include "Array2D.h"
//#include "Array3D.h"
#include "SinglyLinkedList.h"
#include "LinkedListSentinel.h"
#include "RowVector.h"
#include "ColumnVector.h"
#include <iostream>

void ex1(){
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

void ex2()
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

void ex3()
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

void ex4()
{

    std::cout << "Exercicio 04" << std::endl << std::endl;

    //criando uma lista
    LinkedListSentinel<int> lista;

    //testando inserção de elementos
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

void ex5()
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

//void ex6()
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

void ex7()
{
	std::cout << "Exercicio 07" << std::endl << std::endl;

	RowVector<int> row(5);
	for (unsigned int i = 0; i < 5; i++)
	{
		row[0][i] = 4 * i;
	}
	for (unsigned int i = 0; i < 5; i++)
	{
		std::cout << "Row[0][" << i << "] " << row[0][i] << std::endl;
	}

	ColumnVector<int> column(5);
	for (unsigned int i = 0; i < 5; i++)
	{
		column[i][0] = 23 * i;
	}
	for (unsigned int i = 0; i < 5; i++)
	{
		std::cout << "Column[" << i << "][0] " << column[i][0] << std::endl;
	}
}

int main()
{

    ex1();

    ex2();

    ex3();

    ex4();

    ex5();

//    ex6();

    ex7();

    return 0;
}
