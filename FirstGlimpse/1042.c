#include<stdio.h>
#include<string.h>

int main(){
    char a[100];
    gets(a);
    for(int i = 0; i < strlen(a); i++){
        if(a[i] == 122){
            printf("%c", 'a');
        }else if(a[i] >= 97 && a[i] <= 122){
            printf("%c", a[i] + 1);
        }else{
            printf("%c", a[i]);
        }
    }
}

