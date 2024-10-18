#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20 //定义最大长度
typedef int ElementType;

typedef struct {
  ElementType data[MAX_SIZE]; //用静态数组表示顺序表
  int length; //定义数组长度 
} SqList; //结构体名字

//初始化顺序表
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
  for(int i=0;i < list->length;i++){
    printf("%d ",list->data[i]);
    //printf("%d 内存：%d\n",list->data[i],&list->data[i]);
  }
  printf("\n");
}

//删除表中相同的元素，只留下一个
int del_same(SqList* list){
  if (list->length == 0){
    return 0;
  }
  int i,j;  //i是记录不同元素的个数，j是计数器用于遍历顺序表
  for(i = 0, j = 1; j < list->length; j++){  //遍历顺序表
    if(list->data[i] != list->data[j]){   //找到下一个与上一个值不同的元素，把i+1后，将那个不同的元素覆盖前面的元素
      list->data[++i] = list->data[j];  //把元素前移
    }
  }
  list->length = i+1;
  print_list(list);
  return 1;
}

int main(){
  SqList *list1 = InitList();
  int arr1[] = {1,2,2,2,2,3,3,3,4,4,5};
  for(int i =0; i < sizeof(arr1) / sizeof(arr1[0]); i++){
    list1->data[i] = arr1[i];
    list1->length++;
  }
  print_list(list1);
  del_same(list1);
  //print_list(list1);
  return 0;
}