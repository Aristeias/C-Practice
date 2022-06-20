#include<stdio.h>

/* Stupid */

int main(){
    int num;
    int count=0;
    scanf("%d", &num);
    int temp = num;
    while (num > 0)
    {
        num /= 10;
        count++;
    }
    printf("%d\n", count);

    num = temp;
    int i = 0;
    int num2[count];
    while (num > 0)
    {
        int num3 = num % 10;
        num /= 10;
        num2[i] = num3;
        i++;
    }

    int j = 0;
    while (j < i )
    {
        printf("%d ",num2[i - 1 - j]);
        j++;
    }
    printf("\n");
    j = 0;
    while (j < i )
    {
        printf("%d",num2[j]);
        j++;
    }
    
    
    
}