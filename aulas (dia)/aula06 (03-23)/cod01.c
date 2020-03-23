#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ver1(int v[], int n);
int ver2(int v[], int n);

int main(void)
{
    int v[4] = {0,1,3,4};
    int n  = 4;

    clock_t begin = clock();
    if (ver1(v, n) == 1)
        printf("ok");
    else
        printf("no");
    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTempo gasto ver1: %f", time_spent);
    printf("\n");

    begin = clock();
    if (ver2(v, n) == 1)
        printf("ok2");
    else
        printf("no2");
    end = clock();

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTempo gasto ver2: %f", time_spent);
    printf("\n");
}

int ver1(int v[], int n)
{
    // Menos otimizado
    int i;
    if (n > 1)
        for (i = 1; i < n; i++)
            if (v[i-1] > v[i])
                return 0;
            return 1;
}

int ver2(int v[], int n)
{
    // Mais otiimizado
    int i;
    int sim;

    for (i = 1; i < n; i++)
    {
        if (v[i-1] <= v[i])
            sim = 1;
        else
        {
            sim = 0;
            break;
        }
    }
    return sim;
}