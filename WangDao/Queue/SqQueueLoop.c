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
    EnQueue(&Q, 666);
    PrintQueue(&Q);
    for (;Q.size!= 0;)
    {
        DeQueue(&Q, &deQueueTest);
        printf("DeQueue出队: %d\n", deQueueTest);
    }
    PrintQueue(&Q);

}

/**
 * @brief 初始化顺序队列
 * 
 * @param Q 队列指针
 * @return true 
 * @return false 
 */
bool InitQueue(SqQueue *Q){
    Q->front = Q->rear = Q->size = 0;
    return true;
}

/**
 * @brief 入队
 * 
 * @param Q 队列指针
 * @param x 值
 * @return true 
 * @return false 
 */
bool EnQueue(SqQueue *Q, ElemType x){
    if(Q->size == MaxSize){
        printf("顺序队列已满！无法插入值：%d\n", x);
        return false;
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxSize;
    Q->size++;
    printf("值：%d 已经插入队列-\n", x);
    return true;
}

/**
 * @brief 离队
 * 
 * @param Q 队列指针
 * @param x 值
 * @return true 
 * @return false 
 */
bool DeQueue(SqQueue *Q, ElemType *x){
    if(Q->size == 0){
        printf("队列为空，无法离队！\n");
        return false;
    }
    *x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;
    Q->size--;
    return true;
}

/**
 * @brief 输出顺序队列
 * 
 * @param Q 队列指针
 */
void PrintQueue(SqQueue *Q){
    if(Q->size == 0){
        printf("循环队列为空！");
        return ;
    }
    if(Q->size == MaxSize){
        for (int i = Q->front; i < MaxSize; i++)
        {
            printf("%d - ", Q->data[i]);
        }
        for (int i = 0; i < Q->rear; i++)
        {
            printf("%d - ", Q->data[i]);
        }
        
        printf("\n");
    }else{
        for (int i = Q->front;(i + MaxSize) % MaxSize != Q->rear;i = (i + 1) % MaxSize)
        {
            printf("%d - ", Q->data[i]);
        }
        printf("\n");
    }
}

/**
 * @brief 获取队列首元素
 * 
 * @param Q 队列指针
 * @param x 首元素地址
 * @return true 
 * @return false 
 */
bool GetHead(SqQueue *Q, ElemType *x){
    if(Q->size == 0){
        return false;
    }
    *x = Q->data[Q->front];
    return true;
}