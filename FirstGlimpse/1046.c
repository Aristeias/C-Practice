#include<stdio.h>

void operation(int arr[], int m, int len);

int main(){
    int n;
    scanf("%d", &n);
    int arr[n],m;
    for(int i = 0; i < n; i++){
        scanf("%d ", &arr[i]);
    }
    scanf("%d", &m);
    int len = sizeof(arr)/sizeof(arr[0]);
    operation(arr,m,len);
}

void operation(int arr[], int m, int len){
    int tempArr[len];
    for(int i = 0; i < len; i++){
        tempArr[i] = arr[i];
    }

    for(int i = 0; i < len; i++){
        if(i + m >= len){
            arr[(i+m) % len] = tempArr[i];
        }else{
            arr[i + m] = tempArr[i];
        }
    }

    for(int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
}
