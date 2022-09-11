#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "TDALista.h"
using namespace std;

class ArrayList : public TDALista {
	public:
		ArrayList();
		~ArrayList();
		int getSize();
		void anula();
		bool inserta(Object*,int);
		Object* siguiente(int);
		Object* anterior(int);
		void append(Object*);
		void imprimir_lista();
		bool suprime(int);
		Object* recupera(int);
		int localiza(Object*);
		Object* primero();
		bool vacia();
	private:
		Object** array;
		int capacidad;
		int n;
};

#endif
