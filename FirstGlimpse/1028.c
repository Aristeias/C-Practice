#include<stdio.h>
#include <math.h>

void getResult(double a, double b,double c);

int main(){
    double a,b,c;
    scanf("%lf %lf %lf", &a, &b, &c);
    getResult(a, b, c);
}

void getResult(double a, double b,double c){
    
    double delta = b*b - 4*a*c;
    double x1, x2;
    
    if(delta >= 0){
        x1 = (-b + sqrt(delta) )/ 2.0 * a ;
        x2 = (-b - sqrt(delta) )/ 2.0 * a ;
        printf("x1=%.3lf x2= %.3lf", x1, x2);
    }else{
        printf("x1=%.3lf+%.3lfi x2=%.3lf-%.3lfi", -b/(2*a), sqrt(-delta)/ (2 * a),-b/(2*a), sqrt(-delta)/ (2 * a));
    }
}