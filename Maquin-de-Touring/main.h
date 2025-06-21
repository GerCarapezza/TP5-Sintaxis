#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum {E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10} Estados;
typedef enum {IZQUIERDA, DERECHA} Movimiento;

char* crearCinta(char[]);
bool verificarMT(char*);

#endif