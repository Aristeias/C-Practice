#include<stdio.h>
#include<math.h>

int ctof(int c);

int main(){
    int c = -100;
    while(c<=150){
        int f = ctof(c);
        printf("c=%d->f=%d\n", c, f);
        c += 5;
    }
    
}

int ctof(int c){
    return 32+c/5*9;
}