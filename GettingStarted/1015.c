#include<stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    double suma,sumb,sumc;
    while(a > 0){
        suma += a;
        a--;
    }
    while(b > 0){
        suma += b*b;
        b--;
    }
    while(c > 0){
        suma += 1.0/c;
        c--;
    }
    printf("%.2lf", suma + sumb + sumc);
}