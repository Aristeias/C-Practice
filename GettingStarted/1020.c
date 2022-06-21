#include<stdio.h>

int main(){
    int n,sum = 1;
    scanf("%d", &n);
    int peach = 1;
    while(n > 1){
        sum = 2 * (peach + 1);
        peach = sum;
        n--;
    }
    printf("%d", sum);
}