#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "TDAPila.h"

#include "Nodo.h"

class LinkedStack : public TDAPila {
	public:
		LinkedStack();
		~LinkedStack();
		virtual void anula();		
		virtual Object* tope();		
		//Push		
		virtual void mete(Object*);
		//Pop
		virtual Object* saca();	
		virtual bool vacia();		
		virtual void imprime_pila();
	private:
		Nodo* inicio;
}; 

#endif