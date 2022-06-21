#include<stdio.h>

int main(){
    int i,j=1,sum=0,count1=0,count2=0;
    while(j <= 20){
        scanf("%d", &i);
        if(i > 0){
            sum += i;
            count1++;
        }else{
            count2++;
        }
        j++;
    }
    printf("%d\n",count2);
    printf("%.2f",sum * 1.0 / count1);
    
}