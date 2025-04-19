/* Este é o algorítmo de variáveis de trava escrito em C
   Não recomendo o uso desse código em produção devido a sua ineficiência
   em cumprir o objetivo de exclusão mútua, o código é apenas para fins educacionais

*/

// Bibliotecas usadas

#include <stdio.h>
#include <pthread.h>

// Variáveis globais

volatile int lock = 0;

// Declaração dos protótipos de função

void enter_region(int);
void leave_region(int);

void *thread_a(void *);
void *thread_b(void *);


// Função principal

int main() {

    // Criação das threads

    pthread_t threads[2];

    pthread_create(&threads[0], NULL, thread_a, &threads[0]);
    pthread_create(&threads[1], NULL, thread_b, &threads[1]);

    // Inicialização das threads

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    return 0;

}


// Função de entrada para região crítica

void enter_region(int id) {

    if (id == 0) {

        printf("Thread A entrou na região crítica\n");

    } else {

        printf("Thread B entrou na região crítica\n");

    }

}


// Função de saída para região crítica

void leave_region(int id) {

    if (id == 0) {

        printf("Thread A saiu da região crítica\n");

    } else {

        printf("Thread B saiu da região crítica\n");

    }

}


// Rotina do thread A

void *thread_a(void *args) {

    while (lock != 0); // Espera a trava ser liberada

    lock = 1; // Pega a trava para si

    enter_region(0); // Entra na região crítica

    lock = 0; // Deixa a trava livre

    leave_region(0); // Sai da região crítica

}


// Rotina do thread B

void *thread_b(void *args) {

    while (lock != 0); // Espera a trava ser liberada

    lock = 1; // Pega a trava para si

    enter_region(1); // Entra na região crítica

    lock = 0; // Deixa a trava livre

    leave_region(1); // Sai da região crítica

}