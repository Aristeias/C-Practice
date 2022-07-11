#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
    //*LinkList 表示的是 
    //
}LNode, *LinkList;

_Bool InitList(LinkList L);
_Bool ListInsert(LinkList* L, int i, int element);
_Bool InsertNextNode(LNode *p, int element);
_Bool InsertPriorNode(LNode *p, int element);
_Bool ListDelete(LinkList L, int i, int *e);
_Bool DeleteNode(LNode *p);
LNode* GetElem(LinkList L, int i);
LNode* LocateElem(LinkList L, int element);
int Length(LinkList L);
_Bool PrintList(LinkList L);

int main(){
    LinkList L;
    InitList(L);
    int x, i = 1;
    scanf("%d", &x);
    while(x != 1111){
        ListInsert(&L, i, x);
        i++;
        scanf("%d", &x);
    }
    PrintList(L);
    printf("Length: %d\n", Length(L));

    DeleteNode(GetElem(L, 3));
    PrintList(L);
    printf("Length: %d\n", Length(L));

    InsertNextNode(GetElem(L, 2),9);
    PrintList(L);
    printf("Length: %d\n", Length(L));

    DeleteNode(LocateElem(L, 9));
    PrintList(L);
    printf("Length: %d\n", Length(L));

    InsertPriorNode(LocateElem(L, 7), 2);
    PrintList(L);
    printf("Length: %d\n", Length(L));

    int deleteElement = -1;
    ListDelete(L, 5, &deleteElement);
    PrintList(L);
    printf("被删除数据为：%d\n", deleteElement);
    printf("Length: %d\n", Length(L));

}

/**
 * @brief 
 * 初始化单链表 
 * @param L 单链表指针
 * @return _Bool 
 */
_Bool InitList(LinkList L){
    L = NULL;
    return true;
}

/**
 * @brief 
 * 单链表按位插入
 * @param L 单链表指针
 * @param i 位序
 * @param element 插入数据 
 * @return _Bool 
 */
_Bool ListInsert(LinkList* L, int i, int element){
    //位序异常
    if(i < 1){
        return false;
    }
    //在第一位前插入数据
    if(i == 1){
        //不理解，L已经指向newData了，在此输出正常，但出了此函数就输出地址值
        LNode *newData = (LNode *)malloc(sizeof(LNode));
        newData->data = element;
        newData->next = NULL;
        (*L) = newData;
        //L->data = element;
        return true;
    }
    //寻找位序前一位元素
    LNode *p;
    int j = 1;
    p = (*L);
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    //以下部分可修改为
    //return InsertNextNode(p, element);
    //位序异常：超出长度
    if(p == NULL){
        return false;
    }
    //新数据插入单链表
    LNode *newData = (LNode *)malloc(sizeof(LNode));
    newData->data = element;
    newData->next = p->next;
    p->next = newData;
    return true;

}

/**
 * @brief 
 * 单链表指定节点的后插
 * @param p 指定节点
 * @param element 指定数据
 * @return _Bool 
 */
_Bool InsertNextNode(LNode *p, int element){
    if(p == NULL){
        return false;
    }
    LNode *newData = (LNode *)malloc(sizeof(LNode));
    //内存错误
    if(newData == NULL){
        return false;
    }
    newData->data = element;
    newData->next = p->next;
    p->next = newData;
    return true;
}

/**
 * @brief 
 * 单链表指定节点的前插
 * @param p 指定节点
 * @param element 指定数据
 * @return _Bool 
 */
_Bool InsertPriorNode(LNode *p, int element){
    if(p == NULL){
        return false;
    }
    LNode *newData = (LNode *)malloc(sizeof(LNode));
    //内存错误
    if(newData == NULL){
        return false;
    }
    newData->next = p->next;
    p->next = newData;
    //交换两个节点的数据来实现前插
    newData->data = p->data;
    p->data = element;
    return true;
}


/**
 * @brief 
 * 单链表按位删除
 * @param L 链表头结点
 * @param i 位序
 * @param e 被删除数据
 * @return _Bool 
 */
_Bool ListDelete(LinkList L, int i, int *e){
    //位序异常
    if(i < 1){
        return false;
    }
    //寻找位序前一位元素
    LNode *p;
    int j = 1;
    p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    //位序异常：超出长度
    if(p == NULL){
        return true;
    }
    LNode *q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

/**
 * @brief 
 * 单链表删除指定结点
 * @param p 指定结点
 * @return _Bool 
 */
_Bool DeleteNode(LNode *p){
    if(p == NULL){
        return false;
    }
    //将后一结点的数据转移至 被删除的结点上 实现指定结点的删除
    //当删除的结点为最后的结点时，会报错
    //↑ 为什么不直接释放：前一结点的指针指向了被删除的结点，直接释放会造成错误
    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(q);
    return true;
}

/**
 * @brief 
 * 单链表按位查找
 * @param L 链表头结点
 * @param i 位序
 * @return LNode* 
 */
LNode* GetElem(LinkList L, int i){
    if(i < 0){
        return NULL;
    }
    //寻找位序元素
    LNode *p;
    int j = 1;
    p = L;
    while (p != NULL && j < i )
    {
        p = p->next;
        j++;
    }
    return p;
}

/**
 * @brief 
 * 单链表按值查找
 * @param L 链表头结点
 * @param element 值
 * @return LNode* 
 */
LNode* LocateElem(LinkList L, int element){
    LNode *p = L->next;
    while (p != NULL && p->data != element)
    {
        p = p->next;
    }
    return p;
}


/**
 * @brief 
 * 单链表长度
 * @param L 链表头结点
 * @return int 
 */
int Length(LinkList L){
    int len = 0;
    LNode *p = L;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}


/**
 * @brief 
 * 打印单链表
 * @param L 链表头结点
 * @return _Bool 
 */
_Bool PrintList(LinkList L){
    LNode *p = L;

    while(p != NULL){
        printf("%d->", p->data);
        p = p->next;
    }
    printf("\n");
    return true;
}