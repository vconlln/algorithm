#include<stdio.h>
#include<stdlib.h>
#define InitSize 10

typedef struct{
    int *data;  //  动态分配地址的指针
    int MaxSize; // 顺序表的最大容量
    int length; // 顺序表的当前长度
}SeqList;

// 初始化顺序表
void InitList(SeqList *L){
    L->data = (int *)malloc(sizeof(int) * InitSize);
    L->length = 0;
    L->MaxSize = InitSize;
}

void IncreaseList(SeqList *L, int len){
    int *p = L->data;
    L->data = (int *)malloc(sizeof(int) * (L->MaxSize + len));
    for(int i=0; i < L->length; i++){
        L->data[i] = p[i];
    }
    L->MaxSize += len;
    free(p);
}

int main(){
    SeqList L;
    InitList(&L); // 初始化顺序表
    IncreaseList(&L,5);
    return 0;
}







/*
#include<stdio.h>
#include<stdlib.h>
#define InitSize 10 // 顺序表的初始长度

typedef struct {
    int *data; // 动态分配数组的指针
    int MaxSize; // 线性表的最大容量
    int length; // 线性表的当前长度
} SqList;

void InitList(SqList *L) {
    L->data = (int *)malloc(sizeof(int) * InitSize);    // 为顺序表申请空间
    if (L->data) {
        printf("Success: 申请空间成功!\n");
        L->length = 0;          // 初始时，顺序表为空
        L->MaxSize = InitSize;  // 初始时，顺序表的最大容量为InitSize
    } else {
        printf("Error: 申请空间失败!\n");
        exit(0);
    }
}

void IncreaseSize(SqList *L, int len) {
    int *p = L->data;
    L->data = (int *)malloc(sizeof(int) * (L->MaxSize + len));  // 申请新空间
    for (int i = 0; i < len; i++){
        L->data[i] = p[i];  // 将原来的数据复制到新申请的空间中
    }
    L->MaxSize = L->MaxSize + len;
    free(p);     // 释放原来的空间
}

int main() {
    SqList L;   //声明一个顺序表
    InitList(&L);   // 初始化顺序表
    // 往顺序表中随机添加几个元素
    IncreaseSize(&L,5);
    return 0;

}
*/