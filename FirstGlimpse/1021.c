#include<stdio.h>
#include<math.h>

int main(){
    float a;
    scanf("%f", &a);
    double x2 = 1;
    while(1){
         x2 = (x2 + a/x2) / 2;
         if(x2 - sqrt(a)<= 0.00001){
            break;
         }
    }
    printf("%.3f", x2);
}
