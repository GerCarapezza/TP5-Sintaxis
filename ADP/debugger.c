#include "main.h"

//DEBUGS

extern bool debug;

void debugPilaEntrada(Entradas entrada, EstadosPila top){
  if (debug == true) printf("ENUM palabra: %d \n", entrada);
  if (debug == true) printf("TOP de pila: %d \n", top);
}

void debugTablaDeMovimiento(MOVIMIENTOS enumMovimiento, Entradas entrada, Movimiento movimiento){
  if (debug == true) printf("------------------------------------------------\n");
  if (debug == true) printf("tablaDeMovimientos[%d][%d]: = [%d, %d]\n", enumMovimiento, entrada, movimiento.estado, movimiento.accion);
  if (debug == true) printf("------------------------------------------------\n");
}