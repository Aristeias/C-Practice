#include<stdio.h>

int main(){
    int i = 10;
    while(i <= 1000){
        if(i%2==0 && i%3==0 && i%7==0){
            printf("%d\n",i);
        }
        i++;
    }
}