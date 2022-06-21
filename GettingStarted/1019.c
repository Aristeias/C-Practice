#include<stdio.h>

int main(){
    float m,n,sum = 0, startm;
    scanf("%f %f", &m, &n);
    int i = 1;
    startm = m;
    while( i <= n ){
        sum += 2 * m ;
        m /= 2;
        i++;
    }

    printf("%.2f %.2f", m, sum - startm);
}