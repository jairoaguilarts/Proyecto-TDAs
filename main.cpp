#include <iostream>
#include "ArrayList.h"
#include "LinkedList.h"
#include "ArrayStack.h"
#include "LinkedStack.h"
#include "ArrayQueue.h"
#include "LinkedQueue.h"
#include "Alumno.h"
#include "Simbolo.h"
#include <cstring>
using namespace std;
 
//Prototipos de los menus
int menuPrincipal();
int menuListas();
int menuLista();
int menuPilas();
int menuPila();
int menuQueues();
int menuQueue();
bool verificadorEntrada(char c1);
bool verificadorEntrada(string o);

int main() {
    int opcionMenuPrincipal = menuPrincipal();
    while(opcionMenuPrincipal != 4) {
        switch(opcionMenuPrincipal) {
            case 1: { //Caso de listas
                int opcionLista = menuListas();
                while(opcionLista != 3) {
                    switch(opcionLista) {
                        case 1: { //Caso de ArrayList
                            TDALista *lista = new ArrayList;
                            int opcionAccion = menuLista();
                            while(opcionAccion != 10) {
                                switch(opcionAccion) {
                                    case 1: { //Método para agregar
                                        char resp = 's';
                                        while(resp == 's' || resp == 'S') { //Respuesta de usuario
                                            string nombre, cuenta;
                                            int posicion;
                                            cout << "Ingrese el nombre: ";
                                            cin.ignore();
                                            getline(cin, nombre);
                                            cout << "Ingrese la cuenta: ";
                                            cin >> cuenta;
                                            Object *item = new Alumno(nombre, cuenta);
                                            cout << "Ingrese la posicion: ";
                                            cin >> posicion;
                                            if(lista->inserta(item, posicion)) {
                                                cout << "Elemento ingresado en la lista" << endl;
                                            } else {
                                                cout << "No se pudo ingresar el elemento en la lista" << endl;
                                            }
                                            cout << "¿Desea ingresar otro dato? (S/N): ";
                                            cin >> resp;
                                        }
                                        break;
                                    }
                                    case 2: { //Imprimir los datos de la lista
                                        lista->imprimir_lista();
                                        break;
                                    }
                                    case 3: { //Buscar un alumno por el numero de cuenta ***
                                        string cuenta;
                                        cout << "Ingrese el numero de cuenta: ";
                                        cin >> cuenta;
                                        Object* item = new Alumno(" ", cuenta);
                                        int posicion = lista->localiza(item);
                                        if(posicion != -1) {
                                            cout << "Alumno encontrado en la posicion " << posicion << " de la lista" << endl;
                                        } else {
                                            cout << "No se pudoo encontrar el alumno en la lista" << endl;
                                        }
                                        break;
                                    }
                                    case 4: { //Suprimir elemento
                                        int posicion;
                                        cout << "Ingrese la posicion del elemento que desea eliminar: ";
                                        cin >> posicion;
                                        if(lista->suprime(posicion)) {
                                            cout << "Elemento eliminado" << endl;
                                        } else {
                                            cout << "No se pudo eliminar el elemento" << endl;
                                        }
                                        break;
                                    }
                                    case 5: { //Mostrar al usuario si la lista esta vacia
                                        if(lista->vacia()) {
                                            cout << "La lista está vacia" << endl;
                                        } else {
                                            cout << "La lista no está vacia; contiene " << lista->getSize() << " elementos" << endl;
                                        }
                                        break;
                                    }
                                    case 6: { //Recuperar un elemento con la posicion
                                        int posicion;
                                        cout << "Ingrese la posicion del elemento que desea recuperar: ";
                                        cin >> posicion;
                                        Object* recuperado = lista->recupera(posicion);
                                        if(recuperado) {
                                            cout << "Elemento recuperado: " << recuperado->toString() << endl;
                                        } else {
                                            cout << "No se pudo recuperar nada en la posicion " << posicion << " de la lista" << endl;
                                        }
                                        break;
                                    }
                                    case 7: { //Recuperar el dato siguiente de una posicion ****
                                        int posicion;
                                        cout << "Ingrese la posicion: ";
                                        cin >> posicion;
                                        Object* recuperado = lista->siguiente(posicion);
                                        if(recuperado) {
                                            cout << "Elemento recuperado: " << recuperado->toString() << endl;
                                        } else {
                                            cout << "No se pudo recuperar nada delante de la posicion " << posicion << " de la lista" << endl;
                                        }
                                        break;
                                    }
                                    case 8: { //Recuperar el dato anterior de una posicion ****
                                        int posicion;
                                        cout << "Ingrese la posicion: ";
                                        cin >> posicion;
                                        Object* recuperado = lista->anterior(posicion);
                                        if(recuperado) {
                                            cout << "Elemento recuperado: " << recuperado->toString() << endl;;
                                        } else {
                                            cout << "No se pudo recuperar nada detras de la posicion " << posicion << " de la lista" << endl;
                                        }
                                        break;
                                    }
                                    case 9: { //Vaciar la lista
                                        lista->anula();
                                        cout << "Elementos de la lista eliminados" << endl;
                                        break;
                                    }
                                    default: {
                                        cout << "Opcion invalida" << endl;
                                    }
                                }
                                opcionAccion = menuLista();
                            }
                            break;
                        }
                        case 2: { //LinkedList
                            TDALista *lista = new LinkedList;
                            int opcionAccion = menuLista();
                            while(opcionAccion != 10) {
                                switch(opcionAccion) {
                                    case 1: { //Método para agregar
                                        char resp = 's';
                                        while(resp == 's' || resp == 'S') { //Respuesta de usuario
                                            string nombre, cuenta;
                                            int posicion;
                                            cout << "Ingrese el nombre: ";
                                            cin.ignore();
                                            getline(cin, nombre);
                                            cout << "Ingrese la cuenta: ";
                                            cin >> cuenta;
                                            Object *item = new Alumno(nombre, cuenta);
                                            cout << "Ingrese la posicion: ";
                                            cin >> posicion;
                                            if(lista->inserta(item, posicion)) {
                                                cout << "Elemento ingresado en la lista" << endl;
                                            } else {
                                                cout << "No se pudo ingresar el elemento en la lista" << endl;
                                            }
                                            cout << "¿Desea ingresar otro dato? (S/N): ";
                                            cin >> resp;
                                        }
                                        break;
                                    }
                                    case 2: { //Imprimir los datos de la lista
                                        lista->imprimir_lista();
                                        break;
                                    }
                                    case 3: { //Buscar un alumno por el numero de cuenta ***
                                        string cuenta;
                                        cout << "Ingrese el numero de cuenta: ";
                                        cin >> cuenta;
                                        Object* item = new Alumno(" ", cuenta);
                                        int posicion = lista->localiza(item);
                                        if(posicion != -1) {
                                            cout << "Alumno encontrado en la posicion " << posicion << " de la lista" << endl;
                                        } else {
                                            cout << "No se pudoo encontrar el alumno en la lista" << endl;
                                        }
                                        break;
                                    }
                                    case 4: { //Suprimir elemento
                                        int posicion;
                                        cout << "Ingrese la posicion del elemento que desea eliminar: ";
                                        cin >> posicion;
                                        if(lista->suprime(posicion)) {
                                            cout << "Elemento eliminado" << endl;
                                        } else {
                                            cout << "No se pudo eliminar el elemento" << endl;
                                        }
                                        break;
                                    }
                                    case 5: { //Mostrar al usuario si la lista esta vacia
                                        if(lista->vacia()) {
                                            cout << "La lista está vacia" << endl;
                                        } else {
                                            cout << "La lista no está vacia; contiene " << lista->getSize() << " elementos" << endl;
                                        }
                                        break;
                                    }
                                    case 6: { //Recuperar un elemento con la posicion
                                        int posicion;
                                        cout << "Ingrese la posicion del elemento que desea recuperar: ";
                                        cin >> posicion;
                                        Object* recuperado = lista->recupera(posicion);
                                        if(recuperado) {
                                            cout << "Elemento recuperado: " << recuperado->toString() << endl;
                                        } else {
                                            cout << "No se pudo recuperar nada en la posicion " << posicion << " de la lista" << endl;
                                        }
                                        break;
                                    }
                                    case 7: { //Recuperar el dato siguiente de una posicion
                                        int posicion;
                                        cout << "Ingrese la posicion: ";
                                        cin >> posicion;
                                        Object* recuperado = lista->siguiente(posicion);
                                        if(recuperado) {
                                            cout << "Elemento recuperado: " << recuperado->toString() << endl;
                                        } else {
                                            cout << "No se pudo recuperar nada delante de la posicion " << posicion << " de la lista" << endl;
                                        }
                                        break;
                                    }
                                    case 8: { //Recuperar el dato anterior de una posicion
                                        int posicion;
                                        cout << "Ingrese la posicion: ";
                                        cin >> posicion;
                                        Object* recuperado = lista->anterior(posicion);
                                        if(recuperado) {
                                            cout << "Elemento recuperado: " << recuperado->toString() << endl;
                                        } else {
                                            cout << "No se pudo recuperar nada detras de la posicion " << posicion << " de la lista" << endl;
                                        }
                                        break;
                                    }
                                    case 9: { //Vaciar la lista ****
                                        lista->anula();
                                        cout << "Elementos de la lista eliminados" << endl;
                                        break;
                                    }
                                    default: {
                                        cout << "Opcion invalida" << endl;
                                    }
                                }
                                opcionAccion = menuLista();
                            }
                            break;
                        }
                        default: {
                            cout << "Opcion invalida" << endl;
                        }
                    }
                    opcionLista = 3;
                }
                break;
            }
            case 2: { //Stacks
                int opcionStack = menuPilas();
                while(opcionStack != 3){
                    switch(opcionStack) {
                        case 1: { //ArrayStack
                            TDAPila* stack = new ArrayStack;
                            int opcionAccion = menuPila();
                            while(opcionAccion != 6) {
                                switch(opcionAccion) {
                                    case 1: {
                                        char simbolo;
                                        cout << "Ingrese un simbolo: ";
                                        cin >> simbolo;
                                        Object* item = new Simbolo(simbolo);
                                        stack->mete(item);
                                        cout << "Simbolo agregado al stack" << endl;
                                        break;
                                    }
                                    case 2: {
                                        Object* temp = stack->saca();
                                        if(temp) {
                                            cout << "Simbolo obtenido: " << temp->toString() << endl;
                                        } else {
                                            cout << "Pila vacia" << endl;
                                        }
                                        break;
                                    }
                                    case 3: {
                                        Object* temp = stack->tope();
                                        if(temp) {
                                            cout << "Simbolo en el tope: " << temp->toString() << endl;
                                        } else {
                                            cout << "Pila vacia" << endl;
                                        }
                                        break;
                                    }
                                    case 4: {
                                        if(stack->vacia()) {
                                            cout << "La pila esta vacia" << endl;
                                        } else {
                                            cout << "La pila no esta vacia" << endl;
                                        }
                                        break;
                                    }
                                    case 5: {
                                        stack->imprime_pila();
                                        break;
                                    }
                                    default: {
                                        cout << "Opcion invalida" << endl;
                                    }
                                }
                                opcionAccion = menuPila();
                            }
                            break;
                        }
                        case 2: { //LinkedStack
                            TDAPila* stack = new LinkedStack;
                            int opcionAccion = menuPila();
                            while(opcionAccion != 6) {
                                switch(opcionAccion) {
                                    case 1: {
                                        char simbolo;
                                        cout << "Ingrese un simbolo: ";
                                        cin >> simbolo;
                                        Object* item = new Simbolo(simbolo);
                                        stack->mete(item);
                                        cout << "Simbolo agregado al stack" << endl;
                                        break;
                                    }
                                    case 2: {
                                        Object* temp = stack->saca();
                                        if(temp) {
                                            cout << "Simbolo obtenido: " << temp->toString() << endl;
                                        } else {
                                            cout << "Pila vacia" << endl;
                                        }
                                        break;
                                    }
                                    case 3: {
                                        Object* temp = stack->tope();
                                        if(temp) {
                                            cout << "Simbolo en el tope: " << temp->toString() << endl;
                                        } else {
                                            cout << "Pila vacia" << endl;
                                        }
                                        break;
                                    }
                                    case 4: {
                                        if(stack->vacia()) {
                                            cout << "La pila esta vacia" << endl;
                                        } else {
                                            cout << "La pila no esta vacia" << endl;
                                        }
                                        break;
                                    }
                                    case 5: {
                                        stack->imprime_pila();
                                        break;
                                    }
                                    default: {
                                        cout << "Opcion invalida" << endl;
                                    }
                                }
                                opcionAccion = menuPila();
                            }
                            break;
                        }
                        default :{
                            cout << "Opcion invalida" << endl;
                        }
                    }
                    opcionStack = 3;
                }
                break;
            }
            case 3: { //Queues
                int opcionQueue = menuQueues();
                while(opcionQueue != 3){
                    switch(opcionQueue) {
                        case 1: { //ArrayQueue
                            TDACola* cola = new ArrayQueue;
                            int opcionAccion = menuQueue();
                            while(opcionAccion != 6) {
                                switch(opcionAccion) {
                                    case 1: {
                                        string cuenta, nombre;
                                        cout << "Ingrese la cuenta del alumno: ";
                                        cin >> cuenta;
                                        cout << "Ingrese el nombre del alumno: ";
                                        cin.ignore();
                                        getline(cin, nombre);
                                        Object* alumno = new Alumno(nombre, cuenta);
                                        cola->pone_en_cola(alumno);
                                        cout << "Alumno agregado a la cola" << endl;
                                        break;
                                    }
                                    case 2: {
                                        Object* item = cola->saca_de_cola();
                                        if(item) {
                                            cout << "Turno de " << item->toString() << endl;
                                        } else {
                                            cout << "Cola vacia" << endl;
                                        }
                                        break;
                                    }
                                    case 3: {
                                        Object* item = cola->frente();
                                        if(item) {
                                            cout << "El siguiente en la cola es: " << item->toString() << endl;
                                        } else {
                                            cout << "Cola vacia" << endl;
                                        }
                                        break;
                                    }
                                    case 4: {
                                        if(!cola->vacia()) {
                                            cout << "La cola no está vacia" << endl;
                                        } else {
                                            cout << "La cola está vacia" << endl;
                                        }
                                        break;
                                    }
                                    case 5: {
                                        cola->imprime_cola();
                                        break;
                                    }
                                    default: {
                                        cout << "Opcion invalida" << endl;
                                    }
                                }
                                opcionAccion = menuQueue();
                            }
                            break;
                        }
                        case 2: { //LinkedQueue
                            TDACola* cola = new ArrayQueue;
                            int opcionAccion = menuQueue();
                            while(opcionAccion != 6) {
                                switch(opcionAccion) {
                                    case 1: {
                                        string cuenta, nombre;
                                        cout << "Ingrese la cuenta del alumno: ";
                                        cin >> cuenta;
                                        cout << "Ingrese el nombre del alumno: ";
                                        cin.ignore();
                                        getline(cin, nombre);
                                        Object* alumno = new Alumno(nombre, cuenta);
                                        cola->pone_en_cola(alumno);
                                        cout << "Alumno agregado a la cola" << endl;
                                        break;
                                    }
                                    case 2: {
                                        Object* item = cola->saca_de_cola();
                                        if(item) {
                                            cout << "Turno de " << item->toString() << endl;
                                        } else {
                                            cout << "Cola vacia" << endl;
                                        }
                                        break;
                                    }
                                    case 3: {
                                        Object* item = cola->frente();
                                        if(item) {
                                            cout << "El siguiente en la cola es: " << item->toString() << endl;
                                        } else {
                                            cout << "Cola vacia" << endl;
                                        }
                                        break;
                                    }
                                    case 4: {
                                        if(!cola->vacia()) {
                                            cout << "La cola no está vacia" << endl;
                                        } else {
                                            cout << "La cola está vacia" << endl;
                                        }
                                        break;
                                    }
                                    case 5: {
                                        cola->imprime_cola();
                                        break;
                                    }
                                    default: {
                                        cout << "Opcion invalida" << endl;
                                    }
                                }
                                opcionAccion = menuQueue();
                            }
                            break;
                        }
                        default :{
                            cout << "Opcion invalida" << endl;
                        }
                    }
                    opcionQueue = 3;
                }
                break;
            }
            default : {
                cout << "Opcion invalida" << endl;
            }
        }
        opcionMenuPrincipal = menuPrincipal();
    }
    return 0;
}

