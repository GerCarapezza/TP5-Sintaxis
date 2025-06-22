#include "main.h"

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

bool verificarMT(char* cinta){
  int longitudCinta = strlen(cinta);
  
  if (debug == true) printf("longitudCinta: %d\n", longitudCinta);

  for (int i = 1; i < longitudCinta + 1; i++){
    if (debug == true)  printf("EstadoActual: %s%d%s\nEstado de la cinta: %s%s%s\n", GREEN, estadoActual, RESET, GREEN, cinta, RESET);
    
    switch (estadoActual){
      case E0:
        ejecutarE0(cinta, &i);
        break;
      case E1:
        ejecutarE1(cinta, &i);
        break;
      case E2:
        ejecutarE2(cinta, &i);
        break;
      case E3:
        ejecutarE3(cinta, &i);
        break;
      case E4:
        ejecutarE4(cinta, &i);
        break;
      case E5:
        ejecutarE5(cinta, &i);
        break;
      case E6:
        ejecutarE6(cinta, &i);
        break;
      case E7:
        ejecutarE7(cinta, &i);
        break;
      case E8:
        ejecutarE8(cinta, &i);
        break;
      case E9:
        ejecutarE9(cinta, &i);
        break;
      case E10:
        return true;
        break;
    }
  }

  return false;
}


void accionar(int escritura, Movimiento direccion, Estados nuevoEstado, char* cinta, int* indice){
  cinta[*indice] = escritura;
  estadoActual = nuevoEstado;
  if (direccion == IZQUIERDA) *indice = *indice - 2;
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