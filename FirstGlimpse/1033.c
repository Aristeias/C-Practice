#include<stdio.h>

int findLetter(char arr[]);

int main(){
    char a[100];
    scanf("%s", &a);
    findLetter(a);
}

int findLetter(char arr[]){
    for(int i = 0; i < 100; i++){
        if(arr[i]=='a' || arr[i]=='e' || arr[i]=='i' || arr[i]=='o' || arr[i]=='u'){
            printf("%c", arr[i]);
        }
    }
}
