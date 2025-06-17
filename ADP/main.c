#include "main.h"


bool debug = false;
char* alfabeto = "abc";

const char *RED = "\033[1;31m";
const char *GREEN = "\033[1;32m";
const char *RESET = "\033[0m";

/*Tabla de movimientos*/
Movimiento tablaDeMovimientos[5][4] = { 
                                    {{E0, R$},  {-1, -1},  {-1, -1}, {-1, -1}},
                                    {{E0, RR},  {-1, -1},  {E1, R},  {-1, -1}},
                                    {{-1, -1},  {E2, e},   {-1, -1}, {-1, -1}},
                                    {{-1, -1},  {E2, e},   {-1, -1}, {-1, -1}},
                                    {{-1, -1},  {-1, -1},  {-1, -1}, {E2, e}}};


int main(){
  char palabra[50];
  printf("Ingrese una palabra a verificar... ");
  scanf("%s", &palabra);

  /*Validamos si la palabra pertence al lenguaje*/
  bool validacion = verificarADP(palabra);

  if (validacion)  printf("%s La palabra %s%s%s es valida.%s \n", GREEN, RESET, palabra, GREEN, RESET);
  if (!validacion) printf("%s La palabra %s%s%s, NO es reconocida por el lenguaje.%s \n", RED, RESET, palabra, RED, RESET);

  return 0;
}

//Funciones

bool verificarADP (char palabra[]){
  bool resultado = true; //Valor a retornar que determinar si se cumple o no con el lenguaje
  int longitud = strlen(palabra);//Cantidad de caracteres a validar en el lenguaje

  if (debug == true) printf("palabra: %s \n", palabra);
  
  Estados estadoActual = E0;    //Estados iniciales {estado 0 y $ en la pila}
  Nodo* pila = crearNodo(PESOS);
  
  int cantidadDeC = 0;

  for (int i = 0; i < longitud; i++){             //Recorremos la palabra validad con el lenguaje
    Entradas entrada = identificarEntrada(palabra[i]);//identificamos la letra si es que pertenece al alfabeto
    EstadosPila top = pop(&pila);                     //identificamos valores actuales de la pila y estados para ubicarnos en la tabla
    MOVIMIENTOS enumMovimiento = identificarMovimiento(estadoActual, top);

    debugPilaEntrada(entrada, top);

    if (i == 0 && entrada != A){            //Si no comienza con a, no pertenece al lenguaje
      if (debug == true) printf("ERROR\n");
      resultado = false;
      break;
    }
    
    Movimiento movimiento = tablaDeMovimientos[enumMovimiento][entrada];  //Accedemos a la tabla de movimiento

    debugTablaDeMovimiento(enumMovimiento, entrada, movimiento);  //tablaDeMovimientos[E0$][A] ejemplo de acceso para el caso donde al leer una A, encontramos $ en el top de la pila en el estado 0

    estadoActual = movimiento.estado;//Actualizar estado
      
    if (movimiento.estado == -1 || movimiento.accion == -1){  //en la tabla se representa el caso de error como {-1, -1}
      resultado = false;
      break;
    }

    ejecutarAccion (movimiento, &pila, top);
  }

  EstadosPila top = pop(&pila);
  if (top != PESOS) resultado = false;

  return resultado;
}

void ejecutarAccion (Movimiento movimiento, Nodo** pila, EstadosPila top){
  /*Si la entrada es permitida, actulizamos el estado al siguiente y realizamos la accion*/
  /*ejemplo:*/
  /*para una entrada A en el estado 0 con pila vacia (fila: e0,$ ; columna: a) -- Ver Lucidchart --*/
  /*Realizamos la siguiente accion: e0,R$*/
  /*quiere decir que mantendremos el estado 0 y que volveremos a colocar el $ a la pila con el nuevo caracter R*/
  switch (movimiento.accion)//ejecutar accion (R, RR, R$, ...)
  {
    case R://agregamos el elemento consumido dejando la pila en el mismo estado anterior
      if (debug == true) printf("ACCION: R \n");
      push(pila, top);
      break;
    case R$://devolvemos el $ a la pila y agregamos un nuevo elemento R
      if (debug == true) printf("ACCION: R$ \n");
      push(pila, top);
      push(pila, E_R);
      break;
    case RR://devolvemos el elemento R consumido y agregamos otro
      if (debug == true) printf("ACCION: RR \n");
      push(pila, E_R);
      push(pila, top);
      break;
    case e://no devolvemos el elemento consumido (solo sacamos de la pila)
      if (debug == true) printf("ACCION: e \n");
      break;
  }
}

Entradas identificarEntrada(char letra){
  if (debug == true) printf("letra: %c ; alfabeto: %c\n", letra, alfabeto[0]);
  if(alfabeto[0] == letra)      return A;
  else if(alfabeto[1] == letra) return B;
  else if(alfabeto[2] == letra) return C;
  return -1;
}

MOVIMIENTOS identificarMovimiento (Estados estadoActual, EstadosPila top){

  if (estadoActual == E0 && top == PESOS) return E0PESOS;
  if (estadoActual == E0 && top == E_R) return E0R;
  if (estadoActual == E1 && top == E_R) return E1R;
  if (estadoActual == E2 && top == E_R) return E2R;
  if (estadoActual == E2 && top == PESOS) return E2PESOS;
}

//Funciones de Pila

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

//DEBUGS

void debugPilaEntrada(Entradas entrada, EstadosPila top){
  if (debug == true) printf("ENUM palabra: %d \n", entrada);
  if (debug == true) printf("TOP de pila: %d \n", top);
}

void debugTablaDeMovimiento(MOVIMIENTOS enumMovimiento, Entradas entrada, Movimiento movimiento){
  if (debug == true) printf("------------------------------------------------\n");
  if (debug == true) printf("tablaDeMovimientos[%d][%d]: = [%d, %d]\n", enumMovimiento, entrada, movimiento.estado, movimiento.accion);
  if (debug == true) printf("------------------------------------------------\n");
}