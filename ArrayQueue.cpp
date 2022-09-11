#include <iostream>
#include "ArrayQueue.h"
using namespace std;
 
ArrayQueue::ArrayQueue() {
	inicio = 0;
	fin = 0;
	n = 0;
	capacidad = 10;
	array = new Object*[capacidad];
	for(int i = 0; i < capacidad; i++)
		array[i] = nullptr;
}

ArrayQueue::~ArrayQueue() {
	for(int i = 0; i < capacidad; i++){
		if(array[i]){
			delete &array[i];
		}
	}
	//libera el arreglo
	delete[] array;
}

Object* ArrayQueue::frente() {
	if (n){
		return array[inicio-1];
	}
	return nullptr;
}

void ArrayQueue::imprime_cola() {
	if (n) {
		int pos = inicio;
		for (int i = 0; i < n; i++) {
			cout << array[pos-1]->toString();
			if (pos == capacidad) {
				pos = 1;
			} else {
				pos++;
			}
		}
		cout << endl;
	}
	else {
		cout << "La cola esta vacia" << endl;
	}
}

Object* ArrayQueue::saca_de_cola() {
	if (n) {
		Object* item = array[inicio - 1];
		array[inicio - 1] = NULL;
		if (inicio == fin) {
			inicio = fin = 0;
		}
		else if (inicio == capacidad) {
			inicio = 1;
		}
		else {
			inicio++;
		}
		n--;
		return item;
	}
	else {
		return nullptr;
	}
}

void ArrayQueue::pone_en_cola(Object* item) {
	if (item != nullptr) {
		if (n == capacidad-1) {
			capacidad += 10;
			Object** aux = new Object * [capacidad];
			int pos = inicio;
			for (int i = 0; i < n; i++) {
				aux[i] = array[pos-1];
				if (pos == n+1) {
					pos = 1;
				} else {
					pos++;
				}
			}
			inicio = 1;
			fin = this->n;
			delete[] array;
			array = aux;
		}
		if (inicio == 0) {
			inicio = fin = 1;
			array[fin - 1] = item;
		} else if (fin == capacidad) {
			fin = 1;
			array[fin - 1] = item;
		} else {
			fin++;
			array[fin - 1] = item;
		}
		n++;
	}
}

bool ArrayQueue::vacia() {
	if (n) {
		return false;
	}
	return true;
}

void ArrayQueue::anula() {
	for (int i = capacidad-1; i >= 0; i--) {
		array[i] = nullptr;
	}
	n = 0;
	inicio = 0;
	fin = 0;
}
