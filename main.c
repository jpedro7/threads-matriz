#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct data {
        int **matriz;
        pthread_t *tid;
        int n;
        int i;
} Data;

void *soma_linha(void *args);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int soma = 0;

int main(void)
{
        Data *data = (Data *)malloc(sizeof(Data));
        data->i = 0;
        scanf("%d", &data->n);

        data->matriz = (int **)malloc(data->n * sizeof(int *));
        pthread_t threads[data->n];

        for (int i = 0; i < data->n; i++) {
                data->matriz[i] = (int *)malloc(data->n * sizeof(int));
                for (int j = 0; j < data->n; j++) {
                        scanf(" %d", &data->matriz[i][j]);
                }
        }

        data->tid = threads;
        for (int i = 0; i < data->n; i++) {
                if (pthread_create(&threads[i], NULL, soma_linha, data)) {
                        printf("Error on creating thread!\n");
                }
        }

        printf("\n");

        for (int i = 0; i < data->n; i++) {
                pthread_join(threads[i], NULL);
        }

        printf("\nSoma total: %d\n", soma);

        return 0;
}

void *soma_linha(void *args)
{
        Data *data = (Data *) args;
        int soma_local = 0;

        pthread_mutex_lock(&mutex);

        int *linha = data->matriz[data->i];

        printf("\nSomando linha %d\n", data->i + 1);
        printf("Thread id: %lu\n", *(data->tid + data->i));

        for (int i = 0; i < data->n; i++) {
                soma += linha[i];
                soma_local += linha[i];
                if (i < 1)
                        printf("[%d]", linha[i]);
                else
                        printf(" - [%d]", linha[i]);
        }

        printf(" - Resultado da linha: %d\n", soma_local);

        data->i += 1;

        pthread_mutex_unlock(&mutex);

        return args;
}
