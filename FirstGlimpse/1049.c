#include<stdio.h>

struct calender{
    int year;
    int month;
    int day;
};

int main(){
    struct calender test;
    scanf("%d", &test.year);
    scanf("%d", &test.month);
    scanf("%d", &test.day);
    int dayInYear = 0;
    int dayPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(test.year % 400 == 0 || (test.year % 4 == 0 && test.year % 100 != 0)){
        dayPerMonth[1] ++;
    }
    if(test.month == 1){
        dayInYear += test.day;
    }else{
        for(int i = 0; i < test.month - 1; i++){
            dayInYear += dayPerMonth[i];
        }
        dayInYear += test.day;
    }
    printf("%d", dayInYear);
}

