#include<stdio.h>

int main(){
    int h;
    int w;
    scanf("%d", &h);
    scanf("%d", &w);
    printf("C:%d\nS:%d", (h+w)*2, w*h);
}