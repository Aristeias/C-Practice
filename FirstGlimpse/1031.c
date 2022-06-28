#include<stdio.h>
#include<string.h>

void reverseArr(char arr[], int length);

int main(){
    char a[50];
    gets(a);
    
    int len = strlen(a);
    reverseArr(a,len);
}

void reverseArr(char arr[], int length){
    int tempArr[length];
    for(int i = length - 1; i >= 0; i--){
        tempArr[length - i - 1] = arr[i];
    }
    for(int i = 0; i <= length; i++){
        if(tempArr[i] == 32){
            continue;
        }
        printf("%c", tempArr[i]);
    }

}

//没通过，但测试用例过了，网站直接答案错误0，我很生气，因为看不见错误测试用例