#include<stdio.h>

int getAllChar(char arr[], int num[]);

int main(){
    char a[100];
    int num[4] ={0,0,0,0};
    gets(a);
    //scanf("%d", &a);
    getAllChar(a,num);
    for(int i = 0; i < 4;i++){
        printf("%d\n", num[i]);
    }
}

int getAllChar(char arr[], int num[]){
    for(int i = 0; i < 100; i++){
        if(arr[i] == 32){
            num[1]++;
        }else if(arr[i] >= 48 && arr[i] <= 57){
            num[2]++;
        }else if((arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122)){
            num[0]++;
        }else{
            num[3]++;
        }
        //其他字符删去空字符
        if(arr[i] == 0){
            num[3]--;
            break;
        }
    }
}