//Implementaciones de los menus 
int menuPrincipal() {
    int opcion;
    char opc;
    cout << "====MENU PRINCIPAL====" << endl;
    cout << "1) Trabajar con Listas" << endl;
    cout << "2) Trabajar con Pilas" << endl;
    cout << "3) Trabajar con Colas" << endl;
    cout << "4) Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opc;
    while(!verificadorEntrada(opc)){
        cout << "Entrada invalida: ";
        cin >> opc;
    }
    opcion = opc - '0';
    return opcion;
}

int menuListas() {
    int opcion;
    char opc;
    cout << "====LISTAS====" << endl;
    cout << "1) Trabajar con ArrayList" << endl;
    cout << "2) Trabajar con LinkedList" << endl;
    cout << "3) Regresar al menu principal" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opc;
    while(!verificadorEntrada(opc)){
        cout << "Entrada invalida: ";
        cin >> opc;
    }
    opcion = opc - '0';
    return opcion;
}

int menuLista() {
    int opcion;
    string opc;
    char c1, c2;
    cout << "====MENU LISTA====" << endl;
    cout << "1) Insertar elemento" << endl;
    cout << "2) Imprimir elementos" << endl;
    cout << "3) Buscar elemento" << endl;
    cout << "4) Borrar elemento" << endl;
    cout << "5) Ver si está vacia" << endl;
    cout << "6) Obtener elemento por posicion" << endl;
    cout << "7) Obtener siguiente" << endl;
    cout << "8) Obtener anterior" << endl;
    cout << "9) Anular lista" << endl;
    cout << "10) Regresar al menu principal" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opc;
    while(!verificadorEntrada(opc)){
        cout << "Entrada invalida: ";
        cin >> opc;
    }
    opcion = stoi(opc);
    return opcion;
}

