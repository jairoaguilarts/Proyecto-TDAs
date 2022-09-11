#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "TDAPila.h"

class ArrayStack : public TDAPila {
	public:
		ArrayStack();
		~ArrayStack();
		virtual void anula();		
		virtual Object* tope();		
		virtual void mete(Object*);//push		
		virtual Object* saca();//pop	
		virtual bool vacia();		
		virtual void imprime_pila();
	private:
		Object** array;
		int capacidad; 
		int n;
};
 
#endif