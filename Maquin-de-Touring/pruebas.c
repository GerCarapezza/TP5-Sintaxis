#include <stdio.h>
#include <string.h>

#define MAX 100

#include <stdio.h>
#include <string.h>

#define MAX 200

typedef enum { q0, q1, q2, q3, q4, q5, q6, q_accept, q_reject } State;

char tape[MAX];
int head = 0;
State state = q0;

void moveRight() { head++; }
void moveLeft()  { if (head > 0) head--; }

void printTape() {
    for (int i = 0; i < strlen(tape); i++) {
        if (i == head) printf("[%c]", tape[i]);
        else printf(" %c ", tape[i]);
    }
    printf("   (Estado: q%d)\n", state);
}

void run() {
    while (1) {
        printTape();
        char symbol = tape[head];
        switch (state) {
            case q0:
                if (symbol == 'a') {
                    tape[head] = 'X';
                    moveRight();
                    state = q1;
                } else if (symbol == 'X') {
                    moveRight();
                } else if (symbol == 'c') {
                    state = q3;
                } else {
                    state = q_reject;
                }
                break;

            case q1:
                if (symbol == 'a') {
                    moveRight();
                } else if (symbol == 'c') {
                    tape[head] = 'Y';
                    moveLeft();
                    state = q2;
                } else if (symbol == 'Y') {
                    moveRight();
                } else {
                    state = q_reject;
                }
                break;

            case q2:
                if (symbol == 'a' || symbol == 'Y') {
                    moveLeft();
                } else if (symbol == 'X') {
                    moveRight();
                    state = q0;
                } else {
                    state = q_reject;
                }
                break;

            case q3:
                if (symbol == 'Y') {
                    moveRight();
                } else if (symbol == 'd') {
                    moveRight();
                    state = q4;
                } else {
                    state = q_reject;
                }
                break;

            case q4:
                if (symbol == 'e') {
                    tape[head] = 'Z';
                    moveLeft();
                    state = q5;
                } else if (symbol == 'Z') {
                    moveRight();
                } else if (symbol == 'B') {
                    state = q_accept;
                } else {
                    state = q_reject;
                }
                break;

            case q5:
                if (symbol == 'Z' || symbol == 'e') {
                    moveLeft();
                } else if (symbol == 'd') {
                    moveLeft();
                    state = q6;
                } else {
                    state = q_reject;
                }
                break;

            case q6:
                if (symbol == 'Y') {
                    moveLeft();
                } else if (symbol == 'X') {
                    moveRight();
                    state = q4;
                } else {
                    state = q_reject;
                }
                break;

            case q_accept:
                printf("\n✅ Cadena aceptada.\n");
                return;

            case q_reject:
                printf("\n❌ Cadena rechazada.\n");
                return;
        }
    }
}

int main() {
    char input[MAX];
    printf("Ingrese una cadena (ej: aaccdeee): ");
    scanf("%s", input);

    strcpy(tape, input);
    strcat(tape, "B");  // símbolo blanco al final

    run();
    return 0;
}
// gcc .\pruebas.c -o pruebas
// .\pruebas.exe