/* Este código se trata do clássico algoritmo de Peterson
   um dos mais conhecidos algoritmos que busca alcançar
   a exclusão mútua, o que ele teve sucesso, no entanto
   ele ainda sofre com o problema da espera ocupada, por isso
   não é recomendado seu uso em produção, mas seu valor educacional
   é indiscutível */

// Bibliotecas usadas

#include <stdio.h>
#include <pthread.h>

// Definições do macro

#define FALSE 1
#define TRUE  0
#define N     2                // Número de processos/threads

// Variáveis globais

volatile int turn; // Guarda de quem é a vez
int interested[2]; // Arranjo para os threads indicarem ou não interesse na região crítica

// Protótipos das funções

void *thread_a(void *);
void *thread_b(void *);

void enter_region(int);
void leave_region(int);

// Função principal

int main() {

    // Criação das threads A e B

    pthread_t threads[2];

    pthread_create(&threads[0], NULL, thread_a, &threads[0]);
    pthread_create(&threads[1], NULL, thread_b, &threads[1]);

    // Inicialização das threads

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    return 0;

}


// Rotina da thread A

void *thread_a(void *args) {

    enter_region(0); // Entra na região crítica

    leave_region(0); // Sai da região crítica

    return NULL;

}


// Rotina da thread B

void *thread_b(void *args) {

    enter_region(1); // Entra na região crítica

    leave_region(1); // Sai da região crítica

    return NULL;

}


// Entrou na região crítica

void enter_region(int id) {

    int other = 1 - id; // ID do outro thread

    interested[id] = TRUE; // Altera seu número no arranjo para true
    turn = id; // Altera turn para seu ID 

    while (interested[other] == TRUE && turn == id); // Espera ocupada pelo outro thread

    if (id == 0) {

        printf("Thread A entrou\n");

    } else {

        printf("Thread B entrou\n");

    }

}


// Sai da região crítica

void leave_region(int id) {

    interested[id] = FALSE; // Altera o seu valor no arranjo para false

    if (id == 0) {

        printf("Thread A saiu\n");

    } else {

        printf("Thread B saiu\n");

    }

}