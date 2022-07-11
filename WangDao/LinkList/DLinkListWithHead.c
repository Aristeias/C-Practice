#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef int ElemType;

typedef struct DNode{
    ElemType data;
    struct DNode *prior,*next;
}DNode, *DLinkList;

bool InitDLinkList(DLinkList *L);
bool InsertNextNode(DNode *node, DNode *new);
bool InsertPriorNode(DNode *node, DNode *new);
bool DeleteNextNode(DNode *node);
bool DestroyList(DLinkList L);
DNode* GetElem(DLinkList L, int i);
DNode* LocateElem(DLinkList L, ElemType element);
bool PrintList(DLinkList L);
int Length(DLinkList L);


int main(){
    DLinkList L;
    InitDLinkList(&L);

    int x;
    scanf("%d", &x);

    
    DNode *node = L;
    while(x != 1111){
        DNode* number = (DNode*)malloc(sizeof(DNode));
        number->data = x;
        number->next = NULL;
        number->prior = NULL;
        InsertNextNode(node, number);
        node = node->next;
        scanf("%d", &x);      
    }

    PrintList(L);
    printf("Length: %d\n", Length(L));

    DNode* insertTestNode = (DNode*)malloc(sizeof(DNode));
    insertTestNode->data = 100;
    InsertPriorNode(GetElem(L, 2), insertTestNode);
    PrintList(L);

    DNode* insertTestNode2 = (DNode*)malloc(sizeof(DNode));
    insertTestNode2->data = 120;
    InsertPriorNode(LocateElem(L, 3), insertTestNode2);
    PrintList(L);
    // DeleteNextNode(LocateElem(L, 3));
    // PrintList(L);

    
}

/**
 * @brief 初始化双链表
 * 
 * @param L 双链表头结点
 * @return true 
 * @return false 
 */
bool InitDLinkList(DLinkList *L){
    (*L) = (DNode*)malloc(sizeof(DNode));
    //内存异常
    if(L == NULL){
        return false;
    }
    (*L)->prior = NULL;
    (*L)->next = NULL;
    return true;
}

/**
 * @brief 指定结点的后插操作
 * 
 * @param node 指定结点
 * @param new 新结点
 * @return true 
 * @return false 
 */
bool InsertNextNode(DNode *node, DNode *new){
    if(node == NULL || new == NULL){
        return false;
    }
    new->next = node->next;
    //判断node后是否存在结点
    if(node->next != NULL){
        node->next->prior = new;
    }
    new->prior = node;
    node->next = new;
    return true;
}

/**
 * @brief 指定结点的前插操作
 * 
 * @param node 指定结点
 * @param new 新结点
 * @return true 
 * @return false 
 */
bool InsertPriorNode(DNode *node, DNode *new){
    if(node == NULL || new == NULL){
        return false;
    }
    if(node->prior == NULL){
        return false;
    }
    new->prior = node->prior;
    node->prior->next = new;
    node->prior = new;
    new->next = node;
    return true;
}

/**
 * @brief 删除指定结点的后一个结点
 * 
 * @param node 指定结点
 * @return true 
 * @return false 
 */
bool DeleteNextNode(DNode *node){
    if(node == NULL){
        return false;
    }
    DNode *next = node->next;
    if(next == NULL){
        return false;
    }
    node->next = next->next;
    if(next->next != NULL){
        next->next->prior = node;
    }
    free(next);
    return true;
}

/**
 * @brief 释放双链表
 * 
 * @param L 双链表头结点
 * @return true 
 * @return false 
 */
bool DestroyList(DLinkList L){
    while (L->next != NULL)
    {
        DeleteNextNode(L);
    }
    free(L);
    L=NULL;
    return true;
}

/**
 * @brief 按位查找
 * 
 * @param L 头结点指针
 * @param i 位序
 * @return DNode* 
 */
DNode* GetElem(DLinkList L, int i){
    DNode *node = L;
    int number = 0;
    while (node != NULL)
    {
        if(number == i){
            return node;
        }
        node = node->next;
        number++;
    }
}

/**
 * @brief 按值查找
 * 
 * @param L 双链表头结点
 * @param element 值
 * @return DNode* 
 */
DNode* LocateElem(DLinkList L, ElemType element){
    DNode *node = L;
    while (node->next != NULL)
    {
        node = node->next;
        if(node->data == element){
            return node;
        }
    }
}

/**
 * @brief 打印双链表
 * 
 * @param L 双链表头指针
 * @return true 
 * @return false 
 */
bool PrintList(DLinkList L){
    DNode *node = L;
    while (node->next != NULL)
    {
        node = node->next;
        printf("%d<->", node->data);
    }
    printf("\n");
}

/**
 * @brief 双链表长度
 * 
 * @param L 链表头结点
 * @return int 
 */
int Length(DLinkList L){
    int len = 0;
    DNode *p = L->next;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}