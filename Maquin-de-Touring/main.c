#include "main.h"

bool debug = false;
char* alfabeto = "acde";

const char *RED = "\033[1;31m";
const char *GREEN = "\033[1;32m";
const char *RESET = "\033[0m";

Estados estadoActual = E0;

int main() {

  char palabra[50];
  printf("Ingrese una palabra a verificar... ");
  scanf("%s", &palabra);
  
  char* cinta = crearCinta(palabra); //crearCinta retorna un string con la palabra ingresada pero con B (representacion del vacio) en los extremos

  if (debug == true)  printf("Estado de la cinta: %s%s%s\n", GREEN, cinta, RESET);

  /*Validamos si la palabra pertence al lenguaje*/
  bool validacion = verificarMT(cinta);

  if (validacion)  printf("%s La palabra %s%s%s es valida.%s \n", GREEN, RESET, palabra, GREEN, RESET);
  if (!validacion) printf("%s La palabra %s%s%s, NO es reconocida por el lenguaje.%s \n", RED, RESET, palabra, RED, RESET);

  return 0;
}

bool verificarMT(char* cinta){ //retorna un booleando que determima si es o no aceptada la palabra; recibe ls cinta en formato string
  int longitudCinta = strlen(cinta); //consigo la longitud de la cinta
  
  if (debug == true) printf("longitudCinta: %d\n", longitudCinta);

  /*este bucle for cumple la funcionalidad de la cinta, representado al head con i*/
  for (int i = 1; i < longitudCinta + 1; i++){
    if (debug == true)  printf("EstadoActual: %s%d%s\nEstado de la cinta: %s%s%s\n", GREEN, estadoActual, RESET, GREEN, cinta, RESET);
    
    switch (estadoActual){//Dependiendo del estado actual se validara las entradas que puede recibir 
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

/*accionar (caracter a escribir en ascii; direccion[Derecha o izquierda]; nuevo valor de estado[enum Estados]; cinta en formato string; la direccion del indicie para poder retrodecer de ser necesario)*/
void accionar(int escritura, Movimiento direccion, Estados nuevoEstado, char* cinta, int* indice){
  cinta[*indice] = escritura; //escribimos en la poscion del head, head es i
  estadoActual = nuevoEstado; //actualizamos el estado al siguiente
  if (direccion == IZQUIERDA) *indice = *indice - 2; //en caso de retroceder restamos 2 al head (1 porque al finalizar el ciclo for se sumara 1 y otro porque queremos retroceder)
}

char* crearCinta(char palabra[]){//Devuelve cinta con los vacios y recive la palabra ingresada
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