int menuPilas() {
    int opcion;
    char opc;
    cout << "====PILAS====" << endl;
    cout << "1) Trabajar con ArrayStack" << endl;
    cout << "2) Trabajar con LinkedStack" << endl;
    cout << "3) Regresar al menu principal" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opc;
    while(!verificadorEntrada(opc)){
        cout << "Entrada invalida: ";
        cin >> opc;
    }
    opcion = opc - '0';
    return opcion;
}

int menuPila() {
    int opcion;
    char opc;
    cout << "====MENU PILA====" << endl;
    cout << "1) Push" << endl;
    cout << "2) Pop" << endl;
    cout << "3) Top" << endl;
    cout << "4) Verificar si esta vacia" << endl;
    cout << "5) Imprimir elementos" << endl;
    cout << "6) Regresar al menu principal" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opc;
    while(!verificadorEntrada(opc)){
        cout << "Entrada invalida: ";
        cin >> opc;
    }
    opcion = opc - '0';
    return opcion;
}

int menuQueues()  {
    int opcion;
    char opc;
    cout << "====COLAS====" << endl;
    cout << "1) Trabajar con ArrayQueue" << endl;
    cout << "2) Trabajar con LinkedQueue" << endl;
    cout << "3) Regresar al menu principal" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    while(!verificadorEntrada(opc)){
        cout << "Entrada invalida: ";
        cin >> opc;
    }
    opcion = opc - '0';
    return opcion;
}

int menuQueue() {
    int opcion;
    char opc;
    cout << "====MENU QUEUE====" << endl;
    cout << "1) Queue" << endl;
    cout << "2) De-Queue" << endl;
    cout << "3) Peek" << endl;
    cout << "4) Verificar si esta vacia" << endl;
    cout << "5) Imprimir elementos" << endl;
    cout << "6) Regresar al menu principal" << endl;
    cout << "Ingrese su opcion: ";
    cin >> opc;
    while(!verificadorEntrada(opc)){
        cout << "Entrada invalida: ";
        cin >> opc;
    }
    opcion = opc - '0';
    return opcion;
}

bool verificadorEntrada(char c){
    if(c >= 48 && c <= 57)
        return true;
    return false;
}
bool verificadorEntrada(string opc){
    char c1, c2;
    c1 = opc[0]; c2 = opc[1];
    if(opc.length() == 1){
        if(c1 >= 48 && c1 <= 57)
            return true;
    }
    else{
        if(c1 >= 48 && c1 <= 57 && c2 >= 48 && c2 <= 57)
            return true;
    }
    return false;
}
