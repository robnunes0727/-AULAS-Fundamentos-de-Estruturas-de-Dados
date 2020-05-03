#include <stdio.h>

float func(int x, int n){
    if (n == 0)
        return 1;
    else if (n > 0)
        return x * func(x, (n-1));
    else
        return 1.0 / func(x, -n);

}

int main(void){
    printf("%.2f\n",func(4, 4));
}