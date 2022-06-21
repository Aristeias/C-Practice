#include<stdio.h>

int main(){
    int num[10],sum=0;
    int i = 0;
    while( i < 10){
        scanf("%d",&num[i]);
        sum += num[i];
        i++;
    }
    i=0;
    double average =  1.0 * sum /10;
    int count;
    while (i < 10){
        if(num[i] > average){
            count++;
        }
        i++;
    }
    printf("%d",count);
    
}