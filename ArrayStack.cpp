#include "ArrayStack.h"
#include <iostream>
using namespace std;

#define NULL 0

ArrayStack::ArrayStack(){
	n = 0;
	capacidad = 10;
	array = new Object*[capacidad];
	for(int i = 0; i < capacidad; i++)
		array[i] = NULL;
}

ArrayStack::~ArrayStack(){
	//libera el contenido de las casillas
	for(int i = 0; i<capacidad; i++){
		if(array[i]){
			delete array[i];
		}
	}
	//libera el arreglo
	delete[] array;
} 

void ArrayStack::anula(){
	for (int i = n - 1; i >= 0; i--){
		array[i] = NULL;
	}
	n = 0;
}

Object* ArrayStack::tope(){
	return array[n - 1];
}

void ArrayStack::mete(Object* item){
	if(n == capacidad){
		capacidad += 15;
		Object** temp = new Object*[capacidad];
		for (int i = 0; i < n; i++) {
			temp[i] = array[i];
		}
		delete[] array;
		array = temp;
	}
	if(item != NULL){
		array[n - 1] = item;
		n++;
	}
	else
		cout << "var tipo Object nulo";
}

Object* ArrayStack::saca(){
	if(n != 0){
		Object* temp = array[n - 1];
		delete array[n - 1];
		n--;
		return temp;
	}
	cout << "La Pila esta vacia";
	return NULL;
}

bool ArrayStack::vacia(){
	return n == 0;
}

void ArrayStack::imprime_pila(){
	if(n == 0)
		cout << "La Pila esta vacia";
	else{
		for (int i = 0; i < n; i++){
			cout << endl;
			cout << "-> " << array[i]->toString(); 
		}
		cout << endl;
	}
}
