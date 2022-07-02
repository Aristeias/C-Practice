#include<stdio.h>
#include<mem.h>


int main(){
    int n;
    scanf("%d", &n);
    int factor[n],k=0;
    
    for(int i = 2; i <= n; i++){
        memset(factor, 0, sizeof(factor));
        int sum = 0;
        k = 0;
        for(int j = 1; j < i; j++){
            if(i % j == 0){
                sum += j;
                factor[k++] = j;
            }
            if(sum > i){
                break;
            }
        }
        
        if(sum == i){
            printf("%d its factors are", i);
            for(int j = 0; j <= n; j++){
                if(factor[j] == 0){
                    break;
                }
                printf(" %d", factor[j]);
            }
            printf("\n");
        }
    }
}