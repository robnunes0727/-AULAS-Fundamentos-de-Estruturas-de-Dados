#include <stdio.h>

// Implemente uma função max recursiva

int max_rec(int v[], int max, int n)
{
    // Caso final
    if (n == 0)
    {
        if (v[n] > max)
            max = v[n];
        
        return max;
    }

    if (v[n] > max)
        max = v[n];
    
    return max_rec(v, max, n-1);
}

int main(void)
{
    for(int i = 25; i > 0; i--){
    int vetor[8] = {1,22,332,5,1,0,9,2};
    int max = 0;
    int tam = 8;
    
    max = max_rec(vetor, max, tam);
    
    printf("Max: %d\n", max);
    }
}