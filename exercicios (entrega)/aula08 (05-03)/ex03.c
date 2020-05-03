#include <stdio.h>

int CombR(int n,int k)
{
    if(k == 1)
        return n;
    if(k == n)
        return 1;
    return CombR(n-1,k-1) + CombR(n-1,k);
}

int fatorial( int N )
{
  int product = 1;
  for ( int j=1; j<=N; j++ )
    product *= j;
  return product;
}

int CombI(int n, int k)
{
    return fatorial(n) / (fatorial(k) * fatorial(n-k));
}

int main(void)
{
    printf("%d\n", CombR(4, 3));
    printf("%d\n", CombI(4, 3));
}