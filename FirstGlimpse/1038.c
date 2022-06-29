#include<stdio.h>
#include<math.h>

#define M(a,b,c) (a + b + c)/2.0
#define S(s,a,b,c) sqrt((s*(s-a)*(s-b)*(s-c)))

int main(){
    float a,b,c;
    scanf("%f %f %f", &a, &b, &c);
    float s = M(a,b,c);
    printf("%.3f ", S(s,a,b,c));
}
