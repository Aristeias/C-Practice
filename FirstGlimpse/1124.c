#include<stdio.h>
#include<string.h>

void letterToUpper(char arr[], int length);


int main(){
    char a[100];
    gets(a);
    letterToUpper(a,strlen(a));
}

void letterToUpper(char arr[], int length){
    for(int i = 0; i < length; i++){
        if(arr[i] >= 65 && arr[i] <= 90){
            arr[i] += 32;
        }
    }
    printf("%s", arr);
}
