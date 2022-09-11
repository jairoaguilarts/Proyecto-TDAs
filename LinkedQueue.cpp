#include <iostream>
#include "LinkedQueue.h"
using namespace std;

LinkedQueue::LinkedQueue() {
	primero = nullptr;
	ultimo = nullptr;
}

LinkedQueue::~LinkedQueue() {
	if(ultimo)
		delete ultimo;
}

Object* LinkedQueue::frente() {
	if (primero != nullptr) {
		return primero->getItem();
	}
	return nullptr;
}

void LinkedQueue::imprime_cola() {
	if (primero != nullptr) {
		Nodo* temp = this->primero;
		while (temp) {
			cout << temp->getItem()->toString();
			temp = temp->getSiguiente();
		}
	}
	else {
		cout << "La cola esta vacia. " << endl;
	}
}

void LinkedQueue::anula() {
	if (primero)
		delete primero;
	primero = nullptr;
	ultimo = nullptr;
}

Object* LinkedQueue::saca_de_cola() {
	if (primero != nullptr) {
		Nodo* elim = primero;
		Object* item = elim->getItem();
		primero = elim->getSiguiente();
		if (primero != nullptr) {
			primero->setAnterior(nullptr);
			elim->setSiguiente(nullptr);
		}
		return item;
	}
	else {
		return nullptr;
	}
}

void LinkedQueue::pone_en_cola(Object* item) {
	Nodo* nuevo = new Nodo();
	nuevo->setItem(item);
	nuevo->setAnterior(ultimo);
	if (primero != nullptr) {
		ultimo->setSiguiente(nuevo);
		ultimo = nuevo;
	}
	else {
		primero = nuevo;
		ultimo = nuevo;
	}
}

bool LinkedQueue::vacia() {
	return this->primero != nullptr;
}