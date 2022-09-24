#include "LinkedList.h"
#include "Alumno.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
	inicio = nullptr;
	final = nullptr;
	n = 0; 
}

LinkedList::~LinkedList() {
	if(inicio)
		delete inicio;
}

int LinkedList::getSize() {
	return n;
}

void LinkedList::append(Object* item) {
	Nodo* newNode = new Nodo;
	newNode->setItem(item);
	this->final->setSiguiente(newNode);
	newNode->setAnterior(this->final);
	this->final = newNode;
	n++; 
}

bool LinkedList::inserta(Object* item, int posicion) {
	if(posicion >= 1 && posicion <= n + 1) {
		if(posicion == 1) {
			Nodo* newNode = new Nodo;
			newNode->setItem(item);
			if(n == 0) {
				inicio = newNode;
				final = newNode;
				n++;
			} else {
				inicio->setAnterior(newNode);
				newNode->setSiguiente(inicio);
				inicio = newNode;
				n++;
			}
		} else if(posicion == n + 1) {
			append(item);
		} else {
			Nodo* newNode = new Nodo;
			newNode->setItem(item);
			Nodo* temp = inicio;
			for(int i = 1; i <= posicion; i++) {
				if(i == posicion) {
					temp->getAnterior()->setSiguiente(newNode);
					newNode->setAnterior(temp->getAnterior());
					newNode->setSiguiente(temp);
					temp->setAnterior(newNode);
				} else {
					temp = temp->getSiguiente();
				}
			}
			n++;
		}
		return true;
	}
	return false;
}

bool LinkedList::suprime(int posicion) {
	if(posicion >= 1 && posicion <= n) {
		if(posicion == 1) {
			Nodo* temp = this->inicio;
			this->inicio = this->inicio->getSiguiente();
			temp->setSiguiente(nullptr);
			if(n != 1) {
				this->inicio->setAnterior(nullptr);
			}
		} else if(posicion == n) {
			Nodo* temp = this->final;
			this->final = this->final->getAnterior();
			this->final->setSiguiente(nullptr);
			temp->setAnterior(nullptr); 
		} else {
			Nodo* temp = this->inicio;
			for(int i = 1; i < posicion; i++) {
				temp = temp->getSiguiente();
			}
			temp->getAnterior()->setSiguiente(temp->getSiguiente());
			temp->getSiguiente()->setAnterior(temp->getAnterior());
			temp->setSiguiente(nullptr);
			temp->setAnterior(nullptr);
		}
		n--;
		return true;
	}
	return false;
}

void LinkedList::anula() {
	if (inicio)
		delete inicio;
	inicio = nullptr;
	final = nullptr;
	n = 0;
}

Object* LinkedList::recupera(int posicion) {
	if(posicion >= 1 && posicion <= n) {
		Nodo* tempNodo = this->inicio;
		for(int i = 1; i < posicion; i++) {
			tempNodo = tempNodo->getSiguiente();
		}
		return tempNodo->getItem();
	}
	return nullptr;
}

Object* LinkedList::siguiente(int posicion) {
	return recupera(posicion + 1);
}

Object* LinkedList::anterior(int posicion) {
	return recupera(posicion - 1);
}

bool LinkedList::vacia() {
	return inicio == nullptr;
}

Object* LinkedList::primero() {
	return inicio->getItem();
}

int LinkedList::localiza(Object* item) {
	int index = -1;
	Nodo* temp = this->inicio;
	for(int i = 1; i <= n; i++) {
		if(dynamic_cast<Alumno*>(temp->getItem())->getCuenta() == dynamic_cast<Alumno*>(item)->getCuenta()) {
			index = i;
			break;
		}
		temp = temp->getSiguiente();
	}
	return index;
}

void LinkedList::imprimir_lista() {
	if(n > 0) {
		Nodo* temp = this->inicio;
		for(int i = 1; i <= n; i++) {
			cout << i << ") " << temp->getItem()->toString() << endl;
			temp = temp->getSiguiente();
		} 
	} else {
		cout << "La lista está vacia" << endl;
	}
}
