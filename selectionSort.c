#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

void ordenarListaCrescente(int V[], int n){
    int i, j, auxiliar;

    for(i=0; i<n; i++){
        for(j = i+1; j<n; j++){
            if(V[i] > V[j]){
                auxiliar = V[i];
                V[i] = V[j];
                V[j] = auxiliar;
            }
        }
    }
}

void ordenarListaDecrescente(int V[], int n){
    int i, j, auxiliar;

    for(i=0; i<n; i++){
        for(j = i+1; j<n; j++){
            if(V[i] < V[j]){
                auxiliar = V[i];
                V[i] = V[j];
                V[j] = auxiliar;
            }
        }
    }
}

void selectionSort(int V[], int n){
    int i, j, auxiliar, menor;

    for(i=0; i<n-1; i++){
        menor = i;
        for(j = i + 1; j<n; j++)
            if(V[menor] > V[j])
                menor = j;

        if(i != menor){
            auxiliar = V[i];
            V[i] = V[menor];
            V[menor] = auxiliar;
        }
    }
}

int main(){
    int V[N], i;
    clock_t tempo;

    srand( time(NULL) );

    for(i=0; i<N; i++)
        V[i] = rand() % N;
    
    tempo = clock();
    selectionSort(V, N);
    tempo = clock() - tempo;

    printf("O Tempo em segundos para um vetor preenchido com numeros aleatorios foi: %f\n", ((double)tempo)/CLOCKS_PER_SEC);

    ordenarListaCrescente(V, N);

    tempo = clock();
    selectionSort(V, N);
    tempo = clock() - tempo;

    printf("O Tempo em segundos para um vetor ordenado de forma crescente foi: %f\n", ((double)tempo)/CLOCKS_PER_SEC);

    ordenarListaDecrescente(V, N);

    tempo = clock();
    selectionSort(V, N);
    tempo = clock() - tempo;

    printf("O tempo em segundos para um vetor ordenado de forma decrescente foi: %f\n", ((double)tempo)/CLOCKS_PER_SEC);

    return 0;
}