#include <stdio.h>
#define MaxSize 10  //定义最大长度

typedef struct{
    int data[MaxSize]; //用静态的"数组"存放数据元素
    int length;        //顺序表的当前长度
}SqList;      //顺序表的类型定义

//基本操作一初始化一个顺序表
void InitList(SqList *L){
    for(int i=0;i< MaxSize;i++){
        L->data[i]=0;    //将所有数据元素设置为默认初始值
    }
    L->length = sizeof(L->data)/sizeof(L->data[0]);      //顺序表初始长度为0
}   // 使用指针访问结构体成员时，应该使用箭头操作符 ->

/*
c++
void InitList(SqList L){
    for(int i=0;i<MaxSize;i++)
        L.data[i]=0;   
    L.length=0;     
}
.......
InitList(L); 
*/

int main() {
    SqList L;
    InitList(&L);    //初始化顺序表
    //...未完待续，后续操作
    printf("Max size: %d\n", MaxSize);
    printf("L的长度为%d\n",L.length);
    for(int i=0; i < L.length; i++) {
        printf("data[%d] = %d\n", i, L.data[i]);  // 输出每一项数据
    }
    return 0;
}

/*
在GCC编译器上：出现该错误的主要原因是：在C语言里没有C++所谓的 “按引用传递” ，例如C++可以写这样一个函数：
void func(int &a)
{
//函数功能
}

在C语言无法这样使用，所以需要改为地址引用：
void func(int *a)
{
//函数功能
}

具体调用该函数时候就修改为：
int num=10;
func(&num);

*/