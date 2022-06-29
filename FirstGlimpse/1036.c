#include<stdio.h>
#define M(a,b) {int c=a;a=b;b=c;}

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    M(a,b);
    printf("%d %d", a,b);
}
