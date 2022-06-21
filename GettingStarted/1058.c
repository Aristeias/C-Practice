#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int num,sum = 0 ;
    while( n > 0){
        scanf("%d", &num);
        if(num % 2 == 0){
            sum += num;
        }
        n--;
    }
    printf("%d", sum);
}