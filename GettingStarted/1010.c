#include<stdio.h>

int main(){
    double num;
    double bonus = 0;
    scanf("%lf", &num);
    if(num <= 100000){
        bonus = 0.1 * num;
    }else if(num <= 200000){
        bonus = 0.1 * 100000 + (num - 100000) * 0.075;
    }else if(num <= 400000){
        bonus = (0.1 + 0.075) * 100000 + (num - 200000) * 0.05;
    }else if(num <= 600000){
        bonus = (0.1 + 0.075) * 100000 + 200000 * 0.05 + (num - 400000) * 0.03;
    }else if(num <= 1000000){
        bonus = (0.1 + 0.075) * 100000 + 200000 * (0.05 + 0.03) + (num - 600000) * 0.015;
    }else{
        bonus = (0.1 + 0.075) * 100000 + 200000 * (0.05 + 0.03) + 400000 * 0.015 + (num - 1000000) * 0.01;
    }
    printf("%.0lf",bonus);
}