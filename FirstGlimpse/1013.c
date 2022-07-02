#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int num[n],factor = 10;
    num[0] = 2;
    for(int i = 1; i < n; i++){
        num[i] = factor * num[i - 1] + num[0];
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += num[i];
    }
    printf("%d", sum);
}