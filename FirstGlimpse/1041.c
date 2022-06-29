#include<stdio.h>

#define M(a,b,c) a>b?(a>c?a:c):(b>c?b:c)

float getMax(float a, float b, float c);

int main(){
    float a,b,c;
    scanf("%f %f %f", &a, &b, &c);
    printf("%.3f\n",getMax(a,b,c));
    printf("%.3f", M(a,b,c));
}

float getMax(float a, float b, float c){
    if(a > b){
        if(a > c){
            return a;
        }else{
            return c;
        }
    }else{
        if(b > c){
            return b;
        }else{
            return c;
        }
    }
}
