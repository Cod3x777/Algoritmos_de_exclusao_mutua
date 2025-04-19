/* Este é o algorítmo clássico da alternância 
explicita de processos/threads escrito em C por mim 

O código é feito apenas para fins educacionais e não recomenda
seu uso em um produção, visto que o algorítmo se tornou
ineficiente para aplicações complexas nos dias de hoje, então
considere apenas como valor histórico e educacional

*/

// Bibliotecas usadas

#include <stdio.h>
#include <pthread.h>

// Declaração das variáveis globais

int turn = 0;

// Declaração dos protótipos de função

void *thread_a(void *);
void *thread_b(void *);

void enter_region(int);
void leave_region(int);

// Função principal

int main() {

    // Criação dos threads A e B

    pthread_t threads[2];

    pthread_create(&threads[0], NULL, thread_a, &threads[0]);
    pthread_create(&threads[1], NULL, thread_b, &threads[1]);

    // Inicialização dos threads

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    return 0;

}

// Rotina para o thread A

void *thread_a(void *args) {

    while (turn != 0); // Espera turn ser 0

    enter_region(0); // Entra na região crítica

    turn = 1; // Muda turn para 1

    leave_region(0); // Sai da região crítica

}


// Rotina para o thread B

void *thread_b(void *args) {

    while (turn != 1); // Espera turn ser 1

    enter_region(1); // Entra na região crítica

    turn = 0; // Muda turn para 0

    leave_region(1); // Sai da região crítica

}


// Função de entrada da região crítica

void enter_region(int id) {

    if (id == 0) {

        printf("O thread A entrou\n");

    } else {

        printf("O thread B entrou\n");

    }

}


// Função para saída da região crítica

void leave_region(int id) {

    if (id == 0) {

        printf("O thread A saiu\n");

    } else {

        printf("O thread B saiu\n");

    }

}