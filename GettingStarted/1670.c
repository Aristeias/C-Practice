#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    while(n > 0){
        int a = n % 10;
        n /= 10;
        printf("%d ", a);
    }
}