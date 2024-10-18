#include <stdio.h>
#define MaxSize 10  //定义最大长度

typedef int ElemType; /*ElemType根据实际情况*/
typedef struct{
    ElemType  data[MaxSize]; //用静态的"数组"存放数据元素
    int length;        //顺序表的当前长度
}SqList;      //顺序表的类型定义

//基本操作一初始化一个顺序表
void InitList(SqList *L){        
    // 不设置初始值，内存中会遗留”脏“数据
    L->length=0;      //顺序表初始长度为0
}   // 使用指针访问结构体成员时，应该使用箭头操作符 ->


int main() {
    SqList L;
    InitList(&L);    //初始化顺序表
    // 尝试“违规”打印整个 data 数组
    for(int i=0;i<MaxSize;i++) {    // 产生“脏数据“
    //for(int i=0; i < L.length;i++) { 
        printf("data[%d] = %d\n", i, L.data[i]);  // 输出每一项数据
    }
    return 0;
}

