#include<stdio.h>

void getInput(int a[]);
void operation(int a[]);
void output(int a[]);
void exchange(int a[], int index1, int index2);

int main(){
    int a[10];
    getInput(a);
    operation(a);
    output(a);
}

void getInput(int a[]){
    for(int i = 0; i < 10; i++){
            scanf("%d", &a[i]);
    }
}

void operation(int a[]){
    int min = a[0],max = a[9],mini = 0,maxi = 0;
    for(int i = 0; i < 10; i++){
        if(a[i] < min){
            mini = i;
            min = a[i];
        }
        if(a[i] > max){
            maxi = i;
            max = a[i];
        }
    }
    if(maxi == 0){
        exchange(a,0,9);            
        exchange(a,0,mini);
    }else if(mini == 9){
        exchange(a,0,9); 
        exchange(a,9,maxi); 
    }else{     
        exchange(a,0,mini);
        exchange(a,9,maxi); 
    }
}

void output(int a[]){
    for(int i = 0; i < 10; i++){
        printf("%d ", a[i]);
    }
}

void exchange(int a[], int index1, int index2){
    int temp = a[index1];
    a[index1] = a[index2];
    a[index2] = temp;   
}
