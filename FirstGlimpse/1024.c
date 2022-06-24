#include<stdio.h>

int main(){
    int num[3][3],i,sum1=0,sum2=0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &num[i][j]);
            
            if(i == j){
                sum1 += num[i][j];
            }
            if(i + j == 2){
                sum2 += num[i][j];
            }
        }
    }
    printf("%d %d", sum1, sum2);
}