#include<stdio.h>

int main(){
    int i = 1, j = 1;
    while(i <= 9){
        while(j <= i){
            printf("%d*%d=%-2d ", j, i, i*j);
            j++;
        }
        printf("\n");
        i++;
        j = 1;
    }
}