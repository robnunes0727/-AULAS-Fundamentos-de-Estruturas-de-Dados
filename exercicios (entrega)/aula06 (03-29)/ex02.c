#include <stdio.h>
#include <stdlib.h>

    /*******************************************************************************************************************************************************************\
    ** 3. Escreva uma função que receba um inteiro x e um vetor v[0..n-1] de inteiros em ordem crescente e insira x no vetor de modo a manter a ordem crescente.       **
    ** 7. Busca binária. Realizar a inserção de novos numeros usando busca binária e analise o resultado.                                                              **
    \*******************************************************************************************************************************************************************/

int bin(int *vetor, int n, int max);
void printarArray(int vetor[], int tam);

int main(void)
{
    int vetor[6] = {1,3,4,5,6,0};
    int tam = sizeof(vetor) / sizeof(vetor[0]); 

    printf("Digite o valor a ser inserido no lugar de 0: ");
    printarArray(vetor, tam);
    scanf("%d", &vetor[5]);

    int i, valor, j, loc;
    for (i = 1; i < tam; i++)
    {
        valor = vetor[i];
        j = i - 1;

        loc = bin(vetor, valor, j);

        while (vetor[j] > loc)
        {
            vetor[j+1] = vetor[j];
            j = j - 1;
        }
        vetor[j+1] = valor;
    }

    printarArray(vetor, tam);
}

void printarArray(int v[], int n)
{
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", v[i]); 
    printf("\n"); 

}

int bin(int *vetor, int n, int max)
{
    int esq = 0;
    int dir = max;

    while (esq <= dir)
    {
        int meio = esq + (dir - esq) / 2;

        if (vetor[meio] == n)
            return meio;
        else if (vetor[meio] > n)
            dir = meio - 1;
        else 
            esq = meio + 1;
    }

    if (n > vetor[esq])
        return esq;
    else
        return esq + 1;
}

    /*******************************************************************************************************************************************************************\
    **  RESPOSTA 7: ANALISE                                                                                                                                            **
    **  Mesmo usando busca binária, o tempo médio de complexidade ainda é o mesmo, pois sempre que se faz a seleção deve-se arrastar o número para seu devido local.   **
    \*******************************************************************************************************************************************************************/