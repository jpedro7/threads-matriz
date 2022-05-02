#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct data {
        int **matriz;
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

        for (int i = 0; i < data->n; i++) {
                if (pthread_create(&threads[i], NULL, soma_linha, data)) {
                        printf("Error on creating thread!\n");
                }
        }

        for (int i = 0; i < data->n; i++) {
                pthread_join(threads[i], NULL);
        }

        printf("\n%d\n", soma);

        return 0;
}

void *soma_linha(void *args)
{
        pthread_mutex_lock(&mutex);

        Data *data = (Data *) args;
        int *linha = data->matriz[data->i];

        for (int i = 0; i < data->n; i++) {
                soma += linha[i];
        }

        data->i += 1;

        pthread_mutex_unlock(&mutex);
}