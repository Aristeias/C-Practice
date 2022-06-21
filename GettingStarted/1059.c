#include<stdio.h>

int main(){
    int sum = 0,n,a = 2;
    scanf("%d", &n);
    while(n > 0){
        sum += a;
        a += 3;
        n--;
    }
    printf("%d", sum);
    
}