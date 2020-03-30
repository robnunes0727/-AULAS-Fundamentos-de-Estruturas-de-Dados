/*
 * 1. Implemente em uma linguagem de programação o algoritmo de ordenação por seleção. Teste com o vetor abaixo:
 * 330, 108, 383, 362, 269, 175, 276, 301, 387, 422, 328
 * 
 * 2. Pior caso.  Descreva o pior caso.
 *
 * 3. Melhor caso. Descreva o melhor caso.
 * 
 * 4. Movimentação de dados.  Quantas vezes, no pior caso, o algoritmo de seleção copia um elemento do vetor de um lugar para outro?  
 * Quantas vezes isso ocorre no melhor caso?
 * 
 * 5. Fazer o array ordenar em ordem decrescente.
*/

#include <stdio.h>

#define TAMANHO 11

void printarArray();
void selectionSort();
void decSelectionSort();

int main(void)
{
    //int v[TAMANHO] = {330, 108, 383, 362, 269, 175, 276, 301, 387, 422, 328};
    int v[TAMANHO] = {10, 9, 8, 7, 6, 5,4, 3,2, 1, 0};
    printarArray(v, TAMANHO);
    selectionSort(v, TAMANHO);
    printarArray(v, TAMANHO);
    decSelectionSort(v, TAMANHO);
    printarArray(v, TAMANHO);
}

void selectionSort(int v[TAMANHO],int n){

    int i,j,aux,posicaoMenor, qtd = 0;

    for (i = 0; i < n-1; i++) 
    {
        posicaoMenor = i;
        
        for (j = i+1; j < n; j++){
            qtd++;
            if (v[j] < v[posicaoMenor])
                posicaoMenor = j;
        }
        aux = v[i];
        v[i] = v[posicaoMenor];
        v[posicaoMenor] = aux;

        printf("T%d ", qtd);
    }
}

void printarArray(int v[], int n)
{
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", v[i]); 
    printf("\n"); 

}

void decSelectionSort(int v[], int n)
{
    int i,j,aux,posicaoMenor;

    for (i = 0; i < n-1; i++) 
    {
        posicaoMenor = i;
        
        for (j = i+1; j < n; j++)
            // Só precisa mudar o if de < pra >.
            if (v[j] > v[posicaoMenor])
                posicaoMenor = j;
        
        aux = v[i];
        v[i] = v[posicaoMenor];
        v[posicaoMenor] = aux;
    }
}

/*
 * RESPOSTAS
 * 
 * 2. Ele sempre roda no pior caso.
 * 
 * 3. Um array já ordenado. Mas ele sempre faz o mesmo tanto de comparações.
 * 
 * 4. No melhor caso ele não muda nada de lugar, mas ainda faria varias comparações. 
 * No pior caso ele copiaria o array inteiro, e faria o mesmo tanto de comparações, considerando arrays do mesmo tamanho.
 * 
*/