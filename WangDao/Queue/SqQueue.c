#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define MaxSize 10

typedef int ElemType;

typedef struct{
    int front,rear,size; 
    ElemType data[MaxSize];
}SqQueue;

bool InitQueue(SqQueue *Q);
bool EnQueue(SqQueue *Q, ElemType x);
void PrintQueue(SqQueue *Q);
bool DeQueue(SqQueue *Q, ElemType *x);
bool GetHead(SqQueue *Q, ElemType *x);

int main(){
    SqQueue Q;
    InitQueue(&Q);
    int deQueueTest = -1,getHeadTest = -1;
    DeQueue(&Q, &deQueueTest);
    for (int i = 1; i < 12; i++)
    {
        EnQueue(&Q, i);
    }
    PrintQueue(&Q);
    DeQueue(&Q, &deQueueTest);
    printf("DeQueue出队: %d\n", deQueueTest);
    PrintQueue(&Q);
    GetHead(&Q, &getHeadTest);
    printf("GetHead获取队首元素: %d\n", getHeadTest);
    PrintQueue(&Q);

}

bool InitQueue(SqQueue *Q){
    Q->front = Q->rear = Q->size = 0;
    return true;
}

bool EnQueue(SqQueue *Q, ElemType x){
    if(Q->size == MaxSize){
        printf("顺序队列已满！无法插入值：%d\n", x);
        return false;
    }
    Q->data[Q->rear++] = x;
    Q->size++;
    printf("值：%d 已经插入队列-\n", x);
    return true;
}

bool DeQueue(SqQueue *Q, ElemType *x){
    if(Q->size == 0){
        printf("队列为空，无法离队！\n");
        return false;
    }
    *x = Q->data[Q->front++];
    Q->size--;
    return true;
}

void PrintQueue(SqQueue *Q){
    for (int i = Q->front; i < Q->rear; i++)
    {
        printf("%d - ", Q->data[i]);
    }
    printf("\n");
}

bool GetHead(SqQueue *Q, ElemType *x){
    if(Q->size == 0){
        return false;
    }
    *x = Q->data[Q->front];
    return true;
}