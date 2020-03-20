#include <stdio.h>
#include <stdlib.h>

    /*************************************************************************************************************************\
    ** 1. Escreva a função de ordenação de inserção em uma linguagem de programação.					                     **
    ** 2. Escreva uma função que rearranje um vetor v[0..n-1] de modo que ele fique em ordem estritamente crescente.	     **
    ** 4. Crie uma função que conte quantas iterações ocorrem ao ordenar um vetor.					                         **
    ** 5. Pior caso. Descreva e analise uma instância de pior caso para o algoritmo de inserção (mais lento possivel).	     **
    ** 6. Melhor caso. Descreva e analise uma instância de melhor caso para o algoritmo de inserção (mais rapido possivel).  **
    \*************************************************************************************************************************/

void printarArray(int v[], int n);

int main(void)
{
    int vetor[5] = {5,3,2,1,0};
    int tam = sizeof(vetor) / sizeof(vetor[0]); 

    int i, valor, j;
    int qtd = 0;

    printarArray(vetor, tam);

    for (i = 1; i < tam; i++)
    {
        valor = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > valor)
        {
            vetor[j+1] = vetor[j];
            j = j - 1;
            qtd++;
        }
        vetor[j+1] = valor;
    }

    printarArray(vetor, tam);
    printf("Esse array levou %d loops para ser ordenado.\n", qtd);
}

void printarArray(int v[], int n)
{
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", v[i]); 
    printf("\n"); 

}

    /*******************************************************************************************************************************************************************\
    **  RESPOSTA 5 e 6: ANALISE                                                                                                                                        **
    **  5: O melhor caso possível é um array já ordenado.                                                                                                              **
    **  6: O pior caso possível é um array ordenado de forma decrescente.                                                                                              ** 
    \*******************************************************************************************************************************************************************/