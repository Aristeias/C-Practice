#include<stdio.h>

int main(){
    double c;
    double f;
    scanf("%lf", &f);
    c = 5 * (f - 32) / 9.0;
    printf("c=%.2lf", c);
}