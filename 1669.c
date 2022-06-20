#include<stdio.h>

int main(){
    double r;
    scanf("%lf", &r);
    printf("%.2lf", r*r*3.141 + 0.005);
}