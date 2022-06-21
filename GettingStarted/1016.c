#include<stdio.h>

int main(){
    int num=100,sum=0;
    int temp = num;
    while(num < 1000){
        while(num > 0){
            int a = num % 10;
            num/=10;
            sum += a * a * a;
        }
        if(sum == temp){
            printf("%d\n",sum);
        }
        temp++;
        num = temp;
        sum = 0;
    }
}