#include "LinkedStack.h"

LinkedStack::LinkedStack() {
	inicio = nullptr;
}

LinkedStack::~LinkedStack() {
	if(inicio)
		delete inicio;
} 