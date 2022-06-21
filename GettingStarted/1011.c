#include<stdio.h>

int main(){
    int a,b;
    int max,min;
    scanf("%d %d", &a, &b);
    if(a < b){
        int temp = a;
        a = b;
        b = temp;
    }
    int tempb = b;
    while( b > 0){
        if(a % b == 0){
            if(tempb % b == 0){
                max = b;
                break;
            }
        }
        b--;
    }
    b = tempb;

    min = a * b / max;
    printf("%d %d", max, min);

}