#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    
    long long int sum = 0;
    if(n == 0){
        sum = 1;
    }
    for(int i = 1; i <= n; i++){
        int multiply = 1;
        for(int j = 1; j <= i; j++){
            multiply *= j;
        }
        sum += multiply;
    }
    printf("%ld", sum);
}