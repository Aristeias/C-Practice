#include<stdio.h>
#include<math.h>

int main(){
    double x,result = 0;
    scanf("%lf", &x);
    if(x < 0){
        result = fabs(x);
    }else if(x >= 0 && x < 2){
        result = sqrt(x+1);
    }else if(x >= 2 && x < 4){
        result = pow(x + 2, 3);
    }else if(x >= 4){
        result = 2 * x + 5;
    }
    printf("%.2lf", result);
}