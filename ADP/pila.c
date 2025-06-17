#include "main.h"

Nodo* crearNodo(EstadosPila valor){
  Nodo* nuevoNodo = malloc(sizeof(Nodo));

  nuevoNodo->dato = valor;
  nuevoNodo->sgt = NULL;

  return nuevoNodo;
}

void push(Nodo** pila, EstadosPila valor){
  Nodo* nuevoNodo = crearNodo(valor);

  nuevoNodo->sgt = *pila;
  (*pila) = nuevoNodo; 
}

EstadosPila pop(Nodo** pila){
  if(pila == NULL) return -1;

  EstadosPila valor = (*pila)->dato;
  Nodo* temp = *pila;
  (*pila) = (*pila)->sgt;
  
  free(temp);

  return valor;
}