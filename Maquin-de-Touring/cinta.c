#include "main.h"

/*cada funcion de ejecucion recibe la cinta y el head (*i)*/
void ejecutarE0(char* cinta, int* i){
    int entrada = cinta[*i];
    switch (entrada){
        case 'a':
            accionar('X', DERECHA, E1, cinta, i);//accionar modifica la cinta, actualiza el estado y se desplaza par iz o der
            return;
        case 'Y':
            accionar('Y', DERECHA, E7, cinta, i);
            return;
    }
}

void ejecutarE1(char* cinta, int* i){
    int entrada = cinta[*i];
    switch (entrada){
        case 'a':
            accionar('a', DERECHA, E1, cinta, i);
            return;
        case 'c':
            accionar('Y', DERECHA, E2, cinta, i);
            return;
        case 'y':
            accionar('Y', DERECHA, E5, cinta, i);
            return;
    }
}

void ejecutarE2(char* cinta, int* i){
    int entrada = cinta[*i];
    switch (entrada){
        case 'c':
            accionar('c', DERECHA, E2, cinta, i);
            return;
        case 'd':
            accionar('W', DERECHA, E3, cinta, i);
            return;
        case 'W':
            accionar('W', DERECHA, E3, cinta, i);
            return;
    }
}

void ejecutarE3(char* cinta, int* i){
    int entrada = cinta[*i];
    switch (entrada){
        case 'e':
            accionar('Z', IZQUIERDA , E4, cinta, i);
            return;
        case 'Z':
            accionar('Z', DERECHA   , E6, cinta, i);
            return;
    }
}

void ejecutarE4(char* cinta, int* i){
    int entrada = cinta[*i];
    switch (entrada){
        case 'a':
            accionar('a', IZQUIERDA , E4, cinta, i);
            return;
        case 'c':
            accionar('c', IZQUIERDA , E4, cinta, i);
            return;
        case 'Z':
            accionar('Z', IZQUIERDA , E4, cinta, i);
            return;
        case 'Y':
            accionar('Y', IZQUIERDA , E4, cinta, i);
            return;
        case 'W':
            accionar('W', IZQUIERDA , E4, cinta, i);
            return;
        case 'X':
            accionar('X', DERECHA   , E0, cinta, i);
            return;
    }
}

void ejecutarE5(char* cinta, int* i){
    int entrada = cinta[*i];
    switch (entrada){
        case 'c':
            accionar('Y', DERECHA, E2, cinta, i);
            return;
        case 'Y':
            accionar('Y', DERECHA, E5, cinta, i);
            return;
    }
}

void ejecutarE6(char* cinta, int* i){
    int entrada = cinta[*i];
    switch (entrada){
        case 'e':
            accionar('Z', IZQUIERDA , E4, cinta, i);
            return;
        case 'Z':
            accionar('Z', DERECHA   , E6, cinta, i);
            return;
    }
}

void ejecutarE7(char* cinta, int* i){
    int entrada = cinta[*i];
    switch (entrada){
        case 'Y':
            accionar('Y', DERECHA, E7, cinta, i);
            return;
        case 'W':
            accionar('W', DERECHA, E8, cinta, i);
            return;
    }
}

void ejecutarE8(char* cinta, int* i){
    accionar('Z', DERECHA, E9, cinta, i);
}

void ejecutarE9(char* cinta, int* i){
    int entrada = cinta[*i];
    switch(entrada){
        case 'Z':
            accionar('Z', DERECHA, E9, cinta, i);
            return;
        case 'B':
            accionar('B', DERECHA, E10, cinta, i);
            return;

    }
}