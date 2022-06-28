#include<stdio.h>

void seperateLetter(int a);

int main(){
    int a;
    scanf("%d", &a);
    seperateLetter(a);
}

void seperateLetter(int a){
    int j = 1000;
    for(int i = 0; i < 4; i++){
        int k = 100;
        int num = a / j % 10;
        printf("%d ", num);
        j /= 10;

    }
}