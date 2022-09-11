#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "TDACola.h"

class ArrayQueue : public TDACola {
	private:
		int capacidad, n, inicio, fin;
		Object** array;
	public:
		ArrayQueue();
		~ArrayQueue();
		virtual Object* frente();
		virtual void imprime_cola();
		virtual void anula();
		//Dequeue
		virtual Object* saca_de_cola(); 
		//Queue
		virtual void pone_en_cola(Object*);
		virtual bool vacia();
};

#endif