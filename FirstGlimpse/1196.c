#include<stdio.h>
#include<string.h>

int main(){
    char a[100][80];
    int i = 0;
    while(1){
        gets(a[i]);
        if(a[i][0] == 0){
            break;
        }
        i++;
    }
    for(int m = 0; m < i; m++){
        int k = strlen(a[m]);
        for(int n = 0; n < k; n++){
            if(a[m][n] == 32){
                continue;
            }
            printf("%c", a[m][n]);
        }
        printf("\n");
    }
}

