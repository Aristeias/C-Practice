#include<stdio.h>

struct people{
    int index;
    int number;
};

int getNumber(struct people num[],int length, int shout);
void removePeople(struct people num[],int length);

int main(){
    int n;
    scanf("%d", &n);
    struct people num[n];
    for(int i = 0; i < n; i++){
        num[i].number = i + 1;
        num[i].index = i + 1;
    }

    int sumPeople = 0,finalPeople = 0 ,shout = 1;

    while(1){
        sumPeople = 0;
        shout = getNumber(num, n, shout);
        for(int i = 0; i < n; i++){
            if(num[i].number != 0){
                sumPeople++;
                finalPeople = i;
            }
        }

        if(sumPeople == 1){
            break;
        }

        removePeople(num, n);

        // for(int i = 0; i < n; i++){
        //     printf("%d", num[i].number);
        // }
        // printf("\n");

    }

    printf("%d", finalPeople + 1);


}

int getNumber(struct people num[],int length, int shout){
    for(int i = 0; i < length; i++){
        
        if(num[i].number == 0){
            continue;
        }
        if(shout == 4){
            shout = 1;
        }
        num[i].number = shout;
        shout++;
    }
    
    return shout;
}

void removePeople(struct people num[],int length){
    for(int j = 0; j < length; j++){
        if(num[j].number == 3){
            num[j].number = 0;
        }
    }
}
