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
    int sum_1 = 0, sum_2 = 0, sum_3 = 0;
    int index = 0;
    int max = 0;

    for(int i = 0; i < n; i++){
        int sum = p[i].subject_1 + p[i].subject_2 + p[i].subject_3;
        sum_1 += p[i].subject_1;
        sum_2 += p[i].subject_2;
        sum_3 += p[i].subject_3;
        if(sum > max){
            max = sum;
            index = i;
        }
    }
    printf("%d %d %d\n", sum_1 / n, sum_2 / n, sum_3 / n);
    printf("%s %s %d %d %d", p[index].num, p[index].name, p[index].subject_1, p[index].subject_2, p[index].subject_3);
}

