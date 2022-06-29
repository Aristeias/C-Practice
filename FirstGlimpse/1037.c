#include<stdio.h>
#define M(a,b) a % b

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    int c = M(a,b);
    printf("%d ", c);
}
