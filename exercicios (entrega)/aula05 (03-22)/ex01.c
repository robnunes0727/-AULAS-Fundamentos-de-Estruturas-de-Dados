#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int seq(int *vetor, int n);
int bin(int *vetor, int n, int tam);
int binorg();

    /*******************************************************************************************************\
    ** Dado um vetor de 250 números aleatórios implemente:                                                 **
    ** - Uma função de busca sequencial;                                                                   **
    ** - Uma função de busca binária;                                                                      **
    ** - A leitura de um número pelo usuário e exiba em qual posição encontra-se o número escolhido.       **
    \*******************************************************************************************************/

int main(void)
{
    int vetor[250];
    int n, input, a;

    // Da uma seed pro random.h não repetir os numeros.
    srand(time(0)); 

    // Loop para inserção
    int i = 0;
    for (i = 0; i < 250; i++)
    {
        n = rand() % 50 + 1;
        vetor[i] = n;
    }

    // Input do usuario
    printf("Digite o valor a ser buscado: (1 a 50 para encontrar)\n");
    scanf("%d", &input);

    // Funcao de busca binaria desordenada
    printf("\nBusca binária:\n");
    a = bin(vetor, input, sizeof(vetor) / sizeof(vetor[0]));
    if (a == -1)
        printf("BIN: Valor nao encontrado. (array nao ordenado)\n");
    else
        printf("BIN: Valor encontrado na posicao: %d\n", a);
    
    // Funcao de busca sequencial
    printf("\nBusca sequencial:\n");
    a = seq(vetor, input);
    if (a == -1)
        printf("SEQ: Valor nao encontrado.\n");
    else
        printf("SEQ: Valor encontrado na posicao: %d\n", a);
    
    printf("\n#######################################################\n");
    
    // Funcao de busca binaria em vetor pré-ordenado
    printf("\nBusca binaria em vetor ordenado:\n");
    a = binorg();
    if (a == -1)
        printf("Valor nao encontrado.\n");
    else
        printf("Valor encontrado na posicao: %d\n", a);

    return 0;
}

int seq(int *vetor, int n)
{
    // Busca sequencial, compara um por um
    int i;
    for (i = 0; i < 250; i++)
    {
        if (vetor[i] == n)
            return i;
    }
    return -1;
}

int bin(int *vetor, int n, int tam)
{
    // Busca binaria, acha a metade e corta no meio
    int esq = 0;
    int dir = tam; // tam = sizeof(vetor) / sizeof(vetor[0])

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

    return -1;
}

int binorg()
{
    // Busca binaria em vetor ordenado
    int vetor[10] = {1,2,3,4,5,6,7,8,9,10};
    int n;

    printf("Digite o valor a ser buscado: (1 a 10 para encontrar)\n");
    scanf("%d", &n);
   
    int esq = 0;
    int dir = sizeof(vetor) / sizeof(vetor[0]); 

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

    return -1;
}