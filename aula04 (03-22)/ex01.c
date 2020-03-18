#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    /*************************************************************************************\
    ** Crie um programa que adicione 20.000 números aleatórios em um vetor dinâmico.     **
    ** Imprima a quantidade de memoria utilizada:                                        **
    ** - Antes da inserção;                                                              **
    ** - Ao final da inserção;                                                           **
    ** - Após liberar a memória.                                                         **
    \*************************************************************************************/
    
int main(void)
{
    // Criar vetor e inicia variavel.
    int *vetor;
    int n;
    
    // Printa tamanho (1)
    printf("%lu\n", sizeof(vetor));
    
    // Da uma seed pro random.h não repetir os numeros.
    srand(time(0)); 

    // Malloc vetor pra 20000
    vetor = (int*) malloc(20000 * sizeof(n));

    // Checa se tem espaço pro vetor
    if (vetor == NULL)
        return 1;

    // Loop para inserção
    int i = 0;
    for (i = 0; i < 20000; i++)
    {
        n = rand() % 20000;
        vetor[i] = n;
    }

    // Printa tamanho (2)
    printf("%lu\n", sizeof(vetor));

    // Libera memoria.
    free(vetor);

    // Printa tamanho (3)
    printf("%lu\n", sizeof(vetor));

    // Sempre vai dar 8 pois sizeof está medindo o tamanho do ponteiro, não do array.
}