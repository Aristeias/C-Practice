#include<stdio.h>
#define M(a) ((a % 400 == 0) || (a % 4 == 0 && a % 100 != 0))? 'L':'N'

int main(){
    int a;
    scanf("%d", &a);
    printf("%c", M(a));
}
