#include<stdio.h>

int main(){
    int num[10],i,reverse[10];
    i=0;
    while(i < 10){
        scanf("%d", &num[i]);
        i++;
    }
    i--;
    while(i >= 0){
        reverse[10 - i - 1] = num[i];
        printf("%d ", reverse[10 - i - 1]);
        i--;
    }
}