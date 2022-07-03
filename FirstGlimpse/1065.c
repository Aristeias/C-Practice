#include<stdio.h>
#include<math.h>

int main(){
    int a[10];
    int min, index = 0;
    for(int i = 0; i < 10; i++){
        scanf("%d",&a[i]);
    }
    min = a[0];
    for(int i = 0; i < 10; i++){
        if(abs(a[i]) < min){
            min = abs(a[i]);
            index = i;
        }
    }

    if(index != 9){
        int temp = a[index];
        a[index] = a[9];
        a[9] = temp;
    }

    for(int i = 0; i < 10; i++){
        printf("%d ", a[i]);
    }
}
