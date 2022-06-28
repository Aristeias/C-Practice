#include<stdio.h>

int c;
int getMax(int a, int b);
int getMin(int a, int b);

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    if(a > b){
        c = b;
    }else{
        c = a;
    }
    printf("%d %d", getMax(a,b), getMin(a,b));
}

int getMax(int a, int b){
    for(int i = c; i > 0; i--){
        if(a % i == 0 && b % i == 0){
            return i;
        }
    }
}

int getMin(int a, int b){
    int max = getMax(a,b);
    return a * b / max;
}