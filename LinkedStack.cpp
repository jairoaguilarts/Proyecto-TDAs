#include "LinkedStack.h"
#include <iostream>
using namespace std;

LinkedStack::LinkedStack() {
	inicio = nullptr;
}

LinkedStack::~LinkedStack() {
	if(inicio)
		delete inicio;
} 

void LinkedStack::anula() {
	delete inicio;
}

Object* LinkedStack::tope() {
	return inicio->getItem();
}

void LinkedStack::mete(Object* item){
	Nodo* newNode = new Nodo;
	newNode->setItem(item);
	if(inicio == nullptr){
		inicio = newNode;
	} else {
		newNode->setAnterior(inicio);
		inicio->setSiguiente(newNode);
		inicio = newNode;
	}
}

Object* LinkedStack::saca() {
	if(inicio != nullptr){
		Nodo* temp = inicio;
		Object* tempItem = inicio->getItem();
		inicio = inicio->getAnterior();
		temp = nullptr;
		delete temp;
		return tempItem;
	}
	return nullptr;
}

bool LinkedStack::vacia() {
	return inicio == nullptr;
}

void LinkedStack::imprime_pila() {
	if(inicio != nullptr){
		Nodo* temp = inicio;
		while(temp){
			cout << "->" << temp->getItem()->toString() << endl;
			temp = temp->getAnterior();
		}
	}
	else
		cout << "La Pila esta vacia" << endl;
}
