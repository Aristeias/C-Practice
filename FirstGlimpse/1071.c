#include<stdio.h>

double fact(int k);

int main(){
    int n;
    scanf("%d", &n);
    double sum = 0;
    for(int i = 1; i <= n; i++){
        sum += 1 / fact(i);
    }
    printf("sum=%.5f", sum);
}

double fact(int k){
    double result = 1;
    for(int i = 1; i <= k; i++){
        result *= i;
    }
    return result;
}
