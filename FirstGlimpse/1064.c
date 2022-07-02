#include<stdio.h>

int main(){
    double temp = 1,sum = 0;
    for(int i = 1; i <= 30; i++){
        temp *= i;
        sum += temp;
    }
    printf("%.2e\n",sum);
}