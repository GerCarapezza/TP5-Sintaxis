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
void accionar(int, Movimiento, Estados, char*, int*);

void ejecutarE0(char*, int*);
void ejecutarE1(char*, int*);
void ejecutarE2(char*, int*);
void ejecutarE3(char*, int*);
void ejecutarE4(char*, int*);
void ejecutarE5(char*, int*);
void ejecutarE6(char*, int*);
void ejecutarE7(char*, int*);
void ejecutarE8(char*, int*);
void ejecutarE9(char*, int*);
void ejecutarE10(char*, int*);

#endif