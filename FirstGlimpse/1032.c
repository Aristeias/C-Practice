#include<stdio.h>
#include<string.h>

void connectArr(char a[], char b[], int m, int n);

int main(){
    char a[50],b[50];
    gets(a);
    gets(b);
    
    int alen = strlen(a);
    int blen = strlen(b);
    
    connectArr(a, b, alen, blen);

}

void connectArr(char a[], char b[], int m, int n){
    for(int i = 0; i < n; i++){
        a[m + i] = b[i];
    }
    printf("%s", a);
}

