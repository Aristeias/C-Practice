#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int num[n][n],i,sum1=0,sum3=0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &num[i][j]);
            
            if(i == j){
                sum1 += num[i][j];
            }
            if(i + j == n - 1){
                sum3 += num[i][j];
            }
        }
    }
    if(n % 2 != 0){
        sum3 -= num[n / 2][n / 2];
    }
    printf("%d", sum1+sum3);
}