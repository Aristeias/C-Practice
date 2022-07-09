#include<stdio.h>
#include<stdlib.h>

#define InitSize 5

typedef struct
{
    int *data;
    int MaxSize,length;
} SeqList;

_Bool InitList(SeqList *L);
_Bool IncreaseSize(SeqList *L, int len);
_Bool ListInsert(SeqList *L, int i, int element);
_Bool ListDelete(SeqList *L, int i, int *element);
int GetElem(SeqList *L, int i);
int LocateElem(SeqList *L, int element);

int main(){
    SeqList *L;
    InitList (L);
    //插入测试
    for (int i = 1; i <= 20; i++)
    {
        ListInsert(L,i,i);
    }
    ListInsert(L, 10, 666);
    
    //删除测试
    int deleteElement = -1,*e = &deleteElement;
    if(ListDelete(L, 10, e)){
        printf("删除数据为 %d \n", *e);
    }else{
        printf("删除失败,位序异常");
    }
    //输出链表
    for (int i = 0; i < L->length; i++)
    {
        printf("data[%d]=%d\n", i, L->data[i]);
    }
    printf("Length = %d\n",L->length);
    //查找测试
    ListInsert(L, 10, 100);
    ListInsert(L, 21, 666);
    printf("按位查找：%d\n", GetElem(L, 10));
    printf("按值查找：%d\n", LocateElem(L, 666));
}

/**
 * @brief 
 * 顺序表的动态初始化
 * @param L 链表指针
 * @return _Bool 
 */

_Bool InitList(SeqList *L){
    //开辟连续空间，用以存放一个InitSize大小的链表
    L->data = (int*) malloc(sizeof(int) * InitSize);
    L->length = 0;
    L->MaxSize = InitSize;
}

/**
 * @brief 
 * 动态增加链表长度（动态链表的体现）
 * @param L 链表指针
 * @param len 需要增加的长度（可以写一个固定的数）
 * @return _Bool 
 */

_Bool IncreaseSize(SeqList *L, int len){
    int *p = L->data;
    //申请链表增长后的内存空间
    L->data = (int*) malloc(sizeof(int) * (L->MaxSize + len));
    //复制数据到新链表中
    for (int i = 0; i < L->length; i++)
    {
        L->data[i] = p[i];
    }
    //将链表最大长度增加len
    L->MaxSize += len;
    //释放原内存空间
    free(p);
} 

/**
 * @brief 
 * 静态顺序表的插入操作
 * @param L 链表指针
 * @param i 插入位序
 * @param element 插入数据
 * @return _Bool 
 */
_Bool ListInsert(SeqList *L, int i, int element){
    //位序异常
    if( i < 1 || i > L->length + 1){
        return 0;
    }
    //空间异常处理
    while (L->length >= L->MaxSize)
    {
        IncreaseSize(L, 5);
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
_Bool ListDelete(SeqList *L, int i, int *element){
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
int GetElem(SeqList *L, int i){
    return L->data[i - 1];
}

/**
 * @brief 
 * 静态顺序表 按值查找
 * @param L 链表指针
 * @param element 指定数值
 * @return int 位序
 */
int LocateElem(SeqList *L, int element){
    for (int i = 0; i < L->length; i++)
    {
        if(L->data[i] == element)
        {
            return i + 1;
        }
    }
    return -1;
}