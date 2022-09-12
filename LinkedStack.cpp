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

void LinkedStack::anula(){
	delete inicio;
}

Object* LinkedStack::tope(){
	return inicio->getItem();
}

void LinkedStack::mete(Object* item){
	if(inicio == NULL){
		inicio->setItem(item);
		inicio->setAnterior(NULL);
	}
	else{
		Nodo* temp = new Nodo;
		temp = inicio;
		inicio->setItem(item);
		temp->setAnterior(inicio->getAnterior());
		inicio->setAnterior(temp);
		temp->setSiguiente(inicio);
	}
}

Object* LinkedStack::saca(){
	if(inicio != NULL){
		Nodo* temp = inicio;
		Object* tempItem = inicio->getItem();
		inicio = inicio->getAnterior();
		temp = NULL;
		delete temp;
		return tempItem;
	}
	cout << "La Pila esta vacia!";
	return NULL;
}

bool LinkedStack::vacia(){
	return inicio == NULL;
}

void LinkedStack::imprime_pila(){
	if(inicio != NULL){
		Nodo* temp = inicio;
		while(temp){
			cout << temp->getItem()->toString() << " ";
			temp = temp->getAnterior();
		}
	}
	else
		cout << "La Pila esta vacia";
}
