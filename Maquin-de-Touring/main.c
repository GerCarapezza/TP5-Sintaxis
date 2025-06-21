#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool debug = true;
char* alfabeto = "acde";

const char *RED = "\033[1;31m";
const char *GREEN = "\033[1;32m";
const char *RESET = "\033[0m";

Estados estadoActual = E0;

int main() {

  char palabra[50];
  printf("Ingrese una palabra a verificar... ");
  scanf("%s", &palabra);
  
  char* cinta = crearCinta(palabra);

  //if (debug == true)  printf("Estado de la cinta: %s%s%s\n", GREEN, cinta, RESET);

  /*Validamos si la palabra pertence al lenguaje*/
  bool validacion = verificarMT(cinta);

  if (validacion)  printf("%s La palabra %s%s%s es valida.%s \n", GREEN, RESET, palabra, GREEN, RESET);
  if (!validacion) printf("%s La palabra %s%s%s, NO es reconocida por el lenguaje.%s \n", RED, RESET, palabra, RED, RESET);

  return 0;
}

void accionar(int escritura, Movimiento direccion, Estados nuevoEstado, char* cinta, int* indice){
  cinta[*indice] = escritura;
  estadoActual = nuevoEstado;
  if (direccion == IZQUIERDA) *indice = *indice - 2;
}

bool verificarMT(char* cinta){
  int longitudCinta = strlen(cinta);
  if (debug == true) printf("longitudCinta: %d\n", longitudCinta);
  for (int i = 1; i < longitudCinta + 1; i++)
  {
    if (debug == true)  printf("EstadoActual: %s%d%s\nEstado de la cinta: %s%s%s\n", GREEN, estadoActual, RESET, GREEN, cinta, RESET);
    switch (estadoActual){
      case E0:
        if (cinta[i] == 'a' ) {
          accionar('X', DERECHA, E1, cinta, &i);
          break;
        };
        if (cinta[i] == 'Y' ) {
          accionar('Y', DERECHA, E7, cinta, &i);
          break;
        };
        break;
      case E1:
        if (cinta[i] == 'a' ) {
          accionar('a', DERECHA, E1, cinta, &i);
          break;
        };
        // printf("Lectura E1: %c\n", cinta[i]);
        // printf("%c == %c\n", cinta[i], 99);
        if (cinta[i] == 'c' ) {
          accionar('Y', DERECHA, E2, cinta, &i);
          break;
        };
        if (cinta[i] == 'Y' ) {
          accionar('Y', DERECHA, E5, cinta, &i);
          break;
        };
        break;
      case E2:
        if (cinta[i] == 'c' ) {
          accionar('c', DERECHA, E2, cinta, &i);
          break;
        };
        if (cinta[i] == 'd' ) {
          accionar('W', DERECHA, E3, cinta, &i);
          break;
        };
        if (cinta[i] == 'W' ) {
          accionar('W', DERECHA, E3, cinta, &i);
          break;
        };
        break;
      case E3:
        if (cinta[i] == 'e' ) {
          accionar('Z', IZQUIERDA , E4, cinta, &i);
          break;
        };
        if (cinta[i] == 'Z' ) {
          accionar('Z', DERECHA   , E6, cinta, &i);
          break;
        };
        break;
      case E4:
        if (cinta[i] == 'a' ) {
          accionar('a', IZQUIERDA , E4, cinta, &i);
          break;
        };
        if (cinta[i] == 'c' ) {
          accionar('c', IZQUIERDA , E4, cinta, &i);
          break;
        };
        if (cinta[i] == 'Z' ) {
          accionar('Z', IZQUIERDA , E4, cinta, &i);
          break;
        };
        if (cinta[i] == 'Y' ) {
          accionar('Y', IZQUIERDA , E4, cinta, &i);
          break;
        };
        if (cinta[i] == 'W' ) {
          accionar('W', IZQUIERDA , E4, cinta, &i);
          break;
        };
        if (cinta[i] == 'X' ) {
          accionar('X', DERECHA   , E0, cinta, &i);
          break;
        };
        break;
      case E5:
        if (cinta[i] == 'c' ) {
          accionar('Y', DERECHA, E2, cinta, &i);
          break;
        };
        if (cinta[i] == 'Y' ) {
          accionar('Y', DERECHA, E5, cinta, &i);
          break;
        };
        break;
      case E6:
        if (cinta[i] == 'e' ) {
          accionar('Z', IZQUIERDA , E4, cinta, &i);
          break;
        };
        if (cinta[i] == 'Z' ) {
          accionar('Z', DERECHA   , E6, cinta, &i);
          break;
        };
        break;
      case E7:
        if (cinta[i] == 'Y' ) {
          accionar('Y', DERECHA, E7, cinta, &i);
          break;
        };
        if (cinta[i] == 'W' ) {
          accionar('W', DERECHA, E8, cinta, &i);
          break;
        };
        break;
      case E8:
        accionar('Z', DERECHA, E9, cinta, &i);
        break;
      case E9:
        if (cinta[i] == 'Z' ) {
          accionar('Z', DERECHA, E9, cinta, &i);
          break;
        };
        if (cinta[i] == 'B' ) {
          accionar('B', DERECHA, E10, cinta, &i);
          break;
        };
        break;
      case E10:
        return true;
        break;
    }
  }

  return false;
}

char* crearCinta(char palabra[]){
  int longitud = strlen(palabra);
  char* nuevaCinta = malloc(longitud + 2);

  for (int i = 0; i < (longitud + 2); i++){
    if (i == 0) {
      nuevaCinta[0] = 'B';
      continue;
    };
    if (i == longitud + 1) {
      nuevaCinta[longitud + 1] = 'B';
      continue;
    };
    nuevaCinta[i] = palabra[i - 1];
  }
  nuevaCinta[longitud + 2] = '\0';
  return nuevaCinta;
}