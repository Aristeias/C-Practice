#include<stdio.h>

struct score{
    char num[10];
    char name[20];
    int subject_1;
    int subject_2;
    int subject_3;
};

int input(struct score *p);
void print(struct score *p, int n);


int main(){
    struct score arr[100];
    struct score *p;
    p = &arr[0];
    int n = input(p);
    print(p,n);

}

int input(struct score *p){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s %s %d %d %d", &p[i].num, &p[i].name, &p[i].subject_1, &p[i].subject_2, &p[i].subject_3);
    }
    return n;
}

void print(struct score *p, int n){

    for(int i = 0; i < n; i++){
        printf("%s,%s,%d,%d,%d\n",p[i].num, p[i].name, p[i].subject_1, p[i].subject_2, p[i].subject_3);
    }
}

