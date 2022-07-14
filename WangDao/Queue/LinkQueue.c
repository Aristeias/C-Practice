#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef int ElemType;

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front, *rear;
}LinkQueue;

bool InitQueue(LinkQueue *Q);
bool EnQueue(LinkQueue *Q, ElemType x);
void PrintQueue(LinkQueue *Q);
bool DeQueue(LinkQueue *Q, ElemType *x);
bool GetHead(LinkQueue *Q, ElemType *x);


int main(){
    LinkQueue Q;
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
}

/**
 * @brief 不带头结点的链式队列的初始化
 * 
 * @param Q 头尾指针结构体
 * @return true 
 * @return false 
 */
bool InitQueue(LinkQueue *Q){
    Q->front = NULL;
    Q->rear = NULL;
    return true;
}

/**
 * @brief 不带头结点的链式队列的入队操作
 * 
 * @param Q 头尾指针结构体
 * @param x 值
 * @return true 
 * @return false 
 */
bool EnQueue(LinkQueue *Q, ElemType x){
    LinkNode *newData = (LinkNode*)malloc(sizeof(LinkNode));
    newData->data = x;
    newData->next = NULL;
    if(Q->front == NULL){
        Q->front = newData;
        Q->rear = newData;
    }else{
        Q->rear->next = newData;
        Q->rear = newData;
    }
    return true;
}

/**
 * @brief 不带头结点的链式队列的出队
 * 
 * @param Q 头尾指针结构体
 * @param x 出队值
 * @return true 
 * @return false 
 */
bool DeQueue(LinkQueue *Q, ElemType *x){
    if(Q->front == NULL){
        return false;
    }
    LinkNode *node = Q->front;
    *x = node->data;
    Q->front = node->next;
    if(Q->rear == node){
        Q->rear = NULL;
    }
    free(node);
    return true;
}

/**
 * @brief 不带头结点的链式队列的队首元素获取
 * 
 * @param Q 头尾指针结构体
 * @param x 队首元素
 * @return true 
 * @return false 
 */
bool GetHead(LinkQueue *Q, ElemType *x){
    if(Q->front == NULL){
        return false;
    }
    *x = Q->front->data;
    return true;
}

/**
 * @brief 不带头结点的链式队列的输出
 * 
 * @param Q 头尾指针结构体
 */
void PrintQueue(LinkQueue *Q){
    LinkNode *node = Q->front;
    while (node != NULL)
    {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("\n");
}