#include <stdio.h>
#include <stdlib.h>

int ver1(int v[], int n);
int ver2(int v[], int n);

int main(void)
{
    int v[4] = {0,1,4,3};
    int n  = 4;

    if (ver1(v, n) == 1)
        printf("ok");
    else
        printf("no");
    
    printf("\n");

    if (ver2(v, n) == 1)
        printf("ok2");
    else
        printf("no2");
    
    printf("\n");
}

int ver1(int v[], int n)
{
    int i;
    if (n > 1)
        for (i = 1; i < n; i++)
            if (v[i-1] > v[i])
                return 0;
            return 1;
}

int ver2(int v[], int n)
{
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