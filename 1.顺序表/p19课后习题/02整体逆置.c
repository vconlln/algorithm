#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10 //定义最大长度
typedef int ElementType;

typedef struct {
  ElementType data[MAX_SIZE]; //用静态数组表示顺序表
  int length; //定义数组长度 
} SqList; //结构体名字

SqList * InitList(){
  //你的指针是什么类型的，你申请的malloc空间就要返回什么类型的
  //malloc返回的是void* 
  //该函数返回一个指针指向已分配大小的内存如果请求失败则返回null
  SqList *list = (SqList *)malloc(sizeof(SqList)); 
  //此处返回结构体类型指针
  list->length = 0;
  return list;
}

//打印顺序表
void print_list(SqList *list){
  for(int i=0;i<list->length;i++){
    printf("%d ",list->data[i]);
    //printf("%d 内存：%d\n",list->data[i],&list->data[i]);
  }
  printf("\n");
}

//整体逆置顺序表
void reverse(SqList * list){
  ElementType temp;   // 临时变量，用于存储顺序表里面的值
  for(int i = 0; i < (list->length/2) ;i++){  //只需遍历一半元素即可
    temp = list->data[i];
    list->data[i] = list->data[list->length - 1 - i];
    list->data[list->length - 1 - i] = temp;
  }
  printf("逆置后的顺序表为:\n");
  print_list(list);
}

int main(){
  SqList *list1 = InitList();
  //printf("%d",list1->length);
  for(int i=0;i<MAX_SIZE-4;i++){
    list1->data[i] = (i+1);
    list1->length +=1;
  }
  //printf("%d\n",list1->length);
  print_list(list1);
  reverse(list1);
  //print_list(list1);
  return 0;
}