#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode, *LiStack;

bool InitStack(LiStack *S);
bool StackEmpty(LiStack S);
bool Push(LiStack* S, ElemType x);
bool Pop(LiStack *S, ElemType *x);
bool GetTop(LiStack *S, ElemType *x);
void PrintStack(LiStack *S);

int main(){
    LiStack S;
    InitStack(&S);
    for (int i = 1; i < 5; i++)
    {
        Push(&S,i);
    }
    PrintStack(&S);
    int popTest = -1;
    Pop(&S, &popTest);
    printf("移除栈顶元素：%d\n", popTest);
    PrintStack(&S);

    int getTopTest = -1;
    GetTop(&S, &getTopTest);
    printf("获取栈顶元素：%d\n", getTopTest);
    PrintStack(&S);
}

/**
 * @brief 初始化链栈
 * 
 * @param S 链栈头指针
 * @return true 
 * @return false 
 */
bool InitStack(LiStack *S){
    S = NULL;
    printf("InitStack\n");
    return true;
}

/**
 * @brief 链栈判空
 * 
 * @param S 链栈头指针
 * @return true 
 * @return false 
 */
bool StackEmpty(LiStack S){
    if(S == NULL){
        return true;
    }
    return false;
}

/**
 * @brief 向链栈插入数据
 * 
 * @param S 链栈头指针
 * @param x 数据
 * @return true 
 * @return false 
 */
bool Push(LiStack* S, ElemType x){
    LinkNode *node = (LinkNode*)malloc(sizeof(LinkNode));
    node->data = x;
    node->next = (*S);
    (*S) = node;
    return true;
}

/**
 * @brief 弹出栈顶元素
 * 
 * @param S 链栈头指针
 * @param x 被弹出的栈顶元素
 * @return true 
 * @return false 
 */
bool Pop(LiStack *S, ElemType *x){
    if(S == NULL){
        return false;
    }
    *x = (*S)->data;
    (*S) = (*S)->next;
    return true;
}

/**
 * @brief 获取栈顶元素
 * 
 * @param S 链栈头指针
 * @param x 栈顶元素
 * @return true 
 * @return false 
 */
bool GetTop(LiStack *S, ElemType *x){
    if((*S) == NULL){
        return false;
    }
    *x = (*S)->data;
    return true;
}

/**
 * @brief 输出链栈
 * 
 * @param S 链栈头指针
 */
void PrintStack(LiStack *S){
    LinkNode *node = (*S);
    while ((node->next != NULL))
    {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("\n");
}