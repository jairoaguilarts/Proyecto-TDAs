#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "TDALista.h"
#include "Nodo.h"

class LinkedList : public TDALista {
	public:
		LinkedList();
		~LinkedList();
		virtual int getSize(); 
		virtual void anula();
		virtual bool inserta(Object*,int);
		virtual Object* siguiente(int);
		virtual Object* anterior(int);
		virtual void append(Object*);
		virtual void imprimir_lista();
		virtual bool suprime(int);
		virtual Object* recupera(int);
		virtual int localiza(Object*);
		virtual Object* primero();
		virtual bool vacia();
	private:
		Nodo* inicio;
		Nodo* final;
		int n;
};

#endif