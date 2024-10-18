#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10 //定义最大长度
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
  for(int i=0;i<list->length;i++){
    printf("%d ",list->data[i]);
  }
  printf("\n");
}


//插入顺序表
int add(SqList * list,int index,ElementType value){ //在index插入元素value
  if(index < 0 || index >= MAX_SIZE + 1){
    printf("插入的位置不符合顺序表，不能插入\n");
    return 0;
  }
  if(list->length>=MAX_SIZE){
    printf("顺序表当前存储的元素已达到最大值，不能插入\n");
    return 0;
  }
  if(value >= list->data[index+1] || value <= list->data[index-1] || value > list->data[index]){
    printf("插入的数字不符合当前位置，请重新选择数字插入\n");
    return 0;
  }
  for (int i = list->length; i >= index; i--){
    list->data[i] = list->data[i-1]; 
  }
  list->data[index] = value;
  list->length++;
  return 1;
}

//删除顺序表某个元素
int del(SqList*list,int index){ //删除index位置的元素value
  if(index < 0 || index > list->length){
  return 0;
  }
  if(list->length<=0){
    printf("顺序表为空，不能删除");
    return 0;
  }
  for(int i = index; i <= list->length; i++){
    list->data[i] = list->data[i+1]; 
  }
  list->length--;
  return 1;
}

//按值查找
int find(SqList *list,ElementType value){
  for(int i = 0; i <= list->length; i++){
    if(list->data[i] == value){
      printf("你要查找的元素 %d 在顺序表第 %d 个位置\n",value,i+1);
      return i+1;}
  }
  printf("未查找到该元素\n");
  return 0;
}

int main(){
  SqList * list1 = InitList();
  //printf("%d",list1->length);
  for(int i=0;i<MAX_SIZE-4;i++){
    list1->data[i] = (i+1)*10;
    list1->length +=1;
  }
  //printf("%d\n",list1->length);
  print_list(list1);
  add(list1,0,2);
  print_list(list1);
  del(list1,2);
  print_list(list1);
  find(list1,10);
  return 0;
}