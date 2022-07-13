#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 10

typedef int ElemType;

typedef struct{
    ElemType data[MaxSize];
    int top;
} SqStack;

bool InitStack(SqStack *S);
bool StackEmpty(SqStack *S);
bool Push(SqStack *S, ElemType x);
bool Pop(SqStack *S, ElemType *x);
bool GetTop(SqStack *S, ElemType *x);
void PrintStack(SqStack *S);


int main(){
    SqStack *S;
    InitStack(S);
    for (int i = 1; i < 5; i++)
    {
        Push(S,i);
    }
    
    PrintStack(S);
    printf("\n");
    int topNumber = -1;
    Pop(S, &topNumber);
    printf("Pop: %d", topNumber);
    printf("\n");
    PrintStack(S);
    int getTopNumber = -1;
    GetTop(S, &getTopNumber);
    printf("\n");
    printf("Top: %d", getTopNumber);
    printf("\n");
    PrintStack(S);
}

/**
 * @brief 初始化栈
 * 
 * @param S 栈指针
 * @return true 
 * @return false 
 */
bool InitStack(SqStack *S){
    S->top = -1;
    return true;
}

/**
 * @brief 判空
 * 
 * @param S 栈指针
 * @return true 
 * @return false 
 */
bool StackEmpty(SqStack *S){
    if(S->top == -1){
        return true;
    }else{
        return false;
    }
}

/**
 * @brief 元素入栈
 * 
 * @param S 栈指针
 * @param x 入栈元素值
 * @return true 
 * @return false 
 */
bool Push(SqStack *S, ElemType x){
    //检查 栈 是否存满
    if(S->top == MaxSize - 1){
        return false;
    }
    S->top ++;
    S->data[S->top] = x;
    return true;
}

/**
 * @brief 栈顶元素出栈
 * 
 * @param S 栈指针
 * @param x 出栈元素值
 * @return true 
 * @return false 
 */
bool Pop(SqStack *S, ElemType *x){
    if(S->top == MaxSize - 1){
        return false;
    }
    *x = S->data[S->top];
    S->top = S->top - 1;
    return true;
}

/**
 * @brief 获取栈顶元素值
 * 
 * @param S 栈指针
 * @param x 栈顶元素值
 * @return true 
 * @return false 
 */
bool GetTop(SqStack *S, ElemType *x){
    if(S->top == MaxSize - 1){
        return false;
    }
    *x = S->data[S->top];
    return true;
}

/**
 * @brief 输出栈
 * 
 * @param S 栈指针
 */
void PrintStack(SqStack *S){
    for (int i = 0; i <= S->top; i++)
    {
        printf("%d-", S->data[i]);
    }
}