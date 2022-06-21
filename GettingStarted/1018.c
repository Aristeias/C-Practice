#include<stdio.h>

int main(){
    
    int a = 1, b = 2, n;
    float sum = 0;
    scanf("%d", &n);
    while( n > 0){
        sum += b * 1.0 / a; 
        int temp = b;
        b = a + b;
        a = temp;
        n--;
    }
    printf("%.2f", sum);

}