#include "ArrayStack.h"

#define NULL 0

ArrayStack::ArrayStack()
{
	n=0;
	capacidad = 10;
	array = new Object*[capacidad];
	for(int i=0; i<capacidad;i++)
		array[i] = NULL;
}

ArrayStack::~ArrayStack()
{
		//libera el contenido de las casillas
	for(int i=0; i<capacidad; i++){
		if(array[i]){
			delete array[i];
		}
	}
	//libera el arreglo
	delete[] array;
} 