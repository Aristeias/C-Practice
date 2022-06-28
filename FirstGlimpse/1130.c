#include<stdio.h>
#include<string.h>

void counterLetter(char arr[], int length);


int main(){
    char a[100];
    gets(a);
    counterLetter(a,strlen(a));
}

void counterLetter(char arr[], int length){
    int num = 0;
    for(int i = 0; i < length; i++){
        if((arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122)){
            num++;
        }
    }
    printf("%d", num);
}
