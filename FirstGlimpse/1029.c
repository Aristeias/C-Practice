#include<stdio.h>

int isPrime(int a);

int main(){
    int a;
    scanf("%d", &a);
    if(isPrime(a) == 1){
        printf("prime");
    }else{
        printf("not prime");
    }
}

int isPrime(int a){
    for(int i = 2; i < a; i++){
        if(a % i == 0){
            return 0;
        }
    }
    return 1;
}

