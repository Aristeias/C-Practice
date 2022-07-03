#include<stdio.h>
#include<math.h>

int main(){
    int n,exCount=0,passCount=0,unCount=0;
    while(n > 0){
        scanf("%d", &n);
        if(n == 0){
            break;
        }
        if(n > 85){
            exCount++;
        }else if(n < 60){
            unCount++;
        }else{
            passCount++;
        }
    }
    printf(">=85:%d\n", exCount);
    printf("60-84:%d\n", passCount);
    printf("<60:%d\n", unCount);
}
