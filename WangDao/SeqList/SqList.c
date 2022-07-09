#include<stdio.h>

#define MaxSize 10

typedef struct
{
    int data[MaxSize];
    int length;
} SqList;

_Bool InitList(SqList *L);
_Bool ListInsert(SqList *L, int i, int element);
_Bool ListDelete(SqList *L, int i, int *element);
int GetElem(SqList *L, int i);
int LocateElem(SqList *L, int element);

int main(){
    SqList *L;
    InitList(L);
    //插入测试
    for (int i = 1; i <= 5; i++)
    {
        ListInsert(L,i,i);
    }
    ListInsert(L,7,3);
    
    //删除测试
    int deleteElement = -1,*e = &deleteElement;
    if(ListDelete(L, 3, e)){
        printf("删除位序为3的元素,数据为 %d \n", *e);
    }else{
        printf("删除失败,位序异常");
    }

    //输出链表
    for (int i = 0; i < L->length; i++)
    {
        printf("data[%d]=%d\n", i, L->data[i]);
    }
    printf("Length = %d",L->length);
    
}

/**
 * @brief 
 * 静态初始化顺序表
 * @param L 链表指针
 * @return _Bool
 */
_Bool InitList(SqList *L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L->data[i] = 0;
    }
    L->length = 0;  
    return 1;  
}

/**
 * @brief 
 * 静态顺序表的插入操作
 * @param L 链表指针
 * @param i 插入位序
 * @param element 插入数据
 * @return _Bool 
 */
_Bool ListInsert(SqList *L, int i, int element){
    //位序异常
    if( i < 1 || i > L->length + 1){
        return 0;
    }
    //空间异常
    if(L->length >= MaxSize){
        return 0;
    }
    //数据后移
    for (int j = L->length; j >= i; j--)
    {
        L->data[j] = L->data[j - 1];
    }
    //插入数据
    L->data[i - 1] = element;
    L->length++;
    return 1;
}

/**
 * @brief 
 * 静态顺序表的删除操作
 * @param L 链表指针
 * @param i 删除位序
 * @param element 所删除的数据
 * @return _Bool 
 */
_Bool ListDelete(SqList *L, int i, int *element){
    //位序异常
    if( i < 1 || i > L->length + 1){
        return 0;
    }
    //获取删除数据
    *element = L->data[i - 1];
    //数据前移
    for (int j = i; j < L->length; j++)
    {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return 1;
}

/**
 * @brief 
 * 静态顺序表 按位查找
 * @param L 链表指针
 * @param i 指定位序
 * @return int 指定位序的值
 */
int GetElem(SqList *L, int i){
    return L->data[i - 1];
}

/**
 * @brief 
 * 静态顺序表 按值查找
 * @param L 链表指针
 * @param element 指定数值
 * @return int 位序
 */
int LocateElem(SqList *L, int element){
    for (int i = 0; i < L->length; i++)
    {
        if(L->data[i] == element)
        {
            return i + 1;
        }
    }
    return -1;
}