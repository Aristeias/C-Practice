#include<stdio.h>

int main(){
    int a;
    int b;
    int c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    if(a>b){
        if(a>c){
            printf("%d", a);
        }else{
            printf("%d", c);
        }
    }else if(a>c){
        printf("%d", b);
    }else if(b>c){
        printf("%d", b);
    }else{
        printf("%d", c);
    }
}