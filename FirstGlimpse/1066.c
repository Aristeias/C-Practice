#include<stdio.h>

double fact(int n);
double mypow(double x, int n);

int main(){
    double x, sum = 0;
    int n;
    scanf("%lf %d", &x, &n);
    for(int i = 1; i <= n; i++){
        sum += (mypow(x,i) / fact(i)) * mypow(-1, i - 1);
    }
    printf("%.4lf", sum);
    
}

double fact(int n){
    double result = 1;
    for(int i = 1; i <= n; i++){    
        result *= i;
    }
    return result;

}

double mypow(double x, int n){
    double result = 1;
    for(int i = 1; i <= n; i++){    
        result *= x;
    }
    return result;
}
