#include "Nodo.h"


Nodo::Nodo() {
	next = nullptr;
	item = nullptr;
	anterior = nullptr;
	 
}

Nodo::~Nodo() {
	if(anterior) {
		delete anterior;
	}
	if(next) {
		delete next;
	}
	if(item) {
		delete item;
	}		
}

Nodo* Nodo::getAnterior() {
	return anterior;
}

Nodo* Nodo::getSiguiente() {
	return next;
}

Object* Nodo::getItem() {
	return item;
}

void Nodo::setSiguiente(Nodo* siguiente) {
	this->next = siguiente;
}

void Nodo::setAnterior(Nodo* anterior) {
	this->anterior = anterior;
}

void Nodo::setItem(Object* item) {
	this->item = item;
}