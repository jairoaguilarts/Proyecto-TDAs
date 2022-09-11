#ifndef NODO_H
#define NODO_H

#include "Object.h"

class Nodo {
	public:
		Nodo();
		~Nodo();
		Nodo* getSiguiente();
		Nodo* getAnterior();
		Object* getItem(); 
		void setSiguiente(Nodo*);
		void setAnterior(Nodo*);
		void setItem(Object*);
	private:
		Nodo* next;
		Object* item;
		Nodo* anterior;
};

#endif