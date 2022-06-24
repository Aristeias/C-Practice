#include<stdio.h>

int main(){
    int num[10],i,a;
    i=0;
    while(i < 9){
        scanf("%d", &num[i]);
        i++;
    }
    scanf("%d", &a);
    i = 0;
    while(i < 10){
        if(a < num[i]){
            break;
        }
        i++;
    }
    while(i < 10){
        int temp = num[i];
        num[i] = a;
        a = temp;
        i++;
    }
    i = 0;
    while(i < 10){
        printf("%d\n", num[i]);
        i++;
    }
}