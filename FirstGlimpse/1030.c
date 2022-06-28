#include<stdio.h>

int num[3][3];
int reverseArray();

int main(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &num[i][j]);
        }
    }
    reverseArray();
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ",num[i][j]);
        }
        printf("\n");
    }
}

int reverseArray(){
    for(int i = 0; i <= 3; i++){
        for(int j = i; j < 3; j++){
            int temp = num[i][j];
            num[i][j] = num[j][i];
            num[j][i] = temp;
        }
    }
    return 1;
}